#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindowManager.h"
#include "EventManager.h"
#include "GamePlayManager.h"

namespace Core
{
    class GameLoop
    {
    private:
        GameWindowManager *game_window_manager;
        Event::EventManager *event_manager;
        Gameplay::GamePlayManager *gameplay_manager;

    public:
        void initialize();
        bool isGameRunning();
        void pollEvent();
        void update(float deltaTime); // <-- CHANGED
        void render();
    };
}