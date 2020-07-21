#include "Enermy.hpp"
#include "DEFINITIONS.hpp"
#include <cmath>
#include <stdio.h>
#include <string>
#include <iostream>

namespace Mtajima {
    Enermy::Enermy(GameDataRef data) : _data(data){
        faceSprite1.setTexture(_data->assets.GetTexture("straightFace"));
        faceSprite2.setTexture(_data->assets.GetTexture("angryFace"));
        faceSprite3.setTexture(_data->assets.GetTexture("pienFace"));
        faceSprite4.setTexture(_data->assets.GetTexture("painfulFace"));
        
        aroundSprite0.setTexture(_data->assets.GetTexture("around0"));
        aroundSprite1.setTexture(_data->assets.GetTexture("around1"));
        aroundSprite2.setTexture(_data->assets.GetTexture("around2"));
        aroundSprite3.setTexture(_data->assets.GetTexture("around3"));
        aroundSprite4.setTexture(_data->assets.GetTexture("around4"));
        aroundSprite5.setTexture(_data->assets.GetTexture("around5"));
        aroundSprite6.setTexture(_data->assets.GetTexture("around6"));
        
        
        waitingBuffer.loadFromFile(ENERMY_WAITING_SOUND_FILEPATH);
        waitingSound.setBuffer(waitingBuffer);
        beamBuffer.loadFromFile(ENERMY_BEAM_SOUND_FILEPATH);
        beamSound.setBuffer(beamBuffer);
        dashBuffer.loadFromFile(ENERMY_DASH_SOUND_FILEPATH);
        dashSound.setBuffer(dashBuffer);
        eruptionBuffer.loadFromFile(ENERMY_ERUPTION_SOUND_FILEPATH);
        eruptionSound.setBuffer(eruptionBuffer);
        rainBuffer.loadFromFile(ENERMY_RAIN_SOUND_FILEPATH);
        rainSound.setBuffer(rainBuffer);
        rotationBuffer.loadFromFile(ENERMY_ROTATION_SOUND_FILEPATH);
        rotationSound.setBuffer(rotationBuffer);
  
        
        for (int i = 1; i <= ENERMY_FRIEND_NUMBER; i++){
            std::string stri;
            stri = std::to_string(i);
            sf::Sprite Friend(_data->assets.GetTexture("friend" + stri));
            Friend.setOrigin(Friend.getGlobalBounds().width/2, Friend.getGlobalBounds().height/2);
            Friend.setPosition(_data->window.getSize().x + 100, _data->window.getSize().y + 100);
            friendSprites.push_back(Friend);
        }
        
        HP = ENERMY_HP;
        hpBar.setSize(sf::Vector2f(600, 50));
        hpBar.setOutlineThickness(5);
        hpBar.setFillColor(sf::Color(0, 255, 0, 150));
        hpBar.setOutlineColor(sf::Color(0, 0, 0, 200));
        hpBar.setPosition(1150, 60);
        
        remainHP.setSize(sf::Vector2f(0, hpBar.getSize().y));
        remainHP.setFillColor(sf::Color(0, 0, 0, 200));
        remainHP.setPosition(hpBar.getPosition());
        
        r = 30;
        faceSprite1.setOrigin((faceSprite1.getGlobalBounds().width/2), (faceSprite1.getGlobalBounds().height/2));
        faceSprite1.setPosition((_data->window.getSize().x*3/4), (_data->window.getSize().y/2));
        faceSprite1.setScale(0.5f, 0.5f);
        faceSprite2.setColor(sf::Color(255, 255, 255, 255));
        
        faceSprite2.setOrigin((faceSprite2.getGlobalBounds().width/2), (faceSprite2.getGlobalBounds().height/2));
        faceSprite2.setPosition((_data->window.getSize().x*3/4), (_data->window.getSize().y/2));
        faceSprite2.setScale(0.5f, 0.5f);
        faceSprite2.setColor(sf::Color(255, 255, 255, 0));
        
        faceSprite3.setOrigin((faceSprite3.getGlobalBounds().width/2), (faceSprite3.getGlobalBounds().height/2));
        faceSprite3.setPosition((_data->window.getSize().x*3/4), (_data->window.getSize().y/2));
        faceSprite3.setScale(0.5f, 0.5f);
        faceSprite3.setColor(sf::Color(255, 255, 255, 0));
        
        faceSprite4.setOrigin((faceSprite4.getGlobalBounds().width/2), (faceSprite4.getGlobalBounds().height/2));
        faceSprite4.setPosition((_data->window.getSize().x*3/4), (_data->window.getSize().y/2));
        faceSprite4.setScale(0.5f, 0.5f);
        faceSprite4.setColor(sf::Color(255, 255, 255, 0));
        
        
        aroundSprite0.setOrigin((aroundSprite0.getGlobalBounds().width/2), (aroundSprite0.getGlobalBounds().height/2));
        aroundSprite0.setPosition((_data->window.getSize().x*3/4), (_data->window.getSize().y/2));
        
        aroundSprite1.setOrigin(aroundSprite1.getGlobalBounds().width/2, aroundSprite1.getGlobalBounds().height + r);
        aroundSprite2.setOrigin(aroundSprite2.getGlobalBounds().width/2, aroundSprite2.getGlobalBounds().height + r);
        aroundSprite3.setOrigin(aroundSprite3.getGlobalBounds().width/2, aroundSprite3.getGlobalBounds().height + r);
        aroundSprite4.setOrigin(aroundSprite4.getGlobalBounds().width/2, aroundSprite4.getGlobalBounds().height + r);
        aroundSprite5.setOrigin(aroundSprite5.getGlobalBounds().width/2, aroundSprite5.getGlobalBounds().height + r);
        aroundSprite6.setOrigin(aroundSprite6.getGlobalBounds().width/2, aroundSprite6.getGlobalBounds().height + r);
        
        aroundSprite1.setPosition(faceSprite1.getPosition().x, faceSprite1.getPosition().y);
        aroundSprite2.setPosition(faceSprite1.getPosition().x, faceSprite1.getPosition().y);
        aroundSprite3.setPosition(faceSprite1.getPosition().x, faceSprite1.getPosition().y);
        aroundSprite4.setPosition(faceSprite1.getPosition().x, faceSprite1.getPosition().y);
        aroundSprite5.setPosition(faceSprite1.getPosition().x, faceSprite1.getPosition().y);
        aroundSprite6.setPosition(faceSprite1.getPosition().x, faceSprite1.getPosition().y);
        
        aroundSprite1.rotate(0);
        aroundSprite2.rotate(60);
        aroundSprite3.rotate(120);
        aroundSprite4.rotate(180);
        aroundSprite5.rotate(240);
        aroundSprite6.rotate(300);
        
        collisionSprites.push_back(aroundSprite0);
        collisionSprites.push_back(aroundSprite1);
        collisionSprites.push_back(aroundSprite2);
        collisionSprites.push_back(aroundSprite3);
        collisionSprites.push_back(aroundSprite4);
        collisionSprites.push_back(aroundSprite5);
        collisionSprites.push_back(aroundSprite6);
        
        count = 0;
        waitTime = 0;
        soundTime = 0;
        setting = true;
        change = false;
    }



    void Enermy::Draw(){
        _data -> window.draw(aroundSprite1);
        _data -> window.draw(aroundSprite2);
        _data -> window.draw(aroundSprite3);
        _data -> window.draw(aroundSprite4);
        _data -> window.draw(aroundSprite5);
        _data -> window.draw(aroundSprite6);
        _data -> window.draw(faceSprite1);
        _data -> window.draw(faceSprite2);
        _data -> window.draw(faceSprite3);
        _data -> window.draw(faceSprite4);
        _data -> window.draw(aroundSprite0);
        _data -> window.draw(hpBar);
        _data -> window.draw(remainHP);
        for (int i = 0; i < ENERMY_FRIEND_NUMBER; i++){
            std::string stri;
            stri = std::to_string(i);
            _data -> window.draw(friendSprites.at(i));
        }
    }



    void Enermy::Update(float dt){
        float angle = ROTATION_AROUND_FACE_SPEED * dt;
        aroundSprite1.rotate(angle);
        aroundSprite2.rotate(angle);
        aroundSprite3.rotate(angle);
        aroundSprite4.rotate(angle);
        aroundSprite5.rotate(angle);
        aroundSprite6.rotate(angle);
        //change collision area
        collisionSprites.at(0).setPosition(aroundSprite0.getPosition());
        collisionSprites.at(1).setPosition(aroundSprite1.getPosition());
        collisionSprites.at(2).setPosition(aroundSprite2.getPosition());
        collisionSprites.at(3).setPosition(aroundSprite3.getPosition());
        collisionSprites.at(4).setPosition(aroundSprite4.getPosition());
        collisionSprites.at(5).setPosition(aroundSprite5.getPosition());
        collisionSprites.at(6).setPosition(aroundSprite6.getPosition());
        for (int i = 7; i < collisionSprites.size(); i++){
            collisionSprites.at(i).setPosition(friendSprites.at(i-7).getPosition());
        }
    }



    bool Enermy::MoveEnermy(float dt, float EnermyTime){
        sf::Vector2f position = faceSprite1.getPosition();
        int moveRepeat = 100;
        if (EnermyTime <= 2*dt){
            while (true) {
                int theta = rand() % 360;
                dx = ENERMY_MOVEMENT_SPEED * dt * cos(PI*theta/180); //dx
                dy = ENERMY_MOVEMENT_SPEED * dt * sin(PI*theta/180); //dy
                if (150 < position.x + dx * (moveRepeat) && position.x + dx * (moveRepeat) < _data->window.getSize().x - 150 &&
                    150 < position.y + dy * (moveRepeat) && position.y + dy * (moveRepeat) < _data->window.getSize().y - 150){
                    break;
                }
            }
        }

        if (EnermyTime < moveRepeat * dt){
            faceSprite1.move(dx, dy);
            faceSprite2.move(dx, dy);
            faceSprite3.move(dx, dy);
            faceSprite4.move(dx, dy);
            aroundSprite0.move(dx, dy);
            aroundSprite1.move(dx, dy);
            aroundSprite2.move(dx, dy);
            aroundSprite3.move(dx, dy);
            aroundSprite4.move(dx, dy);
            aroundSprite5.move(dx, dy);
            aroundSprite6.move(dx, dy);
            return true;
        } else {
            return false;
        }
    }

    

    bool Enermy::BeamAttack(float dt, float EnermyTime, sf::Vector2f playerPosition){
        float angle;
        float speed;
        int theta;
        int rnd;
        
        angle = 3 * ROTATION_AROUND_FACE_SPEED * dt;
        aroundSprite1.rotate(angle);
        aroundSprite2.rotate(angle);
        aroundSprite3.rotate(angle);
        aroundSprite4.rotate(angle);
        aroundSprite5.rotate(angle);
        aroundSprite6.rotate(angle);
        
        if (1.5f < EnermyTime && EnermyTime < 4.5f){
            enermyPosition = faceSprite1.getPosition();
            //mouth position
            enermyPosition.y += 70;
            if (setting){
                beamSound.play();
                waitingSound.stop();
                faceSprite3.setColor(sf::Color(255, 255, 255, 0));
                faceSprite2.setColor(sf::Color(255, 255, 255, 255));
                for (int i = 0; i < ENERMY_FRIEND_NUMBER; i++){
                    speed = dt * 6;
                    theta = rand()%61 - 30;
                    friendSprites.at(i).setPosition(enermyPosition.x, enermyPosition.y);
                    friendVec.push_back({speed*(cos(PI*theta/180)*(playerPosition.x - enermyPosition.x) -
                                                sin(PI*theta/180)*(playerPosition.y - enermyPosition.y)),
                                         speed*(sin(PI*theta/180)*(playerPosition.x - enermyPosition.x) +
                                                cos(PI*theta/180)*(playerPosition.y - enermyPosition.y))});
                    collisionSprites.push_back(friendSprites.at(i));
                }
                setting = false;
            }else{
                for (int i = 0; i < 100; i++){
                    rnd = rand() % ENERMY_FRIEND_NUMBER;
                    friendSprites.at(rnd).move(friendVec[rnd][0], friendVec[rnd][1]);
                }
            }
            return true;
            
        } else if (4.5f <= EnermyTime){
            faceSprite2.setColor(sf::Color(255, 255, 255, 0));
            faceSprite1.setColor(sf::Color(255, 255, 255, 255));
            for (int i = 0; i < ENERMY_FRIEND_NUMBER; i++){
                //std::cout << friendSprties.at(i).getPosition().x << friendVec[i][0] << std::endl;
                friendSprites.at(i).setPosition(_data->window.getSize().x + 100, _data->window.getSize().y + 100);
                friendVec.pop_back();
                collisionSprites.pop_back();
            }
            setting = true;
            soundTime = 0;
            return  false;
            
        } else {
            if (soundTime == 0){
                waitingSound.play();
                soundTime += 0.01;
            }
            faceSprite1.setColor(sf::Color(255, 255, 255, 0));
            faceSprite3.setColor(sf::Color(255, 255, 255, 255));
            return true;
        }
    }



    bool Enermy::DashAttack(float dt, float EnermyTime, sf::Vector2f playerPosition){
        float angle;
        float theta;
        
        angle = 2 * ROTATION_AROUND_FACE_SPEED * dt;
        aroundSprite1.rotate(angle);
        aroundSprite2.rotate(angle);
        aroundSprite3.rotate(angle);
        aroundSprite4.rotate(angle);
        aroundSprite5.rotate(angle);
        aroundSprite6.rotate(angle);
    
        if (1.0f < EnermyTime){
            if (setting){
                dashSound.play();
                waitingSound.stop();
                setting = false;
            }
            theta = atan2((playerPosition.y - enermyPosition.y), (playerPosition.x - enermyPosition.x));
            dx = 5 * ENERMY_MOVEMENT_SPEED * cos(theta) * dt;
            dy = 5 * ENERMY_MOVEMENT_SPEED * sin(theta) * dt;
            if (150 < faceSprite1.getPosition().x + dx && faceSprite1.getPosition().x + dx < _data->window.getSize().x - 150 &&
                150 < faceSprite1.getPosition().y + dy && faceSprite1.getPosition().y + dy < _data->window.getSize().y - 150){

                faceSprite1.move(dx, dy);
                faceSprite2.move(dx, dy);
                faceSprite3.move(dx, dy);
                faceSprite4.move(dx, dy);
                aroundSprite0.move(dx, dy);
                aroundSprite1.move(dx, dy);
                aroundSprite2.move(dx, dy);
                aroundSprite3.move(dx, dy);
                aroundSprite4.move(dx, dy);
                aroundSprite5.move(dx, dy);
                aroundSprite6.move(dx, dy);

                return true;
                
            } else {
                faceSprite3.setColor(sf::Color(255, 255, 255, 0));
                faceSprite1.setColor(sf::Color(255, 255, 255, 255));
                setting = true;
                soundTime = 0;
                return false;
            }
        } else {
            if (soundTime == 0){
                waitingSound.play();
                soundTime += 0.01;
            }
            enermyPosition = faceSprite1.getPosition();
            faceSprite1.setColor(sf::Color(255, 255, 255, 0));
            faceSprite3.setColor(sf::Color(255, 255, 255, 255));
            return true;
        }
    }



    bool Enermy::RotationAttack(float dt, float EnermyTime, sf::Vector2f playerPosition){
        float angle;
        float theta;
        int MAX = 6 * (ENERMY_FRIEND_NUMBER / 6);
        int R = 330;
        int attackSpeed = 10;
        
        angle = ROTATION_AROUND_FACE_SPEED * dt;
        aroundSprite1.rotate(angle);
        aroundSprite2.rotate(angle);
        aroundSprite3.rotate(angle);
        aroundSprite4.rotate(angle);
        aroundSprite5.rotate(angle);
        aroundSprite6.rotate(angle);
        
        if (2.0f < EnermyTime && EnermyTime < 9.0f){
            for (int i = 0; i < MAX; i++){
                if (setting){
                    waitTime = EnermyTime;
                    soundTime = EnermyTime;
                    waitingSound.stop();
                    collisionSprites.push_back(friendSprites.at(i));
                }
                if (setting || count <= i){
                    if (i % 6 == 0){
                        theta = aroundSprite1.getRotation()*PI/180;
                        friendSprites.at(i).setPosition(aroundSprite1.getPosition().x + R*sin(theta),
                                                        aroundSprite1.getPosition().y - R*cos(theta));
                    } else if (i % 6 == 1) {
                        theta = aroundSprite2.getRotation()*PI/180;
                        friendSprites.at(i).setPosition(aroundSprite2.getPosition().x + R*sin(theta),
                                                        aroundSprite2.getPosition().y - R*cos(theta));
                    } else if (i % 6 == 2) {
                        theta = aroundSprite3.getRotation()*PI/180;
                        friendSprites.at(i).setPosition(aroundSprite3.getPosition().x + R*sin(theta),
                                                        aroundSprite3.getPosition().y - R*cos(theta));
                    } else if (i % 6 == 3) {
                        theta = aroundSprite4.getRotation()*PI/180;
                        friendSprites.at(i).setPosition(aroundSprite4.getPosition().x + R*sin(theta),
                                                        aroundSprite4.getPosition().y - R*cos(theta));
                    } else if (i % 6 == 4) {
                        theta = aroundSprite5.getRotation()*PI/180;
                        friendSprites.at(i).setPosition(aroundSprite5.getPosition().x + R*sin(theta),
                                                        aroundSprite5.getPosition().y - R*cos(theta));
                    } else if (i % 6 == 5) {
                        theta = aroundSprite6.getRotation()*PI/180;
                        friendSprites.at(i).setPosition(aroundSprite6.getPosition().x + R*sin(theta),
                                                        aroundSprite6.getPosition().y - R*cos(theta));
                    }
                    
                    if (i == MAX - 1){
                        setting = false;
                    }
                    
                }
                
                if (i == count - 6 && change){
                    theta = aroundSprite1.getRotation()*PI/180;
                    friendVec.push_back({attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (cos(theta)),
                                        attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (sin(theta))});
                    theta = aroundSprite2.getRotation()*PI/180;
                    friendVec.push_back({attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (cos(theta)),
                                        attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (sin(theta))});
                    theta = aroundSprite3.getRotation()*PI/180;
                    friendVec.push_back({attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (cos(theta)),
                                        attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (sin(theta))});
                    theta = aroundSprite4.getRotation()*PI/180;
                    friendVec.push_back({attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (cos(theta)),
                                        attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (sin(theta))});
                    theta = aroundSprite5.getRotation()*PI/180;
                    friendVec.push_back({attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (cos(theta)),
                                        attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (sin(theta))});
                    theta = aroundSprite6.getRotation()*PI/180;
                    friendVec.push_back({attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (cos(theta)),
                                        attackSpeed * ROTATION_AROUND_FACE_SPEED * dt * (sin(theta))});
                    change = false;
                }
                
                if (i < count){
                    friendSprites.at(i).move(friendVec[i][0], friendVec[i][1]);
                }
            }
            
            if (EnermyTime < 7.5f && count <= MAX && waitTime < EnermyTime){
                count += 6;
                waitTime += 0.08f;
                change = true;
            }
            
            if (soundTime < EnermyTime){
                rotationSound.play();
                soundTime += 0.75f;
            }
            
            return true;
            
        } else if (9.0f <= EnermyTime){
            faceSprite3.setColor(sf::Color(255, 255, 255, 0));
            faceSprite1.setColor(sf::Color(255, 255, 255, 255));
            for (int i = 0; i < MAX; i++){
                friendSprites.at(i).setPosition(_data->window.getSize().x + 100, _data->window.getSize().y + 100);
                collisionSprites.pop_back();
            }
            friendVec.clear();
            count = 0;
            waitTime = 0;
            soundTime = 0;
            setting = true;
            change = false;
            return false;
            
        } else {
            if (soundTime == 0){
                waitingSound.play();
                soundTime = 0.01f;
            }
            faceSprite1.setColor(sf::Color(255, 255, 255, 0));
            faceSprite3.setColor(sf::Color(255, 255, 255, 255));
            return true;
        }
    }



    bool Enermy::RainAttack(float dt, float EnermyTime, sf::Vector2f playerPosition){
        float angle;
        float speed;
        int theta;
        int rnd;
        int friendPersecond = 8;
        
        if (2.0f < EnermyTime && EnermyTime < 3.5f){
            if (soundTime == 0){
                eruptionSound.play();
                soundTime += 0.01;
            }
            faceSprite3.setColor(sf::Color(255, 255, 255, 0));
            faceSprite2.setColor(sf::Color(255, 255, 255, 255));
            angle = 4 * ROTATION_AROUND_FACE_SPEED * dt;
            aroundSprite1.rotate(angle);
            aroundSprite2.rotate(angle);
            aroundSprite3.rotate(angle);
            aroundSprite4.rotate(angle);
            aroundSprite5.rotate(angle);
            aroundSprite6.rotate(angle);
            for (int i = 0; i < 100; i++){
                rnd = rand() % ENERMY_FRIEND_NUMBER;
                friendSprites.at(rnd).move(friendVec[rnd][0], friendVec[rnd][1]);
            }
            setting = true;
            return true;
            
        } else if (3.5f <= EnermyTime && EnermyTime < 10.0f) {
            faceSprite2.setColor(sf::Color(255, 255, 255, 0));
            faceSprite3.setColor(sf::Color(255, 255, 255, 255));
            if (setting){
                waitingSound.stop();
                soundTime = EnermyTime;
                waitTime = EnermyTime;
                for (int i = 0; i < ENERMY_FRIEND_NUMBER; i++){
                    friendSprites.at(i).setPosition(rand() % _data->window.getSize().x, -100);
                }
                setting = false;
            }
            for (int i = 0; i < count; i++){
                friendSprites.at(i).rotate(ROTATION_AROUND_FACE_SPEED*dt);
                friendSprites.at(i).move(0, 3*ENERMY_MOVEMENT_SPEED*dt);
            }
            
            if (EnermyTime < 8.5f && count < ENERMY_FRIEND_NUMBER && waitTime < EnermyTime){
                waitTime += 0.25f;
                count += friendPersecond;
            }
            
            if (soundTime < EnermyTime){
                rainSound.play();
                soundTime += 1.8f;
            }
            
            return true;
            
            
        } else if (10.0f <= EnermyTime){
            rainSound.stop();
            faceSprite3.setColor(sf::Color(255, 255, 255, 0));
            faceSprite1.setColor(sf::Color(255, 255, 255, 255));
            for (int i = 0; i < ENERMY_FRIEND_NUMBER; i++){
                friendSprites.at(i).setPosition(_data->window.getSize().x + 100, _data->window.getSize().y + 100);
                friendSprites.at(i).setRotation(0);
                friendVec.pop_back();
                collisionSprites.pop_back();
            }
            setting = true;
            count = 0;
            waitTime = 0;
            soundTime = 0;
            return false;
            
        } else {
            if (setting){
                waitingSound.play();
                enermyPosition = faceSprite1.getPosition();
                //playerPosition -> eruption direction
                sf::Vector2f eruptionDirection = sf::Vector2f(enermyPosition.x, -500);
                enermyPosition.y -= 100;
                faceSprite1.setColor(sf::Color(255, 255, 255, 0));
                faceSprite3.setColor(sf::Color(255, 255, 255, 255));
                for (int i = 0; i < ENERMY_FRIEND_NUMBER; i++){
                    speed = dt * 8;
                    theta = rand()%61 - 30;
                    friendSprites.at(i).setPosition(enermyPosition.x, enermyPosition.y);
                    friendVec.push_back({speed*(cos(PI*theta/180)*(eruptionDirection.x - enermyPosition.x) -
                                                sin(PI*theta/180)*(eruptionDirection.y - enermyPosition.y)),
                                         speed*(sin(PI*theta/180)*(eruptionDirection.x - enermyPosition.x) +
                                                cos(PI*theta/180)*(eruptionDirection.y - enermyPosition.y))});
                    collisionSprites.push_back(friendSprites.at(i));
                }
                setting = false;
            }
            return true;
        }
    }

    
    
    void Enermy::Attacked(){
        HP -= BULLET_POWER;
        if (remainHP.getSize().x < hpBar.getSize().x){
            remainHP.setSize(sf::Vector2f(remainHP.getSize().x + hpBar.getSize().x * BULLET_POWER/ENERMY_HP,
                            remainHP.getSize().y));
        }
    }



    int Enermy::GetHP(){
        return HP;
    }
    


    const sf::Sprite &Enermy::GetCollisionCircleSprite() const{
        return aroundSprite0;
    }



    const std::vector<sf::Sprite> &Enermy::GetCollisionSprites() const{
        return collisionSprites;
    }
}
