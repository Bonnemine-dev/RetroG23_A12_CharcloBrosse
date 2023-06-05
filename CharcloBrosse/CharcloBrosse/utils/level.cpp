
#include "level.h"

std::vector<Block *> Level::getItsBlockList() const
{
    return itsBlockList;
}

std::vector<Enemy *> Level::getItsEnemiesList() const
{
    return itsEnemiesList;
}

std::vector<Spawner *> Level::getItsSpawnerList() const
{
    return itsSpawnerList;
}

std::vector<Despawner *> Level::getItsDespawnerList() const
{
    return itsDespawnerList;
}

void Level::display(QPainter *painter)
{

}

void Level::removeEnemy(Enemy *)
{

}

Level::Level(std::string levelFilePath)
{

}

