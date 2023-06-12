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

    //    DB_Score itsDBScore;

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

    void onGameStart();

    unsigned int getItsScore() const;

    Player *getItsPlayer() const;

public slots:
    /**
     * @brief corresponds to the game loop, depending on the time the player is not dead.
     */
    void gameLoop();
};


#endif // GAME_H
