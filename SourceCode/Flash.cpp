#include "Flash.hpp"

namespace Mtajima {
    Flash::Flash(GameDataRef data) : _data(data){
        shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
        shape.setFillColor(sf::Color(255, 255, 255, 0));
        flashOn = true;
    }

    bool Flash::Show(float dt, bool On){
        if (On){
            if (flashOn){
                int alpha = (int)shape.getFillColor().a + (FLASH_SPEED*dt);
                if (alpha >= 255.0f){
                    alpha = 255.0f;
                    flashOn = false;
                }
                shape.setFillColor(sf::Color(255, 255, 255, alpha));
            }else{
                int alpha = (int)shape.getFillColor().a - (FLASH_SPEED*dt);
                if (alpha <= 0.0f){
                    alpha = 0.0f;
                    flashOn = true;
                    return false;
                }
                shape.setFillColor(sf::Color(255, 255, 255, alpha));
            }
        }
        return true;
    }
    
    
    void Flash::Draw(){
        _data->window.draw(shape);
    }
}
