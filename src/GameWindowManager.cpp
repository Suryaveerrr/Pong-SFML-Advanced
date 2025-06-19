#include "GameWindowManager.h"

namespace Core
{
    void GameWindowManager::initialize()
    {
        game_window = new sf::RenderWindow();
        createGameWindow();
    }

    void GameWindowManager::createGameWindow()
    {
        game_window->create(sf::VideoMode::getDesktopMode(), game_title, sf::Style::Default);
    }

    bool GameWindowManager::isGameRunning()
    {
        return game_window->isOpen();
    }

    sf::RenderWindow *GameWindowManager::getGameWindow()
    {
        return game_window;
    }

    void GameWindowManager::clearGameWindow()
    {
        game_window->clear();
    }

    void GameWindowManager::displayGameWindow()
    {
        game_window->display();
    }
}
