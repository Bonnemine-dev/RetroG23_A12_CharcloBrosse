#ifndef TYPEDEF_H
#define TYPEDEF_H

#define HEIGHT 22 // the height of the window in tile
#define WIDTH 40 // the width of the window in tile
#define COUNTER_VALUE 150 // define value to restart block state

#define STANDARD_ENEMY_SPEED 1

#define BLOCK_HIT_TIME 100

#define PLAYERMAXSPEED 1 // define value of max X speed
#define STILL 0 // define value of still
#define GRAVITY 1 // gravity value

enum MenuState {
    MAINMENU,
    PAUSEMENU,
    GAMEOVER,
    GAME
};

#endif // TYPEDEF_H
