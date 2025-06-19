#include "GamePlayManager.h"
#include <SFML/Window/Keyboard.hpp>
#include <stdexcept>

namespace Gameplay
{

    GamePlayManager::GamePlayManager()
    {
        // Constructor left empty, initialization done in initialize()
    }

    void GamePlayManager::initialize()
    {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        screen_width = static_cast<float>(desktop.width);
        screen_height = static_cast<float>(desktop.height);
        float paddleY = screen_height / 2.0f - 70.0f;

        boundary = new Boundary(screen_width, screen_height);
        ball = new Ball(screen_width, screen_height);
        player1 = new Paddle(50.0f, paddleY);
        player2 = new Paddle(screen_width - 70.0f, paddleY);

        if (!font.loadFromFile("C:\\Users\\Surya\\OneDrive\\Desktop\\Pong-SFML-main\\Assets\\Fonts\\AmberyGardenRegular-PKjGd.ttf"))
            throw std::runtime_error("Failed to load font!");

        player1ScoreText.setFont(font);
        player1ScoreText.setCharacterSize(48);
        player1ScoreText.setFillColor(sf::Color::White);
        player1ScoreText.setStyle(sf::Text::Bold);
        player1ScoreText.setPosition(screen_width / 2 - 100, 20);

        player2ScoreText.setFont(font);
        player2ScoreText.setCharacterSize(48);
        player2ScoreText.setFillColor(sf::Color::White);
        player2ScoreText.setStyle(sf::Text::Bold);
        player2ScoreText.setPosition(screen_width / 2 + 50, 20);

        countdownText.setFont(font);
        countdownText.setCharacterSize(150);
        countdownText.setFillColor(sf::Color::White);
        countdownText.setStyle(sf::Text::Bold);
        countdownText.setPosition(screen_width / 2 - 50, screen_height / 4 - 50);

        isCountdownActive = false;
        countdownTime = 3.0f;
    }

    void GamePlayManager::resetBall()
    {
        delete ball;
        ball = new Ball(screen_width, screen_height);

        isCountdownActive = true;
        countdownClock.restart();
        boundary->setCenterLineVisible(false);
    }

    void GamePlayManager::update(float deltaTime)
    {
        if (isCountdownActive)
        {
            float elapsed = countdownClock.getElapsedTime().asSeconds();
            if (elapsed >= countdownTime)
            {
                isCountdownActive = false;
                boundary->setCenterLineVisible(true);
            }
            else
            {
                return;
            }
        }

        boundary->update();
        ball->update(deltaTime);

        bool p1_up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool p1_down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        player1->update(p1_up, p1_down);

        bool p2_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool p2_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        player2->update(p2_up, p2_down);

        ball->checkPaddleCollision(player1->getShape());
        ball->checkPaddleCollision(player2->getShape());

        sf::Vector2f ballPos = ball->getSprite().getPosition();
        if (ballPos.x < 0)
        {
            player2Score++;
            resetBall();
        }
        else if (ballPos.x > screen_width)
        {
            player1Score++;
            resetBall();
        }
    }

    void GamePlayManager::render(sf::RenderWindow *game_window)
    {
        boundary->render(game_window);
        ball->render(game_window);
        player1->render(game_window);
        player2->render(game_window);

        player1ScoreText.setString((player1Score < 10 ? "0" : "") + std::to_string(player1Score));
        player2ScoreText.setString((player2Score < 10 ? "0" : "") + std::to_string(player2Score));

        game_window->draw(player1ScoreText);
        game_window->draw(player2ScoreText);

        if (isCountdownActive)
        {
            int countdownValue = static_cast<int>(countdownTime - countdownClock.getElapsedTime().asSeconds()) + 1;
            countdownText.setString(std::to_string(countdownValue));
            game_window->draw(countdownText);
        }
    }
}
