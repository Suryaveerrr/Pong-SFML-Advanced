#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Boundary.h"

namespace Gameplay
{
    class GamePlayManager
    {
    private:
        Ball *ball;
        Paddle *player1;
        Paddle *player2;
        Boundary *boundary;

        sf::Font font;
        sf::Text player1ScoreText;
        sf::Text player2ScoreText;
        sf::Text countdownText;

        int player1Score = 0;
        int player2Score = 0;

        float screen_width;
        float screen_height;

        bool isCountdownActive;
        float countdownTime;
        sf::Clock countdownClock;

    public:
        GamePlayManager();
        void update(float deltaTime); // <--- CHANGED
        void initialize();
        void render(sf::RenderWindow *game_window);
        void resetBall();
    };
}
