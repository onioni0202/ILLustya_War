#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <set>

namespace Mtajima {
    class Enermy{
        public:
            Enermy(GameDataRef data);
            
            void Draw();
        
            void Update(float dt);
        
        
            bool MoveEnermy(float dt, float EnermyTime);
        
            bool BeamAttack(float dt, float EnermyTime, sf::Vector2f playerPosition);
            
            bool DashAttack(float dt, float EnermyTime, sf::Vector2f playerPosition);
            
            bool RotationAttack(float dt, float EnermyTime, sf::Vector2f playerPosition);
            
            bool RainAttack(float dt, float EnermyTime, sf::Vector2f playerPosition);
        
        
            void Attacked();
        
            int GetHP();
        
            const std::vector<sf::Sprite> &GetCollisionSprites() const;
        
            const sf::Sprite &GetCollisionCircleSprite() const;
    
        private:
            GameDataRef _data;
            
            sf::Sprite faceSprite1;
        
            sf::Sprite faceSprite2;
            
            sf::Sprite faceSprite3;
            
            sf::Sprite faceSprite4;
        
            sf::Sprite aroundSprite0;
        
            sf::Sprite aroundSprite1;
            
            sf::Sprite aroundSprite2;
            
            sf::Sprite aroundSprite3;
            
            sf::Sprite aroundSprite4;
            
            sf::Sprite aroundSprite5;
            
            sf::Sprite aroundSprite6;
        
            sf::RectangleShape hpBar;
        
            sf::RectangleShape remainHP;
        
            std::vector<sf::Sprite> collisionSprites;
        
            std::vector<sf::Sprite> friendSprites;
        
            std::vector<std::vector<double>> friendVec;
        
            sf::Vector2f enermyPosition;
        
        
        
            sf::SoundBuffer waitingBuffer;
            
            sf::Sound waitingSound;
            
            sf::SoundBuffer beamBuffer;
            
            sf::Sound beamSound;
            
            sf::SoundBuffer dashBuffer;
            
            sf::Sound dashSound;
            
            sf::SoundBuffer eruptionBuffer;
            
            sf::Sound eruptionSound;
            
            sf::SoundBuffer rainBuffer;
            
            sf::Sound rainSound;
            
            sf::SoundBuffer rotationBuffer;
            
            sf::Sound rotationSound;
            
            int count;
        
            float waitTime;
        
            float soundTime;
        
            bool change;
            
            int r;
        
            int HP;
        
            float dx;
            
            float dy;
        
            bool setting;
    };
}
