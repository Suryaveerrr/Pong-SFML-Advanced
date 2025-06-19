#pragma once
#include <SFML/Graphics.hpp>

namespace Core
{
    class GameWindowManager
    {
    private:
        sf::RenderWindow *game_window;
        const std::string game_title = "Pong SFML";

    public:
        void initialize();
        void createGameWindow();
        bool isGameRunning();
        sf::RenderWindow *getGameWindow();
        void clearGameWindow();
        void displayGameWindow();
    };
}