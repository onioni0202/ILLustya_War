#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Enermy.hpp"
#include "Collision.hpp"
#include "Flash.hpp"

namespace Mtajima {
    class GameState : public State{
        public:
            GameState(GameDataRef data);
            
            void Init();
            
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);
        
        private:
            GameDataRef _data;
            
            sf::Sprite _background;
        
            sf::Music BGM;
        
            Player *player;
        
            Enermy *enermy;
        
            Collision collision;
        
            Flash *flash;

			bool moveOk;
        
            bool shootOk;
        
            bool oneMove;
        
            bool flashOn;
            
            bool recovery;
            
            sf::Clock Clock;
        
            sf::Clock playerClock;
        
            sf::Clock enermyClock;
        
            sf::Clock bulletClock;
        
            sf::Clock recoveryClock;
        
            sf::Clock stateChangeClock;
        
            sf::Vector2f playerPosition;
        
            sf::SoundBuffer attackBuffer;
            
            sf::SoundBuffer attackedBuffer;
        
            sf::SoundBuffer shootBuffer;
            
            sf::Sound attackSound;
            
            sf::Sound attackedSound;
            
            sf::Sound shootSound;

            int gameState;
        
            int enermyState;
            
            int playerMovement;

			int bulletMovement;
        
            int test;
    };
}

