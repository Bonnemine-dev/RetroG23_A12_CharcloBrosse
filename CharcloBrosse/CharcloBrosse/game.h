/**
 * @file game.h
 * @brief Header file for class Game
 * @date 09/06/2023
 * @version 2.0
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
 * @see TileSet
 * @see Player
 * @see Level
 * @see HMI
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-6/qstring.html" target="_blank">QString</a>
 */
class Game : public QObject{

    Q_OBJECT

private:
    /**
     * @brief The combo that is involed when the player does multiple kills in a raw
     */
    unsigned short itsCombo = 0;
    /**
     * @brief The path of the tilset of the current tier
     */
    std::string tileSetPath;
    /**
     * @brief Pointer to the TileSet object used in the game.
     * @see TileSet
     */
    TileSet* itsTileSet;
    /**
     * @brief Pointer to the Player object representing the player in the game.
     * @see Player
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
     * @see Level
     */
    Level* itsLevel = nullptr;
    /**
     * @brief Pointer to the HMI (Human-Machine Interface) object used in the game.
     * @see HMI
     */
    HMI* itsHMI;

    /**
     * @brief isInPause cuurent pause state of the game
     */
    bool isInPause;

    /**
     * @brief itsEllapsedTime the ellapsed time since the mast appirtion of an enemy
     */
    double itsEllapsedTime;

    /**
     * @brief itsLoopCounter the current number of loop pased
     */
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

    /**
     * @brief running the current state of the game (running : a party has stared)
     */
    bool running;

    /**
    * @brief Boolean which represent the state of the BlockPOW, false if it is not hitted, true if it is hitted.
    */
    bool isBlockPOWHitted;

    /**
     * @brief cheminBG the path to the current backgroud
     * @see @see <a href="https://doc.qt.io/qt-6/qstring.html" target="_blank">QString</a>
     */
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
     * @see Player
     * @see Enemy
     */
    void colBtwPlayerAndEnemy(Player* thePlayer,Enemy* theEnemy);
    /**
     * @brief Method launched when an enemy collides with an other enemy
     * @param theFirstEnemy one of the enemies concerned
     * @param theSecondEnemy the other enemies concerned
     * @see Enemy
     */
    void colBtwEnemyAndEnemy(Enemy* theFirstEnemy, Enemy* theSecondEnemy);
    /**
     * @brief Method launched when an enemy collides with a block
     * @param theEnemy the enemy concerned
     * @param theBlock the block concerned
     * @see Enemy
     * @see Block
     */
    void colBtwEnemyAndBlock(Enemy* theEnemy, Block* theBlock);
    /**
     * @brief Method launched when a player collides with a block
     * @param thePlayer the player concerned
     * @param theBlock the block concerned
     * @see Player
     * @see Block
     */
    void colBtwPlayerAndBlock(Player* thePlayer, Block* theBlock);
    /**
     * @brief Method launched when an enemy collides with a despawner
     * @param theEnemy the enemy concerned
     * @param theDespawner the despawner concerned
     * @see Enemy
     * @see DespawnerS
     */
    void colBtwEnemyAndDespawner(Enemy* theEnemy, Despawner* theDespawner);

    /**
     * @brief Method launched when the player collides with an obstacle
     * @param thePlayer the player concerned
     * @see Player
     */
    void colBtwPlayerAndObstacle(Player* thePlayer);

    /**
     * @brief Method launched when the player collides with the bottom of a blockPOW.
     *
     * It switches the state of all enemies that are already on the game screen except enemies that are not on the ground.
     *
     * @param Player* thePlayer : A pointeur to the player in collid.
     * @param Block* theBLockPOW : A pointeur to the blocPOWr in collid.
     * @return void : No return.
     * @see Player
     * @see Block
     */
    void colBtwPlayerAndBlockPOW(Player* thePlayer, Block* theBLockPOW);

    /**
     * @brief Method launched when the player collides with money
     * @param theMoney the money concerned
     * @see Money
     */
    void colBtwPlayerAndMoney(Money* theMoney);




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

    /**
     * @brief isOnTop checks if an entity is on top of another
     * @param entity1 the entity to verify is is on top
     * @param entity2 the other entity
     * @return true if the first entity is on top of the second
     */
    bool isOnTop(Entity * entity1, Entity * entity2);

    /**
     * @brief collid checks if two entities are colliding
     * @param entity1 the first entity
     * @param entity2 the second entity
     * @return true is the entites are colliding
     */
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

    /**
     * @brief getItsScore get the current score of the game
     * @return the score
     */
    unsigned int getItsScore() const;

    /**
     * @brief getItsPlayer get the current player
     * @return  the player
     * @see Player
     */
    Player *getItsPlayer() const;

    /**
     * @brief getItsMoney get the current amout of money
     * @return the amout of money earned
     */
    unsigned int getItsMoney() const;
    /**
     * @brief setItsMoney set the current amount of money
     * @param newItsMoney the new amount of money
     */
    void setItsMoney(unsigned int newItsMoney);

    /**
     * @brief spawnPlayer set the player position to spawn
     */
    void spawnPlayer();

    /**
     * @brief getItsTileSet gets the current tileSet (theme)
     * @return the tileset
     * @see tileSet
     */
    TileSet *getItsTileSet() const;

    /**
     * @brief getCheminBG get the path to the current background
     * @return the path
     * @see <a href="https://doc.qt.io/qt-6/qstring.html" target="_blank">QString</a>
     */
    QString getCheminBG() const;

    /**
     * @brief getCurrentTier gets the current multiplier of the score
     * @return the multiplier
     */
    short getCurrentTier() const;

    /**
     * @brief getItsCombo gets the current combo
     * @return the combo
     */
    unsigned short getItsCombo() const;

public slots:
    /**
     * @brief corresponds to the game loop, depending on the time the player is not dead.
     */
    void gameLoop();
};


#endif // GAME_H
