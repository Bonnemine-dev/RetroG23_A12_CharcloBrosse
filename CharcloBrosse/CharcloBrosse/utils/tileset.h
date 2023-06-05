
#ifndef TILESET_H
#define TILESET_H

#include <QPixmap>
#include <string>





class TileSet
{
private:
    std::string itsFilePath;
    QPixmap itsPLayerTile;
    QPixmap itsBlockTilesList[2][1];
    QPixmap itsEnemyTilesList[2][1];
    QPixmap itsSpawnerTilesList[2][1];
    QPixmap itsDespawnerTilesList[2][1];
public:
    TileSet(std::string aFilePath);
    QPixmap getItsPlayerTile();
    QPixmap getItsBlockTile();
    QPixmap getItsBlockHitTile();
    QPixmap getItsEnemyTile();
    QPixmap getItsEnemyHitTile();
    QPixmap getItsSpawnerTile(int index);
    QPixmap getItsDespawnerTile(int index);
};

#endif // TILESET_H
