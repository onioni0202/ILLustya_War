#pragma once

#include "SFML/Graphics.hpp"

namespace Mtajima
{
    class InputManager{
    public:
        InputManager() {}
        ~InputManager() {}

        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        bool IsSpriteHover(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}


