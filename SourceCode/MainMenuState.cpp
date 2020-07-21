#include <sstream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Mtajima {
    MainMenuState::MainMenuState(GameDataRef data) : _data(data){
        
    }


    void MainMenuState::Init(){
        _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Title1", GAME_TITLE1_FILEPATH);
        _data->assets.LoadTexture("Title2", GAME_TITLE2_FILEPATH);
        _data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
        
        buttonBuffer.loadFromFile(BUTTON_SOUND_FILEPATH);
        buttonSound.setBuffer(buttonBuffer);
        
        BGM.openFromFile(MAIN_MENU_BGM_FILEPATH);
        BGM.setLoop(true);
        BGM.play();
        
        soundOn = false;
        
        background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        title1.setTexture(this->_data->assets.GetTexture("Title1"));
        title2.setTexture(this->_data->assets.GetTexture("Title2"));
        playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        title1.setScale(0.8f, 0.8f);
        title2.setScale(0.8f, 0.8f);
        title1.setPosition(((SCREEN_WIDTH*2/5)-(title1.getGlobalBounds().width/2)),
                           title1.getGlobalBounds().height/2-100);
        title2.setPosition(((SCREEN_WIDTH*3/5)-(title2.getGlobalBounds().width/2)),
                           title2.getGlobalBounds().height/2+130);
        
        playButton.setPosition((SCREEN_WIDTH/2)-(playButton.getGlobalBounds().width/2),
                                (SCREEN_HEIGHT*7/10)-playButton.getGlobalBounds().height/2);
        
        background.setColor(sf::Color(255, 255, 255, 225));
    }


    void MainMenuState::HandleInput(){
        sf::Event event;
        while (_data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                _data->window.close();
            }
            if (_data->input.IsSpriteHover(playButton, sf::Mouse::Left, _data->window)){
                playButton.setColor(sf::Color(255,0,0));
                if (soundOn){
                    buttonSound.play();
                    soundOn = false;
                }
            } else {
                playButton.setColor(sf::Color(255,255,255));
                soundOn = true;
            }
            
            if (_data->input.IsSpriteClicked(playButton, sf::Mouse::Left, _data->window)){
                BGM.stop();
                _data->machine.AddState(StateRef(new GameState(_data)), true);
                
            }
        }
    }


    void MainMenuState::Update(float dt){
        
    }


    void MainMenuState::Draw(float dt){
        _data->window.clear();
        
        _data->window.draw(background);
        _data->window.draw(title1);
        _data->window.draw(title2);
        _data->window.draw(playButton);
        
        _data->window.display();
    }
}

