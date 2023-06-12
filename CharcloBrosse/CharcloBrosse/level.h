/**
 * @file level.h
 * @brief Header file for class Level
 * @author Kevin Simon
 * @date 09/06/2023
 * @version 1.5
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
#include "spawner.h"
#include "despawner.h"
#include "typedef.h"
#include "tileset.h"


enum Sides{
    LEFT = 0,
    RIGHT = 1,
};
/**
 * @brief The Level class define a level of the game Charclo Brosse
 * Define with the Block list for platforms, displayed enemies, to appears enemies, spawners and dispawners.
 * @see Entity
 * @see Block
 * @see Enemy
 * @see Spawner
 * @see Despawner
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
     * @brief itsEnemyAppearsTimes the delay before the papparition of all the enemies
     */
    std::vector<unsigned short> itsEnemyAppearsTimes;

    /**
     * @brief itsEnemyAppearsSides the side of apparition for all the enemies
     */
    std::vector<Sides> itsEnemyAppearsSides;

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
     */
    void display(QPainter * painter);
    void removeEnemy(Enemy * enemy);
    unsigned short getItsId() const;
    unsigned short getItsMinDelay() const;
    unsigned short getItsMaxDelay() const;
    std::vector<unsigned short> getItsEnemyAppearsTimes() const;
    std::vector<Sides> getItsEnemyAppearsSides() const;
    std::vector<Enemy *> getItsRemainingEnemies() const;
    void appears(Enemy * enemy);
    void activate();
    bool isActive();
    void desactivate();
};

#endif // LEVEL_H
