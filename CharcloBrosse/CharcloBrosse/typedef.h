/**
 * @file typeDef.h
 * @brief Header file for general definition
 * @date 08/06/2023
 * @version 2.0
 */

#ifndef TYPEDEF_H
#define TYPEDEF_H

#define HEIGHT 22 // the height of the window in tile
#define WIDTH 40 // the width of the window in tile
#define COUNTER_VALUE 150 // define value to restart block state

#define NUMBER_LOOP_PER_SECOND 960 //Define the number that the gameloop have to make in one second

#define STANDARD_ENEMY_SPEED 5 //Speed for the standard ennemie in blocks per second
#define GIANT_ENEMY_SPEED 3 //Speed for the giant ennemie in blocks per second
#define ACCELERATOR_ENEMY_SPEED 4 //Speed for the accelerator ennemie in blocks per second
#define JUMPER_ENEMY_SPEED 4 //Speed for the jumper ennemie in blocks per second
#define FREEZER_ENEMY_SPEED 10 //Speed for the freezer ennemie in blocks per second
#define KO_TIME 3//The Duration for the KO in seconds

#define DISTANCE_JUMPER_JUMP 20 //the number of block thath the jumper have to walk beetwen each jump

#define TIME_FOR_ANIMATION_CYCLE 150//The Duration for the a cycle for each animation
#define NUMBER_IMAGE_PER_ANIMATION 2//number of image ffor an animation

#define FPS 60 //Define the number of frame per seconds
#define BLOCK_HIT_TIME 100 //The time that a block are hit in milliseconds
#define FREEZER_HIT_PLAYER 1000 //The time that a player freeze
#define BLOCK_SIZE 32 //the number of pixels for each side for all blocks

#define PLAYERMAXSPEED 10 //Speed for the players in blocks per second
#define PLAYER_JUMP_HEIGHT 6 //define the number of block that a player make when he jump
#define STILL 0 // define value of still
#define GRAVITY 1 // gravity value


#define TILESET_FILE_PATH "://ressources/tileset0.png"
#define BACKGROUND1_FILE_PATH ":/ressources/background0.png"
#define BACKGROUND2_FILE_PATH ":/ressources/background1.png"
#define LEVEL_FILE_PATH "://ressources/level1.json"
#define FONT_PATH "://ressources/PressStart2P-Regular.ttf"
#define HIGHSCORES_FILE_PATH "../../CharcloBrosse/CharcloBrosse/ressources/highscores.txt"

#define MAX_LEVEL 4
#define MAX_LIFE 3

/**
 * @brief The MenuState enum states of the menu
 */
enum MenuState {
    MAINMENU,
    PAUSEMENU,
    GAMEOVER,
    GAMEOVER_TOP10,
    GAME
};

/**
 * @brief The MoveX enum states of the x axes movement
 */
enum MoveX {
    NONE = 0,
    RIGHT_X = 1,
    LEFT_X = -1,
};

/**
 * @brief The EnemyType enum the enemies types
 */
enum EnemyType{
    STANDARD=100,
    ACCELERATOR=200,
    JUMPER=300,
    GIANT=400,
    FREEZER=500,
};

/**
 * @brief The BlockType enum the blocks types
 */
enum BlockType{
    BRICK,
    GROUND,
    OBSTACLE,
    POW
};

/**
 * @brief The Direction enum the directions of the spawners
 */
enum Direction{
    EAST,
    WEST
};

/**
 * @brief The MoneyType enum the types of the money
 */
enum MoneyType{
    RED = 1,
    YELLOW = 3,
    BILL = 5
};

/**
 * @brief The Sides enum the sides of apparitions of the enemy
 */
enum Sides{
    LEFT,
    RIGHT
};

#endif // TYPEDEF_H
