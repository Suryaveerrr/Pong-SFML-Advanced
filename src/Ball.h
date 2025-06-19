#pragma once
#include <SFML/Graphics.hpp>
#include "SoundManager.h"
using namespace sf;

namespace Gameplay
{
    class Ball
    {
    private:
        Texture Pong_ball_texture;
        Sprite pong_ball_sprite;
        float screen_width;
        float screen_height;
        Vector2f velocity = {700.0f, 700.0f}; // Adjust as you want, px/sec
        const float scale_x = 0.06f;
        const float scale_y = 0.06f;
        const std::string texture_path = "C:\\Users\\Surya\\OneDrive\\Desktop\\Pong-SFML-main\\Assets\\Textures\\Ball.png";

        void loadTexture();
        void initializeVariables();

    public:
        Ball(float screenWidth, float screenHeight);
        void update(float deltaTime); // <--- CHANGED
        void render(RenderWindow *game_window);
        void checkPaddleCollision(const RectangleShape &paddleShape);
        const Sprite &getSprite() const;
    };
}
