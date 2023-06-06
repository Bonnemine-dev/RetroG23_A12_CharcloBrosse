
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
#include "Entity/entity.h"
#include "Entity/Enemy/enemy.h"
#include "Entity/Enemy/standard.h"
#include "Entity/block.h"
#include "Spawner/spawner.h"
#include "Spawner/despawner.h"
#include "typedef.h"
#include "utils/tileset.h"
#include "Sprite/sprite.h"


enum Sides{
    LEFT,
    RIGHT,
};
/**
 * @brief The Level class define a level of the game Charclo Brosse
 * Define withthe Block list for platforms,
 */
class Level
{
private:
    unsigned short itsId;
    unsigned short itsMinDelay;
    unsigned short itsMaxDelay;
    std::string itsLevelFile;
    std::vector<Block *> itsBlockList;
    std::vector<Enemy *> itsEnemiesList;
    std::vector<Enemy *> itsRemainingEnemies;
    std::vector<Spawner *> itsSpawnerList;
    std::vector<Despawner *> itsDespawnerList;
    std::vector<unsigned short> itsEnemyAppearsTimes;
    std::vector<Sides> itsEnemyAppearsSides;
public:
    Level(std::string levelFilePath, TileSet * tileSet);

    std::vector<Block *> getItsBlockList() const;
    std::vector<Enemy *> getItsEnemiesList() const;
    std::vector<Spawner *> getItsSpawnerList() const;
    std::vector<Despawner *> getItsDespawnerList() const;

    void display(QPainter * painter);
    void removeEnemy(Enemy *);
    unsigned short getItsId() const;
    unsigned short getItsMinDelay() const;
    unsigned short getItsMaxDelay() const;
    std::vector<unsigned short> getItsEnemyAppearsTimes() const;
    std::vector<Sides> getItsEnemyAppearsSides() const;
    std::vector<Enemy *> getItsRemainingEnemies() const;
    void appears(Enemy * enemy);
};

#endif // LEVEL_H
