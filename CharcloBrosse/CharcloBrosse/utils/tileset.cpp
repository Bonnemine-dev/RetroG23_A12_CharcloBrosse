/**
 * @file tileset.cpp
 * @brief Source file for class Tileset
 * @author Melvin WARNET
 * @date 05/06/2023
 * @version 1.1
 */
#include "tileset.h"
#include <ostream>


/**
 * @brief Tileset class constructor implementation
 * Generate and stock all images from the file specified
 * @param string aFilePath : The path to the file which contains all images (tileset)
 */
TileSet::TileSet(const std::string aFilePath)
{
    //< Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre
    QString filePath = QString::fromStdString(aFilePath);
    QPixmap tileset(filePath);
    //> Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre

    //< Vérification de l'ouverture du fichier et lancement d'une exception si non
    if(tileset.isNull())
    {
       throw std::string("File unfound (Tileset::Tileset(const std::string aFilePath)");
    }
    else
    {
        //< Chargement et stockage de chaque image une par une en précisant leur position et leur taille (possibilité de mettre des constantes à termes)
        itsPlayerTile = new QPixmap(tileset.copy(9, 97, 32, 64));
        itsGroundTile = new QPixmap(tileset.copy(97, 9, 32, 32));
        itsBlockTilesList[0] = new QPixmap(tileset.copy(9, 9, 32, 32));
        itsBlockTilesList[1] = new QPixmap(tileset.copy(53, 9, 32, 32));
        itsEnemyTilesList[0] = new QPixmap(tileset.copy(9, 53, 32, 32));
        itsEnemyTilesList[1] = new QPixmap(tileset.copy(53, 53, 32, 32));
        itsSpawnerTilesList[0] = new QPixmap(tileset.copy(9, 174, 64, 96));
        itsSpawnerTilesList[1] = new QPixmap(tileset.copy(73, 174, 64, 96));
        itsDespawnerTilesList[0] = new QPixmap(tileset.copy(137, 174, 64, 96));
        itsDespawnerTilesList[1] = new QPixmap(tileset.copy(201, 174, 64, 96));
        //> Chargement et stockage de chaque image une par une en précisant leur position et leur taille (possibilité de mettre des constantes à termes)
    }
    //> Vérification de l'ouverture du fichier et lancement d'une exception si non
}

/**
 * @brief Tileset::getItsPlayerTile() function implementation
 * @return QPixmap* : A pointer to the image of the Player
 */
QPixmap* TileSet::getItsPlayerTile()
{
    return itsPlayerTile;
}

/**
 * @brief Tileset::getItsBlockTile() function implementation
 * @return QPixmap* : A pointer to the image of a Block in a normal state
 */
QPixmap* TileSet::getItsBlockTile()
{
    return itsBlockTilesList[0];
}

/**
 * @brief Tileset::getItsBlockHitTile() function implementation
 * @return QPixmap* : A pointer to the image of a Block in a hit state
 */
QPixmap* TileSet::getItsBlockHitTile()
{
    return itsBlockTilesList[1];
}

/**
 * @brief Tileset::getItsGroundTile() function implementation
 * @return QPixmap* : A pointer to the image of a ground Block
 */
QPixmap *TileSet::getItsGroundTile()
{
    return itsGroundTile;
}

/**
 * @brief Tileset::getItsEnemyTile() function implementation
 * @return QPixmap* : A pointer to the image of an Enemy in normal state
 */
QPixmap* TileSet::getItsEnemyTile()
{
    return itsEnemyTilesList[0];
}

/**
 * @brief Tileset::getItsEnemyHitTile() function implementation
 * @return QPixmap* : A pointer to the image of an Enemy in hit state
 */
QPixmap* TileSet::getItsEnemyHitTile()
{
    return itsEnemyTilesList[1];
}

/**
 * @brief Tileset::getItsSpawnerTile(unsigned short index) function implementation
 * @param unsigned short index : The index of the image you want, index=[0] for left Spawner image, index=[1] for right Spawner image
 * @return QPixmap* : A pointer to the image of a Spawner specified
 */
QPixmap* TileSet::getItsSpawnerTile(unsigned short index)
{
    return itsSpawnerTilesList[index];
}

/**
 * @brief Tileset::getItsDespawnerTile(unsigned short index) function implementation
 * @param unsigned short index : The index of the image you want, index=[0] for left Despawner image, index=[1] for right Despawner image
 * @return QPixmap* : A pointer to the image of a Despawner specified
 */
QPixmap *TileSet::getItsDespawnerTile(unsigned short index)
{
    return itsDespawnerTilesList[index];
}

