#include "GameLoop.h"

namespace Core
{
    void GameLoop::initialize()
    {
        game_window_manager = new GameWindowManager();
        event_manager = new Event::EventManager();
        gameplay_manager = new Gameplay::GamePlayManager();

        game_window_manager->initialize();
    }

    bool GameLoop::isGameRunning()
    {
        return game_window_manager->isGameRunning();
    }

    void GameLoop::pollEvent()
    {
        event_manager->pollEvents(game_window_manager->getGameWindow());
    }

    void GameLoop::update(float deltaTime) // <-- CHANGED
    {
        gameplay_manager->update(deltaTime); // <-- CHANGED
    }

    void GameLoop::render()
    {
        game_window_manager->clearGameWindow();
        gameplay_manager->render(game_window_manager->getGameWindow());
        game_window_manager->displayGameWindow();
    }
}