#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Mtajima {
class Flash{
    public:
        Flash(GameDataRef data);
        
        bool Show(float dt, bool On);
        void Draw();
    
    private:
        GameDataRef _data;

        sf::RectangleShape shape;
    
        bool flashOn;
    };
}
