/**
 * @file level.h
 * @brief Header file for class Level
 * @date 09/06/2023
 * @version 2.0
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <QPainter>
#include <string>
#include <vector>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>

#include "entity.h"
#include "enemy.h"
#include "standard.h"
#include "giant.h"
#include "accelerator.h"
#include "block.h"
#include "obstacle.h"
#include "spawner.h"
#include "money.h"
#include "despawner.h"
#include "typedef.h"
#include "tileset.h"

/**
 * @brief The Level class define a level of the game Charclo Brosse
 * Define with the Block list for platforms, displayed enemies, to appears enemies, spawners and dispawners by opening a level file in json.
 * @see Entity
 * @see Block
 * @see Enemy
 * @see Spawner
 * @see Despawner
 * @see <a href="https://doc.qt.io/qt-5/qfile.html" target="_blank">QFile</a>
 * @see <a href="https://doc.qt.io/qt-6/qstring.html" target="_blank">QString</a>
 * @see <a href="https://doc.qt.io/qt-6/qjsondocument.html" target="_blank">QJsonDocument</a>
 * @see <a href="https://doc.qt.io/qt-6/qjsonobject.html" target="_blank">QJsonObject</a>
 * @see <a href="https://doc.qt.io/qt-6/qjsonvalue.html" target="_blank">QJsonValue</a>
 * @see <a href="https://doc.qt.io/qt-6/qjsonarray.html" target="_blank">QJsonArray</a>
 */
class Level
{
private:
    /**
     * @brief itsId the id of the level
     */
    unsigned short itsId;

    /**
     * @brief itsMinDelay the minimum delay before an enemy to appears
     */
    unsigned short itsMinDelay;

    /**
     * @brief itsMaxDelay the maximum delay before an enemy to appears
     */
    unsigned short itsMaxDelay;

    /**
     * @brief itsLevelFile the path to the level file
     */
    std::string itsLevelFile;

    /**
     * @brief itsBlockList the list of all blocks that compose the level
     */
    std::vector<Block *> itsBlockList;

    /**
     * @brief itsEnemiesList the list all the displayed enemies
     */
    std::vector<Enemy *> itsEnemiesList;

    /**
     * @brief itsRemainingEnemies the list all all the enemies in wait to appears
     */
    std::vector<Enemy *> itsRemainingEnemies;

    /**
     * @brief itsSpawnerList the list of the spawner for the apparition point of the enemies
     */
    std::vector<Spawner *> itsSpawnerList;

    /**
     * @brief itsDespawnerList the list of the dispawner to teleport the enemies at the top of the level
     */
    std::vector<Despawner *> itsDespawnerList;

    /**
     * @brief itsMoneyList the list of the money that the player can collect
     */
    std::vector<Money *> itsMoneyList;

    /**
     * @brief itsEnemyAppearsTimes the delay before the papparition of all the enemies
     */
    std::vector<unsigned short> itsEnemyAppearsTimes;

    /**
     * @brief itsEnemyAppearsSides the side of apparition for all the enemies
     */
    std::vector<Sides> itsEnemyAppearsSides;

    /**
     * @brief itsTimerTime the time to end the level
     */
    int itsTimerTime;

    /**
     * @brief active tell if the level is displayed
     */
    bool active;

public:
    /**
     * @brief Level the constructor of the Level class
     * @param levelFilePath the path to the level file (json)
     * @param tileSet the tileSet wich is used in the level (theme)
     */
    Level(std::string levelFilePath, TileSet * tileSet);

    /**
     * @brief getItsBlockList getter for itsBlockList
     * @return the list of all blocks
     * @see Level::itsBlockList
     */
    std::vector<Block *> getItsBlockList() const;

    /**
     * @brief getItsEnemiesList gettter for itsEnemiesList
     * @return the list of all the displayed enemies
     * @see Level::itsEnemiesList
     */
    std::vector<Enemy *> getItsEnemiesList() const;

    /**
     * @brief getItsSpawnerList getter for  itsSpawnerList
     * @return the list containing the left and right spawners
     * @see Level::itsSpawnerList
     */
    std::vector<Spawner *> getItsSpawnerList() const;

    /**
     * @brief getItsDespawnerList getter for itsDespawnerList
     * @return the list containing left and right dispawners
     * @see Level::itsDespawnerList
     */
    std::vector<Despawner *> getItsDespawnerList() const;

    /**
     * @brief display display all the entities of the level that have to be displayed
     * @param painter
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html>QPainter</a>
     */
    void display(QPainter * painter);
    /**
     * @brief removeEnemy remove an enemy from the level
     * @param enemy the enemy to remove
     */
    void removeEnemy(Enemy * enemy);
    /**
     * @brief removes the money collected
     * @param The concerned money
     */
    void removeMoney(Money * money);
    /**
     * @brief getItsId gets the id/number of the level
     * @return the number of the level
     */
    unsigned short getItsId() const;
    /**
     * @brief getItsMinDelay get the minimum delay of apparition of an enemy
     * @return the minimum delay
     */
    unsigned short getItsMinDelay() const;
    /**
     * @brief getItsMaxDelay get the maximum delay of apparition of an enemy
     * @return the maximum delay
     */
    unsigned short getItsMaxDelay() const;
    /**
     * @brief getItsEnemyAppearsTimes get the delay before the apparition of all the ramainings enemies
     * @return teh list of delay
     */
    std::vector<unsigned short> getItsEnemyAppearsTimes() const;
    /**
     * @brief getItsEnemyAppearsSides gets the sides of apparition of all the reamainings enemies
     * @return
     */
    std::vector<Sides> getItsEnemyAppearsSides() const;
    /**
     * @brief getItsRemainingEnemies get the enemies in wait to appears
     * @return the list of ramainings ennemies
     */
    std::vector<Enemy *> getItsRemainingEnemies() const;
    /**
     * @brief appears brings up an enemy
     * @param enemy the enemy to brings up
     */
    void appears(Enemy * enemy);
    /**
     * @brief activate set the level as activated
     */
    void activate();
    /**
     * @brief isActive get the state of the level
     * @return true if the level is active, false else
     */
    bool isActive();
    /**
     * @brief desactivate set the level as inactive
     */
    void desactivate();
    /**
     * @brief getItsTimerTime get the time to end the level
     * @return the time in secondes
     */
    int getItsTimerTime() const;
    /**
     * @brief getItsMoneyList get the list of moneys in the level
     * @return the list of the moneys
     */
    std::vector<Money *> getItsMoneyList() const;
};

#endif // LEVEL_H
