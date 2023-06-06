
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <Qrect>
#include "Entity/player.h"
#include "utils/hmi.h"
#include "utils/tileset.h"
#include "utils/level.h"
#include <chrono>

//#include "DB_Score.h"

/**
 * @brief The Game class
 */


class Game : public QObject{
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
    void colBtwPlayerAndEnemy(Player* thePlayer,Enemy* theEnemy);
    void colBtwEnemyAndEnemy(Enemy* theFirstEnemy, Enemy* theSecondEnemy);
    void colBtwEnemyAndBlock(Enemy* theEnemy, Block* theBlock);
    void colBtwPlayerAndBlock(Player* thePlayer, Block* theBlock);
    void colBtwEnemyAndSpawner(Enemy* theEnemy, Despawner* theDespawner);


    void gravity();
    bool isLevelFinished();
    void moveAll();
public:
    Game();
    void gameLoop();
public slots:
    void onLeftKeyPressed();
    void onRightKeyPressed();
    void onUpKeyPressed();
    void onLeftKeyReleased();
    void onRightKeyReleased();
    void onGamePaused();
    void onGameResumed();
};


#endif // GAME_H
