/**
 * @file typeDef.h
 * @brief Header file for general definition
 * @author Kevin Simon
 * @date 08/06/2023
 * @version 1.3
 */

#ifndef TYPEDEF_H
#define TYPEDEF_H

#define HEIGHT 22 // the height of the window in tile
#define WIDTH 40 // the width of the window in tile
#define COUNTER_VALUE 150 // define value to restart block state

#define NUMBER_LOOP_PER_SECOND 960 //Define the number that the gameloop have to make in one second

#define STANDARD_ENEMY_SPEED 5 //Speed for the standard ennemie in blocks per second

#define FPS 10
#define BLOCK_HIT_TIME 100
#define BLOCK_SIZE 32 //the number of pixels for each side for all blocks

#define PLAYERMAXSPEED 30 //Speed for the players in blocks per second
#define PLAYER_JUMP_HEIGHT 6 //define the number of block that a player make when he jump
#define STILL 0 // define value of still
#define GRAVITY 1 // gravity value

#define TILESET_FILE_PATH "/Users/bonnemine/Library/Mobile Documents/com~apple~CloudDocs/BUT_1 /S2/SAE2/SAE1256/ressources/tileset_exclu.png"
#define LEVEL_FILE_PATH "/Users/bonnemine/Library/Mobile Documents/com~apple~CloudDocs/BUT_1 /S2/SAE2/SAE1256/ressources/oneenemy.json"

enum MenuState {
    MAINMENU,
    PAUSEMENU,
    GAMEOVER,
    GAME
};

#endif // TYPEDEF_H
