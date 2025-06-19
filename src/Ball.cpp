#include "Ball.h"
#include "SoundManager.h"
#include <cmath>

namespace Gameplay
{
    Ball::Ball(float screenWidth, float screenHeight)
    {
        screen_width = screenWidth;
        screen_height = screenHeight;
        loadTexture();
        initializeVariables();
    }

    void Ball::loadTexture()
    {
        if (!Pong_ball_texture.loadFromFile(texture_path))
        {
            throw std::runtime_error("Failed to load ball texture!");
        }
    }

    void Ball::initializeVariables()
    {
        pong_ball_sprite.setTexture(Pong_ball_texture);
        pong_ball_sprite.setScale(scale_x, scale_y);

        float start_x = screen_width / 2.0f;
        float start_y = screen_height / 2.0f;

        pong_ball_sprite.setPosition(start_x, start_y);
    }

    void Ball::update(float deltaTime)
    {
        pong_ball_sprite.move(velocity * deltaTime);

        Vector2f pos = pong_ball_sprite.getPosition();
        FloatRect bounds = pong_ball_sprite.getGlobalBounds();

        if (pos.y <= 0)
            velocity.y = std::abs(velocity.y);
        if (pos.y + bounds.height >= screen_height)
            velocity.y = -std::abs(velocity.y);
    }

    void Ball::render(RenderWindow *game_window)
    {
        game_window->draw(pong_ball_sprite);
    }

    void Ball::checkPaddleCollision(const RectangleShape &paddleShape)
    {
        if (pong_ball_sprite.getGlobalBounds().intersects(paddleShape.getGlobalBounds()))
        {
            velocity.x = -velocity.x;
            Sound::SoundManager::PlaySoundEffect(Sound::BALL_BOUNCE);
        }
    }

    const Sprite &Ball::getSprite() const
    {
        return pong_ball_sprite;
    }
}