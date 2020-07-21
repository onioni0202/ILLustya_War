#include "Player.hpp"
#include "DEFINITIONS.hpp"
#include <cmath>
#include <iostream>

namespace Mtajima {
    Player::Player(GameDataRef data) : _data(data){
        playerSprite.setTexture(_data->assets.GetTexture("Player"));
        direction1.setTexture(_data->assets.GetTexture("direction"));
        direction2.setTexture(_data->assets.GetTexture("direction"));
        circle.setTexture(_data->assets.GetTexture("circle"));
        
        HP = PLAYER_HP;
        
        sf::Sprite heart( _data->assets.GetTexture("heart"));
        heart.setScale(0.1f, 0.1f);
        for(unsigned int i = 0; i < PLAYER_HP; i++){
            heart.setPosition(180+50*i, 60);
            heartSprites.push_back(heart);
        }
        
        playerSprite.setScale(0.1f, 0.1f);
        playerSprite.setColor(sf::Color(255, 0, 0, 255));
        
        playerSprite.setOrigin(playerSprite.getGlobalBounds().width/2,
                                playerSprite.getGlobalBounds().height/2);
        
        playerSprite.setPosition((_data->window.getSize().x/4)-(playerSprite.getGlobalBounds().width/2),
                            (_data->window.getSize().y/2)-(playerSprite.getGlobalBounds().height/2));
        
        
        circle.setScale(0.2, 0.2);
        circle.setColor(sf::Color::Black);
        
        direction1.setScale(0.4, 0.4);
        direction2.setScale(0.4, 0.4);
        direction1.setOrigin(0, direction1.getGlobalBounds().height+12);
        direction2.setOrigin(0, direction2.getGlobalBounds().height+12);
        
        direction1.setPosition(circle.getGlobalBounds().width/2,
                               circle.getGlobalBounds().height/2);
        direction2.setPosition(circle.getGlobalBounds().width/2,
                               circle.getGlobalBounds().height/2);
        direction2.rotate(180);
        
        flashOn = true;
        angle = 0;
    }



    void Player::Draw(){
        _data->window.draw(direction1);
        _data->window.draw(direction2);
        for (unsigned short int i = 0; i < PLAYER_HP; i++){
            _data->window.draw(heartSprites.at(i));
        }
        _data->window.draw(circle);
        _data->window.draw(playerSprite);
        for (unsigned short int i = 0; i < bulletSprites.size(); i++){
            _data->window.draw(bulletSprites.at(i));
        }
    }



    void Player::MovePlayer(float dt, int playerMovement){
        if (UP == playerMovement){
            if (playerSprite.getPosition().y > 5){
                playerSprite.move(0, -PLAYER_MOVEMENT_SPEED*dt);
            }
        } else if (DOWN == playerMovement){
            if (playerSprite.getPosition().y < _data->window.getSize().y - 50){
                playerSprite.move(0, PLAYER_MOVEMENT_SPEED*dt);
            }
        } else if (LEFT == playerMovement){
            if (playerSprite.getPosition().x > 5){
                playerSprite.move(-PLAYER_MOVEMENT_SPEED*dt, 0);
            }
        } else if (RIGHT == playerMovement){
            if (playerSprite.getPosition().x < _data->window.getSize().x - 50){
                playerSprite.move(PLAYER_MOVEMENT_SPEED*dt, 0);
            }
        }
    }



	void Player::BulletSet(int bulletMovement) {
		if (bulletMovement == UP_DIRECTION) {
			if (angle <= -45.0f) {
				angle = -45.0f;
			} else {
				angle -= 5;
				direction1.rotate(-5);
				direction2.rotate(5);
			}
		} else if (bulletMovement == DOWN_DIRECTION) {
			if (angle >= 45.0f) {
				angle = 45.0f;
			} else {
				angle += 5;
				direction1.rotate(5);
				direction2.rotate(-5);
			}
		} else if (bulletMovement == LEFT_SHOOT) {
			sf::Sprite bullet(_data->assets.GetTexture("Bullet"));
			bullet.setScale(0.1f, 0.1f);
			sf::Vector2f position = playerSprite.getPosition();
			bullet.setPosition(position.x + 45, position.y + 40);
			directions.push_back('L');
			angles.push_back(angle);
			bulletSprites.push_back(bullet);
		} else if (bulletMovement == RIGHT_SHOOT) {
			sf::Sprite bullet(_data->assets.GetTexture("Bullet"));
			bullet.setScale(0.1f, 0.1f);
			sf::Vector2f position = playerSprite.getPosition();
			bullet.setPosition(position.x + 20, position.y);
			directions.push_back('R');
			angles.push_back(angle);
			bulletSprites.push_back(bullet);
		}
	}



    void Player::MoveBullet(float dt){
        for (unsigned short int i = 0; i < bulletSprites.size(); i++){
            sf::Vector2f position = bulletSprites.at(i).getPosition();
            if (position.x < 0 || position.x > _data->window.getSize().x + 5 ||
                position.y < 0 || position.y > _data->window.getSize().y + 5){
                Player::Bulletdelete(i);
            }
        }
        for (unsigned short int i = 0; i < bulletSprites.size(); i++){
            float movement = BULLET_SPEED * dt;
            if (directions.at(i) == 'R'){
                bulletSprites.at(i).setRotation(angles.at(i));
                bulletSprites.at(i).move(movement*cos(PI*angles.at(i)/180),
                                         movement*sin(PI*angles.at(i)/180));
            } else if (directions.at(i) == 'L'){
                bulletSprites.at(i).setRotation(180-angles.at(i));
                bulletSprites.at(i).move(-movement*cos(PI*angles.at(i)/180),
                                         movement*sin(PI*angles.at(i)/180));
            }
        }
    }



    void Player::Bulletdelete(int i){
        directions.erase(directions.begin() + i);
        angles.erase(angles.begin() + i);
        bulletSprites.erase(bulletSprites.begin() + i);
    }



    void Player::Recoverytime(float dt, bool On){
        if (On){
            if (flashOn){
                int alpha = (int)playerSprite.getColor().a + (FLASH_SPEED*dt*3);
                if (alpha >= 255.0f){
                    alpha = 255.0f;
                    flashOn = false;
                }
                playerSprite.setColor(sf::Color(255, 0, 0, alpha));
            } else{
                int alpha = (int)playerSprite.getColor().a - (FLASH_SPEED*dt*3);
                if (alpha <= 0.0f){
                    alpha = 0.0f;
                    flashOn = true;
                }
                playerSprite.setColor(sf::Color(255, 0, 0, alpha));
            }
        } else{
            playerSprite.setColor(sf::Color(255, 0, 0, 255));
        }
    }



    void Player::Attacked(){
        HP--;
        for(unsigned int i = 0; i < PLAYER_HP; i++){
            if (i < PLAYER_HP - HP){
                heartSprites.at(i).setColor(sf::Color(0, 255, 0));
            }
        }
    }


    
    int Player::GetHP(){
        return HP;
    }



    sf::Vector2f Player::GetPosition(){
        return playerSprite.getPosition();
    }



    void Player::Update(float dt){
        
    }



    const std::vector<sf::Sprite> &Player::GetBulletSprites() const{
        return bulletSprites;
    }



    const sf::Sprite &Player::GetPlayerSprite() const{
        return playerSprite;
    }
}
