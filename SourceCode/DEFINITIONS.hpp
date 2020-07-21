#pragma once

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define PI 3.141592653589793

#define SPLASH_STATE_SHOW_TIME 1.5
#define STATE_CHANGE_SPEED 100.0f

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/pictures/background/logo_sml.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/pictures/background/bg_heaven_tengoku.jpg"
#define GAME_BACKGROUND_FILEPATH "Resources/pictures/background/bg_heaven_tengoku.jpg"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/pictures/background/bg_hell_jigoku.jpg"
#define GAME_CLEAR_BACKGROUND_FILEPATH "Resources/pictures/background/bg_heaven_tengoku.jpg"

#define MAIN_MENU_BGM_FILEPATH "Resources/audio/mainmenu_bgm.wav"
#define GAME_BGM_FILEPATH "Resources/audio/game_bgm.wav"
#define GAME_OVER_BGM_FILEPATH "Resources/audio/gameover_bgm.wav"
#define GAME_CLEAR_BGM_FILEPATH "Resources/audio/gameclear_bgm.wav"

#define GAME_TITLE1_FILEPATH "Resources/pictures/background/title1.png"
#define GAME_TITLE2_FILEPATH "Resources/pictures/background/title2.png"
#define GAME_TITLE_GAME_FILEPATH "Resources/pictures/background/game.png"
#define GAME_TITLE_OVER_FILEPATH "Resources/pictures/background/over.png"
#define GAME_TITLE_CLEAR_FILEPATH "Resources/pictures/background/clear.png"


#define PLAY_BUTTON_FILEPATH "Resources/pictures/background/playbutton.png"

#define PLAYER_FRAME_FILEPATH "Resources/pictures/player/player.png"
#define BULLET_FRAME_FILEPATH "Resources/pictures/player/bullet.png"
#define DIRECTION_FRAME_FILEPATH "Resources/pictures/player/direction.png"
#define CIRCLE_FRAME_FILEPATH "Resources/pictures/player/circle.png"
#define HEART_FRAME_FILEPATH "Resources/pictures/player/heart.png"


#define ENERMY_STRAIGHT_FACE_FILEPATH "Resources/pictures/enermy/face1.png"
#define ENERMY_ANGRY_FACE_FILEPATH "Resources/pictures/enermy/face2.png"
#define ENERMY_PIEN_FACE_FILEPATH "Resources/pictures/enermy/face3.png"
#define ENERMY_PAINFUL_FACE_FILEPATH "Resources/pictures/enermy/face4.png"

#define ENERMY_AROUND0_FILEPATH "Resources/pictures/enermy/around0.png"
#define ENERMY_AROUND1_FILEPATH "Resources/pictures/enermy/around1.png"
#define ENERMY_AROUND2_FILEPATH "Resources/pictures/enermy/around2.png"
#define ENERMY_AROUND3_FILEPATH "Resources/pictures/enermy/around3.png"
#define ENERMY_AROUND4_FILEPATH "Resources/pictures/enermy/around4.png"
#define ENERMY_AROUND5_FILEPATH "Resources/pictures/enermy/around5.png"
#define ENERMY_AROUND6_FILEPATH "Resources/pictures/enermy/around6.png"

#define ENERMY_FRIEND_FOLDERPATH "Resources/pictures/enermy/illust_ya/"
#define ENERMY_FRIEND_NUMBER 723


#define BUTTON_SOUND_FILEPATH "Resources/audio/button.wav"
#define ENERMY_WAITING_SOUND_FILEPATH "Resources/audio/enermy_waiting.wav"
#define ENERMY_BEAM_SOUND_FILEPATH "Resources/audio/enermy_beam.wav"
#define ENERMY_DASH_SOUND_FILEPATH "Resources/audio/enermy_dash.wav"
#define ENERMY_ROTATION_SOUND_FILEPATH "Resources/audio/enermy_rotation.wav"
#define ENERMY_ERUPTION_SOUND_FILEPATH "Resources/audio/enermy_eruption.wav"
#define ENERMY_RAIN_SOUND_FILEPATH "Resources/audio/enermy_rain.wav"

#define SHOOT_SOUND_FILEPATH "Resources/audio/shoot.wav"
#define ATTACK_SOUND_FILEPATH "Resources/audio/attack.wav"
#define ATTACKED_SOUND_FILEPATH "Resources/audio/attacked.wav"


enum PlayerMovements{
    STATE_PLAYER,
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum BulletMovements {
	STATE_BULLET,
	UP_DIRECTION,
	DOWN_DIRECTION,
	RIGHT_SHOOT,
	LEFT_SHOOT
};

enum EnermyMovements{
    STATE_ENERMY,
    MOVE,
    BEAMATTACK,
    DASHATTACK,
    ROTATIONATTACK,
    RAINATTACK,
};


enum GameStates{
    ePlaying,
    eGameOver,
    eGameClear
};



#define PLAYER_MOVEMENT_SPEED 600.0f
#define PLAYER_HP 5
#define PLAYER_RECOVERY_SPEED 80.0f

#define BATTERY_ROTATION_SPEED 5.0f
#define BULLET_SPEED 800.0f
#define BULLET_POWER 100
#define BULLET_DURATION_TIME 0.3f

#define ENERMY_HP 100
#define ROTATION_AROUND_FACE_SPEED 100.0f
#define ENERMY_MOVEMENT_SPEED 300.0f
#define ENERMY_MOVEMENT_CHANGE_SPEED 100.0f

#define FLASH_SPEED 1500.0f

