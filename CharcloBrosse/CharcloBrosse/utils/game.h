
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <Qrect>
#include "Entity/player.h"
#include "utils/hmi.h"
#include "utils/tileset.h"
#include "utils/level.h"

//#include "DB_Score.h"

/**
 * @brief The Game class
 */


class Game {
private:
    TileSet* itsTileSet;
    Player* itsPlayer;
    unsigned int itsScore;
    Level* itsLevel;
    HMI* itsHMI;
//    DB_Score itsDBScore;
    /* Les collisions à check
     * P to E
     * P to P
     * E to E
     * E to B
     * P to B
     * E to S
     * P to M
     */
    void checkAllCollid();
    void isLevelFinished();
    void moveAll();
public:
void gameLoop();
};


#endif // GAME_H
