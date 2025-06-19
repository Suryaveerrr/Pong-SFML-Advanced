#include "Boundary.h"

using namespace sf;

namespace Gameplay
{
    Boundary::Boundary(float screen_width, float screen_height)
    {
        horizontal_boundary_width = screen_width;
        bottom_position_y = screen_height - horizontal_boundary_height;
        vertical_boundary_height = screen_height;

        right_position_x = screen_width - vertical_boundary_width;

        center_line_height = screen_height - 40.0f;
        center_line_position_x = screen_width / 2.0f - center_line_width / 2.0f;

        createTopBoundary();
        createBottomBoundary();
        createLeftBoundary();
        createRightBoundary();
        createCenterLine();
    }

    void Boundary::createTopBoundary()
    {
        topBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
        topBoundary.setPosition(top_position_x, top_position_y);
        topBoundary.setFillColor(boundary_color);
    }

    void Boundary::createBottomBoundary()
    {
        bottomBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
        bottomBoundary.setPosition(top_position_x, bottom_position_y);
        bottomBoundary.setFillColor(boundary_color);
    }

    void Boundary::createLeftBoundary()
    {
        leftBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
        leftBoundary.setPosition(left_position_x, left_position_y);
        leftBoundary.setFillColor(boundary_color);
    }

    void Boundary::createRightBoundary()
    {
        rightBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
        rightBoundary.setPosition(right_position_x, right_position_y);
        rightBoundary.setFillColor(boundary_color);
    }

    void Boundary::createCenterLine()
    {
        centerLine.setSize(Vector2f(center_line_width, center_line_height));
        centerLine.setPosition(center_line_position_x, center_line_position_y);
        centerLine.setFillColor(center_line_color);
    }

    void Boundary::setCenterLineVisible(bool visible)
    {
        showCenterLine = visible;
    }

    void Boundary::update()
    {
        // nothing dynamic for now
    }

    void Boundary::render(RenderWindow *game_window)
    {
        game_window->draw(topBoundary);
        game_window->draw(bottomBoundary);
        game_window->draw(leftBoundary);
        game_window->draw(rightBoundary);

        if (showCenterLine)
        {
            game_window->draw(centerLine);
        }
    }
}
