/**
 * @file typeDef.h
 * @brief Header file for general definitions
 * @date 08/06/2023
 * @version 2.0
 */

#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <string>

//-------- Values for the windows settings --------

#define HEIGHT 22 /**< The height of the window in tiles */

#define WIDTH 40 /**< The width of the window in tiles */

#define FPS 60 /**< Defines the number of frames per second */

#define BLOCK_SIZE 32 /**< The number of pixels for each side of all blocks */

//-------------------------------------------------

// ------- All value for entity speed --------

#define PLAYERMAXSPEED 10 /**< Speed for the players in blocks per second */

#define STANDARD_ENEMY_SPEED 5 /**< Speed for the standard enemy in blocks per second */

#define GIANT_ENEMY_SPEED 3 /**< Speed for the giant enemy in blocks per second */

#define ACCELERATOR_ENEMY_SPEED 4 /**< Speed for the accelerator enemy in blocks per second */

#define JUMPER_ENEMY_SPEED 4 /**< Speed for the jumper enemy in blocks per second */

#define FREEZER_ENEMY_SPEED 15 /**< Speed for the freezer enemy in blocks per second */

// -------------------------------------------------

// --------------- Values for the game -------------

#define MAX_LIFE 3 /**< Maximum life for the player*/

#define KO_TIME 3 /**< The duration for being knocked out in seconds */

#define COMBO_RANGE_TIME 1500 /**< The time in milliseconds when a combo is possible */

#define COUNTER_VALUE 150 /**< Defined value to restart block state */

#define DISTANCE_JUMPER_JUMP 20 /**< The number of blocks the jumper has to walk between each jump */

#define DISTANCE_FOR_MAX_GRAVITY 96 /**< Defines the number of pixels a player needs to reach maximum gravity: 576 pixels/s */

#define PLAYER_JUMP_HEIGHT 6 /**< Defines the number of blocks a player jumps */

#define BLOCK_HIT_TIME 100 /**< The time that a block is hit in milliseconds */

#define FREEZER_HIT_PLAYER 1000 /**< The time that a player is frozen */

// -------------------------------------------------

// - Points settings, all ennemies and there points

#define STANDARD_POINTS 100 /**< The number of point that player won when he kill standard enemy */

#define ACCELERATOR_POINTS 200 /**< The number of point that player won when he kill the accelerator enemy */

#define GIANT_POINTS 300 /**< The number of point that player won when he kill the giant enemy */

#define JUMPER_POINTS 400 /**< The number of point that player won when he kill the jumper enemy */

#define FREEZER_POINTS 500 /**< The number of point that player won when he kill the freezer enemy */

// -------------------------------------------------

// ---- Configure the value of each money type -----

#define RED_COIN_VALUE 1 /**< The value added to the waller for the red coin (RED) when the player hit him*/

#define YELLOW_COIN_VALUE 3 /**< The value added to the waller for the yellow coin (YELLOW) when the player hit him*/

#define CASH_VALUE 5 /**< The value added to the waller for the cash (BILL) when the player hit him*/

// -------------------------------------------------

//------------- Values for the animations ----------

#define TIME_FOR_ANIMATION_CYCLE 150 /**< The duration for a cycle of each animation */

#define NUMBER_IMAGE_PER_ANIMATION 2 /**< The number of images for each animation */

// -------------------------------------------------

// ------------- All path for tileset --------------

#define TILESET_FILE_PATH "://ressources/tileset0.png"

#define TILESET2_FILE_PATH "://ressources/tileset1.png"

#define TILESET3_FILE_PATH "://ressources/tileset2.png"

#define TILESET4_FILE_PATH "://ressources/tileset2.png"

#define TILESET5_FILE_PATH "://ressources/tileset2.png"

// -------------------------------------------------

// -------- All path for background image ----------

#define BACKGROUND1_FILE_PATH ":/ressources/background0.png"

#define BACKGROUND2_FILE_PATH ":/ressources/background1.png"

#define BACKGROUND3_FILE_PATH ":/ressources/background2.png"

#define BACKGROUND4_FILE_PATH ":/ressources/background2.png"

#define BACKGROUND5_FILE_PATH ":/ressources/background2.png"

// -------------------------------------------------

// ---- Other path (font, highscore saving file)----

#define FONT_PATH "://ressources/PressStart2P-Regular.ttf"

#define HIGHSCORES_FILE_PATH "ressources/highscores.txt"

// -------------------------------------------------


// --- Values for the moovement of each entities ---

#define STILL 0 /**< Value indicating stillness */

#define GRAVITY 1 /**< Gravity value */

// -------------------------------------------------

// ----- Other constante for the game program ------

#define MAX_LEVEL 10 /**< Maximum level */

#define NUMBER_LOOP_PER_SECOND 960 /**< Defines the number of game loop iterations per second */

// -------------------------------------------------

/**
 * @brief The MenuState enum represents the states of the menu
 */
enum MenuState {MAINMENU,PAUSEMENU,GAMEOVER,GAMEOVER_TOP10,GAME};

/**
 * @brief The MoveX enum represents the states of movement along the x-axis
 */
enum MoveX {NONE = 0,RIGHT_X = 1,LEFT_X = -1};

/**
 * @brief The EnemyType enum represents the types of enemies
 */
enum EnemyType {STANDARD = STANDARD_POINTS,ACCELERATOR = ACCELERATOR_POINTS,JUMPER = JUMPER_POINTS,GIANT = GIANT_POINTS,FREEZER = FREEZER_POINTS};

/**
 * @brief The BlockType enum represents the types of blocks
 */
enum BlockType {BRICK,GROUND,OBSTACLE,POW};

/**
 * @brief The Direction enum represents the directions of the spawners
 */
enum Direction {EAST,WEST};

/**
 * @brief The MoneyType enum represents the types of money
 */
enum MoneyType {RED = RED_COIN_VALUE,YELLOW = YELLOW_COIN_VALUE,BILL = CASH_VALUE};

/**
 * @brief The Sides enum represents the sides of enemy appearances
 */
enum Sides {LEFT,RIGHT};

/**
 * @brief Define a comparator to reverse the order of the heap
 */
struct CompareScore {
    bool operator()(std::pair<std::string, unsigned int> const& p1, std::pair<std::string, unsigned int> const& p2) {
        return p1.second > p2.second;
    }
};

#endif // TYPEDEF_H
