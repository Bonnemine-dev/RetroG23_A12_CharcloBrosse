
#include "tileset.h"



TileSet::TileSet(std::string aFilePath)
{
    itsFilePath = aFilePath;
}

QPixmap TileSet::getItsPlayerTile()
{
    return itsPLayerTile;
}

QPixmap TileSet::getItsBlockTile()
{
    return itsBlockTilesList[0][0];
}

QPixmap TileSet::getItsBlockHitTile()
{
    return itsBlockTilesList[1][0];
}

QPixmap TileSet::getItsEnemyTile()
{
    return itsEnemyTilesList[0][0];
}

QPixmap TileSet::getItsEnemyHitTile()
{
    return itsEnemyTilesList[1][0];
}

QPixmap TileSet::getItsSpawnerTile(int index)
{
    return itsSpawnerTilesList[index][0];
}

QPixmap TileSet::getItsDespawnerTile(int index)
{
    return itsSpawnerTilesList[index][0];
}

