#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Mtajima {
    class MainMenuState : public State{
        public:
            MainMenuState(GameDataRef data);
            
            void Init();
            
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);
        
        private:
            GameDataRef _data;
            
            sf::Sprite background;
            sf::Sprite title1;
            sf::Sprite title2;
            sf::Sprite playButton;
        
            sf::SoundBuffer buttonBuffer;
            sf::Sound buttonSound;
        
            sf::Music BGM;
        
            bool soundOn;
    };
}

