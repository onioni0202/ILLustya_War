#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Mtajima {
class Player{
    public:
        Player(GameDataRef data);
        
        void Draw();

		void BulletSet(int bulletMovement);
        
        void MoveBullet(float dt);
    
        void MovePlayer(float dt, int playerMovement);
    
        void Update(float dt);
    
        void Bulletdelete(int i);
    
        void Recoverytime(float dt, bool On);
    
        void Attacked();
    
        
        int GetHP();
    
        sf::Vector2f GetPosition();
    
        const std::vector<sf::Sprite> &GetBulletSprites() const;
    
        const sf::Sprite &GetPlayerSprite() const;
    
    private:
        GameDataRef _data;
        
        sf::Sprite playerSprite;
    
        sf::Sprite direction1;
    
        sf::Sprite direction2;
    
        sf::Sprite circle;
        
        std::vector<char> directions;
    
        std::vector<float> angles;
    
        std::vector<sf::Sprite> bulletSprites;
    
        std::vector<sf::Sprite> heartSprites;
    
        float angle;
    
        bool flashOn;
    
        int HP;
    
    };
}
