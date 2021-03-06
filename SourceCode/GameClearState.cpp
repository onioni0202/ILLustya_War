#include "GameClearState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <iostream>

namespace Mtajima {
    GameClearState::GameClearState(GameDataRef data) : _data(data){
        
    }


    void GameClearState::Init(){
        _data->assets.LoadTexture("Game Over Background", GAME_CLEAR_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Game", GAME_TITLE_GAME_FILEPATH);
        _data->assets.LoadTexture("Clear", GAME_TITLE_CLEAR_FILEPATH);
        _data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
        
        buttonBuffer.loadFromFile(BUTTON_SOUND_FILEPATH);
        buttonSound.setBuffer(buttonBuffer);
        
        BGM.openFromFile(GAME_CLEAR_BGM_FILEPATH);
        BGM.setLoop(true);
        BGM.play();
        
        soundOn = false;
        
        background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        title1.setTexture(this->_data->assets.GetTexture("Game"));
        title2.setTexture(this->_data->assets.GetTexture("Clear"));
        playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        title1.setScale(0.8f, 0.8f);
        title2.setScale(0.8f, 0.8f);
        title1.setPosition(((SCREEN_WIDTH*3/10)-(title1.getGlobalBounds().width/2)),
                           title1.getGlobalBounds().height/2-100);
        title2.setPosition(((SCREEN_WIDTH*3/5)-(title2.getGlobalBounds().width/2)),
                           title2.getGlobalBounds().height/2+130);
        playButton.setPosition((SCREEN_WIDTH/2)-(playButton.getGlobalBounds().width/2),
                               (SCREEN_HEIGHT*7/10)-playButton.getGlobalBounds().height/2);
        
        background.setColor(sf::Color(255, 255, 255, 255));
    }


    void GameClearState::HandleInput(){
        sf::Event event;
        while (_data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type){
                _data->window.close();
            }
            if (_data->input.IsSpriteHover(playButton, sf::Mouse::Left, _data->window)){
                playButton.setColor(sf::Color(255,0,0));
                if (soundOn){
                    buttonSound.play();
                    soundOn = false;
                }
            }else{
                playButton.setColor(sf::Color(255,255,255));
                soundOn = true;
            }
            if (_data->input.IsSpriteClicked(playButton, sf::Mouse::Left, _data->window)){
                BGM.stop();
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }


    void GameClearState::Update(float dt){
        
    }


    void GameClearState::Draw(float dt){
        _data->window.clear();
        
        _data->window.draw(background);
        
        _data->window.draw(title1);
        
        _data->window.draw(title2);
        
        _data->window.draw(playButton);
        
        _data->window.display();
    }
}
