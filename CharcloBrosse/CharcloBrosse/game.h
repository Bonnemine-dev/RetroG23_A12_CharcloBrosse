/**
 * @file game.h
 * @brief Header file for class Game
 * @author Arthur Ancien
 * @date 09/06/2023
 * @version 1.7
 */

#ifndef GAME_H
#define GAME_H
#include <chrono>
#include <vector>
#include <QRect> // Corrigé
#include <QTimer>

#include "player.h"
#include "hmi.h"
#include "tileset.h"
#include "level.h"
#include "money.h"


//#include "DB_Score.h"

/**
 * @class Game
 * @brief Class that represents a game, with all the
 * necessary attributes and all the necessary methods
 * to play. from the beginning to the end of the game.
 * @date June 2023
 * @author Arthur ANCIEN
 */
class Game : public QObject{

    Q_OBJECT

private:
    /**
     * @brief Pointer to the TileSet object used in the game.
     */
    TileSet* itsTileSet;
    /**
     * @brief Pointer to the Player object representing the player in the game.
     */
    Player* itsPlayer;
    /**
     * @brief Game score.
     */
    unsigned int itsScore=0;
    /**
     * @brief Money amount in the wallet.
     */
    unsigned int itsMoney=0;
    /**
     * @brief Pointer to the Level object representing the current level of the game.
     */
    Level* itsLevel;
    /**
     * @brief Pointer to the HMI (Human-Machine Interface) object used in the game.
     */
    HMI* itsHMI;

    bool isInPause;

    double itsEllapsedTime;

    unsigned short int itsLoopCounter;

    /**
     * @brief currentLevel the current level number
     */
    short currentLevel;

    /**
     * @brief currentTier the current money tier
     */
    short currentTier = 1;

    //    DB_Score itsDBScore;


    bool running;


    /**
    * @brief Boolean which represent the state of the BlockPOW, false if it is not hitted, true if it is hitted.
    */
    bool isBlockPOWHitted;

    QString cheminBG;

public :
    /**
     * @brief Checks all possible collisions in the current game state
     * and launches the appropriate functions
     */
    void checkAllCollid();
    /**
     * @brief Method launched when a player collides with an enemy
     * @param thePlayer the player concerned
     * @param theEnemy the enemy concerned
     */
    void colBtwPlayerAndEnemy(Player* thePlayer,Enemy* theEnemy);
    /**
     * @brief Method launched when an enemy collides with an other enemy
     * @param theFirstEnemy one of the enemies concerned
     * @param theSecondEnemy the other enemies concerned
     */
    void colBtwEnemyAndEnemy(Enemy* theFirstEnemy, Enemy* theSecondEnemy);
    /**
     * @brief Method launched when an enemy collides with a block
     * @param theEnemy the enemy concerned
     * @param theBlock the block concerned
     */
    void colBtwEnemyAndBlock(Enemy* theEnemy, Block* theBlock);
    /**
     * @brief Method launched when a player collides with a block
     * @param thePlayer the player concerned
     * @param theBlock the block concerned
     */
    void colBtwPlayerAndBlock(Player* thePlayer, Block* theBlock);
    /**
     * @brief Method launched when an enemy collides with a despawner
     * @param theEnemy the enemy concerned
     * @param theDespawner the despawner concerned
     */
    void colBtwEnemyAndDespawner(Enemy* theEnemy, Despawner* theDespawner);

    void colBtwPlayerAndObstacle(Player* thePlayer);

    /**
     * @brief Method launched when the player collides with an obstacle
     * @param thePlayer
     * @param theObstacle the obstacle concerned
     */
    void colBtwPlayerAndObstacle(Player* thePlayer,Obstacle* theObstacle);

    /**
     * @brief Method launched when the player collides with the bottom of a blockPOW.
     *
     * It switches the state of all enemies that are already on the game screen except enemies that are not on the ground.
     *
     * @param Player* thePlayer : A pointeur to the player in collid.
     * @param Block* theBLockPOW : A pointeur to the blocPOWr in collid.
     * @return void : No return.
     */
    void colBtwPlayerAndBlockPOW(Player* thePlayer, Block* theBLockPOW);

    /**
     * @brief Method launched when the player collides with money
     * @param thePlayer
     * @param theMoney the money concerned
     */
    void colBtwPlayerAndMoney(Player* thePlayer, Money* theMoney);




    /**
     * @brief checks whether a level is finished. If the player has no more lives
     * or if there are no more enemies to appear.
     * @return true if the level are finished, false else.
     */
    bool isLevelFinished();
    /**
     * @brief launch player and enemy move methods.
     */
    void moveAll();

    bool isOnTop(Entity * entity1, Entity * entity2);

    bool collid(Entity * entity1, Entity * entity2);

    /**
     * @brief The constructor for the "Game" class
     */
    Game();
    /**
     * @brief Fonction appelée lorsque la touche gauche est enfoncée.
     */
    void onLeftKeyPressed();
    /**
     * @brief Fonction appelée lorsque la touche droite est enfoncée.
     */
    void onRightKeyPressed();
    /**
     * @brief Fonction appelée lorsque la touche haut est enfoncée.
     */
    void onUpKeyPressed();
    /**
     * @brief Fonction appelée lorsque la touche gauche est relâchée.
     */
    void onLeftKeyReleased();
    /**
     * @brief Fonction appelée lorsque la touche droite est relâchée.
     */
    void onRightKeyReleased();
    /**
     * @brief Fonction appelée lorsque le jeu est mis en pause.
     */
    void onGamePaused();
    /**
     * @brief Fonction appelée lorsque le jeu reprend après avoir été mis en pause.
     */
    void onGameResumed();

    /**
     * @brief onGameStart start the Game
     * Start a party at the first level with 3 lives and a score of zero
     */
    void onGameStart();

    int checkTier();
    /**
     * @brief openLevel open a level file and parse it
     * Open the current level file to get the level info and display it
     */
    void openLevel();

    /**
     * @brief levelTimeout when the time to do the level is ellapsed
     * end the game when the time is ellapsed
     */
    void levelTimeout();

    unsigned int getItsScore() const;

    Player *getItsPlayer() const;

    unsigned int getItsMoney() const;
    void setItsMoney(unsigned int newItsMoney);

    /**
     * @brief spawnPlayer set the player position to spawn
     */
    void spawnPlayer();


    TileSet *getItsTileSet() const;

    QString getCheminBG() const;

    short getCurrentTier() const;

public slots:
    /**
     * @brief corresponds to the game loop, depending on the time the player is not dead.
     */
    void gameLoop();
};


#endif // GAME_H
