#include "EventManager.h"
#include <iostream>
using namespace std;
using namespace sf;
namespace Event
{

    void EventManager::pollEvents(RenderWindow *game_window)
    {
        sf::Event event;
        while (game_window->pollEvent(event))
        {
            //  Handle closing window
            if (event.type == sf::Event::Closed)
            {
                game_window->close();
            }

            // OPTIONAL: log clicks or keys
            if (isLeftMouseButtonClicked())
            {
                Vector2i position = Mouse::getPosition(*game_window);
                cout << "Left mouse click at: " << position.x << ", " << position.y << endl;
            }
        }
    }
    bool EventManager::isKeyPressed(Keyboard::Key key)
    {
        // Detect if a specific key is pressed
        return Keyboard::isKeyPressed(key);
    }

    bool EventManager::isLeftMouseButtonClicked()
    {
        // Detect if the left mouse button is clicked
        return (Mouse::isButtonPressed(Mouse::Left));
    }

}