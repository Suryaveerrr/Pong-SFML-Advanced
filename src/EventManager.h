#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Event
{

    class EventManager
    {

    public:
        void pollEvents(RenderWindow *game_window);
        bool isKeyPressed(Keyboard::Key key);
        bool isLeftMouseButtonClicked();
    };
}