#include "GameWindowManager.h"
#include "EventManager.h"
#include "GamePlayManager.h"
#include "SoundManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    Sound::SoundManager::Initialize();
    Core::GameWindowManager *windowManager = new Core::GameWindowManager();
    windowManager->initialize();

    Gameplay::GamePlayManager *gameManager = new Gameplay::GamePlayManager();
    gameManager->initialize();

    sf::RenderWindow *window = windowManager->getGameWindow();
    sf::Clock clock;

    while (windowManager->isGameRunning())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        float deltaTime = clock.restart().asSeconds();
        gameManager->update(deltaTime);

        windowManager->clearGameWindow();
        gameManager->render(window);
        windowManager->displayGameWindow();
    }

    delete windowManager;
    delete gameManager;

    return 0;
}
