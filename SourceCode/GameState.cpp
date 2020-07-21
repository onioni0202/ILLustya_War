#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameClearState.hpp"
#include <string>
#include <iostream>

namespace Mtajima {
    GameState::GameState(GameDataRef data) : _data(data){
        
    }


    void GameState::Init(){
        std::cout << "Game State" << std::endl;
        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Player", PLAYER_FRAME_FILEPATH);
        _data->assets.LoadTexture("Bullet", BULLET_FRAME_FILEPATH);
        _data->assets.LoadTexture("direction", DIRECTION_FRAME_FILEPATH);
        _data->assets.LoadTexture("circle", CIRCLE_FRAME_FILEPATH);
        _data->assets.LoadTexture("heart", HEART_FRAME_FILEPATH);
        
        _data->assets.LoadTexture("straightFace", ENERMY_STRAIGHT_FACE_FILEPATH);
        _data->assets.LoadTexture("angryFace", ENERMY_ANGRY_FACE_FILEPATH);
        _data->assets.LoadTexture("pienFace", ENERMY_PIEN_FACE_FILEPATH);
        _data->assets.LoadTexture("painfulFace", ENERMY_PAINFUL_FACE_FILEPATH);
        
        _data->assets.LoadTexture("around0", ENERMY_AROUND0_FILEPATH);
        _data->assets.LoadTexture("around1", ENERMY_AROUND1_FILEPATH);
        _data->assets.LoadTexture("around2", ENERMY_AROUND2_FILEPATH);
        _data->assets.LoadTexture("around3", ENERMY_AROUND3_FILEPATH);
        _data->assets.LoadTexture("around4", ENERMY_AROUND4_FILEPATH);
        _data->assets.LoadTexture("around5", ENERMY_AROUND5_FILEPATH);
        _data->assets.LoadTexture("around6", ENERMY_AROUND6_FILEPATH);
        
        attackBuffer.loadFromFile(ATTACK_SOUND_FILEPATH);
        attackedBuffer.loadFromFile(ATTACKED_SOUND_FILEPATH);
        shootBuffer.loadFromFile(SHOOT_SOUND_FILEPATH);
        attackSound.setBuffer(attackBuffer);
        attackedSound.setBuffer(attackedBuffer);
        shootSound.setBuffer(shootBuffer);
        
        BGM.openFromFile(GAME_BGM_FILEPATH);
        BGM.setLoop(true);
        BGM.play();
        
        for (int i = 1; i <= ENERMY_FRIEND_NUMBER; i++){
            std::string stri;
            std::string path = ENERMY_FRIEND_FOLDERPATH;
            stri = std::to_string(i);
            _data->assets.LoadTexture("friend"+stri, path+stri+".png");
        }
        
        
        player = new Player(_data);
        enermy = new Enermy(_data);
        flash = new Flash(_data);
        
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        
        playerMovement = STATE_PLAYER;
        
        gameState = ePlaying;
        
        enermyState = STATE_ENERMY;
        
		moveOk = true;

        shootOk = true;
        
        oneMove = true;
        
        flashOn = false;
        
        recovery = false;

        test = 0;
    }


    void GameState::HandleInput(){
		if (gameState == ePlaying) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (moveOk == true || playerMovement != UP)) {
				playerMovement = UP;
				playerClock.restart();
				moveOk = false;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (moveOk == true || playerMovement != DOWN)) {
				playerMovement = DOWN;
				playerClock.restart();
				moveOk = false;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (moveOk == true || playerMovement != LEFT)) {
				playerMovement = LEFT;
				playerClock.restart();
				moveOk = false;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (moveOk == true || playerMovement != RIGHT)) {
				playerMovement = RIGHT;
				playerClock.restart();
				moveOk = false;
			}

			if (playerClock.getElapsedTime().asSeconds() > 0.1f) {
				playerMovement = STATE_PLAYER;
				moveOk = true;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (shootOk == true)) {
				bulletMovement = UP_DIRECTION;
				player->BulletSet(bulletMovement);
				bulletClock.restart();
				shootOk = false;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (shootOk == true)) {
				bulletMovement = DOWN_DIRECTION;
				player->BulletSet(bulletMovement);
				bulletClock.restart();
				shootOk = false;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (shootOk == true)) {
				bulletMovement = LEFT_SHOOT;
				player->BulletSet(bulletMovement);
				bulletClock.restart();
                shootSound.play();
				shootOk = false;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (shootOk == true)) {
				bulletMovement = RIGHT_SHOOT;
				player->BulletSet(bulletMovement);
				bulletClock.restart();
                shootSound.play();
				shootOk = false;
			}

			if (bulletClock.getElapsedTime().asSeconds() > BULLET_DURATION_TIME) {
				bulletMovement = STATE_BULLET;
				shootOk = true;
			}
		}
	
        sf::Event event;
        while (_data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type){
                _data->window.close();
            }
        }
    }


    void GameState::Update(float dt){
        if (GameStates::ePlaying == gameState){
            enermy->Update(dt);
            if (enermyState == STATE_ENERMY){
                enermyClock.restart();
                playerPosition = player -> GetPosition();
				int rnd = rand();
                if (rnd%100 < 12 || oneMove){
                    enermyState = MOVE;
                } else if (rnd%100 < 25){
                    enermyState = DASHATTACK;
                } else if (rnd%100 < 50){
                    enermyState = BEAMATTACK;
                } else if (rnd%100 < 75){
                    enermyState = ROTATIONATTACK;
                } else if (rnd%100 < 100){
                    enermyState = RAINATTACK;
                }
            } else if (enermyState == MOVE){
                if (!enermy->MoveEnermy(dt, enermyClock.getElapsedTime().asSeconds())){
                    oneMove = false;
                    enermyState = STATE_ENERMY;
                }
                
            }else if (enermyState == BEAMATTACK){
                if (!enermy->BeamAttack(dt, enermyClock.getElapsedTime().asSeconds(), playerPosition)){
                    oneMove = true;
                    enermyState = STATE_ENERMY;
                }
            } else if (enermyState == DASHATTACK){
                if (!enermy->DashAttack(dt, enermyClock.getElapsedTime().asSeconds(), playerPosition)){
                    oneMove = true;
                    enermyState = STATE_ENERMY;
                }
            } else if (enermyState == ROTATIONATTACK){
                if (!enermy->RotationAttack(dt, enermyClock.getElapsedTime().asSeconds(), playerPosition)){
                    oneMove = true;
                    enermyState = STATE_ENERMY;
                }
            } else if (enermyState == RAINATTACK){
                if (!enermy->RainAttack(dt, enermyClock.getElapsedTime().asSeconds(), playerPosition)){
                    oneMove = true;
                    enermyState = STATE_ENERMY;
                }
            }
            
			player->MovePlayer(dt, playerMovement);
            player->MoveBullet(dt);

            std::vector<sf::Sprite> bulletSprites = player->GetBulletSprites();
            for (int i = 0; i < bulletSprites.size(); i++){
                if (collision.CheckSpriteCollision(enermy->GetCollisionCircleSprite(), 0.8f, bulletSprites.at(i), 0.1f)){
                    player->Bulletdelete(i);
                    enermy->Attacked();
                    attackSound.play();
                    if (enermy -> GetHP() <= 0){
                        stateChangeClock.restart();
                        gameState = GameStates::eGameClear;
                    }
                    break;
                }
            }
            
            std::vector<sf::Sprite> enermySprites = enermy->GetCollisionSprites();
            for (int i = 0; i < enermySprites.size(); i++){
                if (collision.CheckSpriteCollision(player->GetPlayerSprite(), 0.08f, enermySprites.at(i), 0.85f) &&
                    recoveryClock.getElapsedTime().asSeconds() > PLAYER_RECOVERY_SPEED * dt){
                    flashOn = true;
                    recovery = true;
                    recoveryClock.restart();
                    attackedSound.play();
                    player -> Attacked();
                    if (player -> GetHP() <= 0){
                        stateChangeClock.restart();
                        gameState = GameStates::eGameOver;
                    }
                    break;
                }
            }
    
            
            if (!(flash -> Show(dt, flashOn))){
                flashOn = false;
            }
            if (recoveryClock.getElapsedTime().asSeconds() > PLAYER_RECOVERY_SPEED * dt){
                recovery = false;
            }
            player -> Recoverytime(dt, recovery);
            
        
        } else if (gameState == GameStates::eGameOver &&
                   stateChangeClock.getElapsedTime().asSeconds() > STATE_CHANGE_SPEED * dt){
            BGM.stop();
            _data -> machine.AddState(StateRef(new GameOverState(_data)), true);
    
        } else if (gameState == GameStates::eGameClear &&
                   stateChangeClock.getElapsedTime().asSeconds() > STATE_CHANGE_SPEED * dt){
            BGM.stop();
            _data -> machine.AddState(StateRef(new GameClearState(_data)), true);
        }
    }


    void GameState::Draw(float dt){
        _data->window.clear();
        
        _data->window.draw(_background);
        
        enermy->Draw();
        player->Draw();
        flash->Draw();
        
        _data->window.display();
    }
}

