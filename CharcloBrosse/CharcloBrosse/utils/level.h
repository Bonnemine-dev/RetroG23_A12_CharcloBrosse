
#ifndef LEVEL_H
#define LEVEL_H

#include <QPainter>
#include <string>
#include <vector>
#include "Entity/entity.h"
#include "Entity/Enemy/enemy.h"
#include "Entity/Enemy/standard.h"
#include "Entity/block.h"
#include "Spawner/spawner.h"


class Level
{
private:
    std::string itsLevelFile;
    std::vector<Block *> itsBlockList;
    std::vector<Enemy *> itsEnemiesList;
    std::vector<Spawner *> itsSpawnerList;
    std::vector<Despawner *> itsDespawnerList;
public:
    Level(std::string levelFilePath);

    std::vector<Block *> getItsBlockList() const;
    std::vector<Enemy *> getItsEnemiesList() const;
    std::vector<Spawner *> getItsSpawnerList() const;
    std::vector<Despawner *> getItsDespawnerList() const;

    void display(QPainter * painter);
    void removeEnemy(Enemy *);
};

#endif // LEVEL_H
