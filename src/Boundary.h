#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class Boundary
    {
    private:
        sf::RectangleShape topBoundary;
        sf::RectangleShape bottomBoundary;
        sf::RectangleShape leftBoundary;
        sf::RectangleShape rightBoundary;
        sf::RectangleShape centerLine;

        float horizontal_boundary_width;
        const float horizontal_boundary_height = 20.0f;

        float bottom_position_y;

        const float top_position_x = 0.0f;
        const float top_position_y = 0.0f;

        const float vertical_boundary_width = 20.0f;
        float vertical_boundary_height;

        const float left_position_x = 0.0f;
        const float left_position_y = 0.0f;

        float right_position_x;
        const float right_position_y = 0.0f;

        const float center_line_width = 10.0f;
        float center_line_height;
        float center_line_position_x;
        const float center_line_position_y = 20.0f;

        const sf::Color boundary_color = sf::Color::Blue;
        const sf::Color center_line_color = sf::Color::White;

        bool showCenterLine = true;

        void createTopBoundary();
        void createBottomBoundary();
        void createLeftBoundary();
        void createRightBoundary();
        void createCenterLine();

    public:
        Boundary(float screen_width, float screen_height);

        void update();
        void render(sf::RenderWindow *game_window);
        void setCenterLineVisible(bool visible);
    };
}