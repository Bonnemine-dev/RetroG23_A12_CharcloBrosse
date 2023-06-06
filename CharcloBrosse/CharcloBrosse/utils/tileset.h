/**
 * @file tileset.h
 * @brief Header file for class Tileset
 * @author Melvin WARNET
 * @date 05/06/2023
 * @version 1.1
 */
#ifndef TILESET_H
#define TILESET_H

#include <QPixmap>
#include <string>


/**
 * @class Tileset class
 * @brief The Tileset class generate and stock all images of the game
 * Functions of Tileset class give access to images wanted. Reed documentation to know how to get a specified image.
 */
class TileSet
{
private:
    QPixmap* itsPlayerTile; /**< The image of the Player */
    QPixmap* itsBlockTilesList[2]; /**< The array that contains images of a Block, [0] for Block in normal state image, [1] for Block in hit state image. */
    QPixmap* itsGroundTile; /**< The image of a ground Block */
    QPixmap* itsEnemyTilesList[2]; /**< The array that contains images of an Enemy, [0] for Enemy in normal state image, [1] for Enemy in hit state image. */
    QPixmap* itsSpawnerTilesList[2]; /**< The array that contains images of a Spawner, [0] for left Spawner image, [1] for right Spawner image. */
    QPixmap* itsDespawnerTilesList[2]; /**< The array that contains images of a Despawner, [0] for left Despawner image, [1] for right Despawner image. */
public:
    /**
     * @brief Tileset class constructor declaration
     * Generate and stock all images from the file specified
     * @param string aFilePath : The path to the file which contains all images (tileset)
     */
    TileSet(std::string aFilePath);

    /**
     * @brief Tileset::getItsPlayerTile() function declaration
     * @return QPixmap* : A pointer to the image of the Player
     */
    QPixmap* getItsPlayerTile();

    /**
     * @brief Tileset::getItsBlockTile() function declaration
     * @return QPixmap* : A pointer to the image of a Block in a normal state
     */
    QPixmap* getItsBlockTile();

    /**
     * @brief Tileset::getItsBlockHitTile() function declaration
     * @return QPixmap* : A pointer to the image of a Block in a hit state
     */
    QPixmap* getItsBlockHitTile();

    /**
     * @brief Tileset::getItsGroundTile() function declaration
     * @return QPixmap* : A pointer to the image of a ground Block
     */
    QPixmap* getItsGroundTile();

    /**
     * @brief Tileset::getItsEnemyTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy in normal state
     */
    QPixmap* getItsEnemyTile();

    /**
     * @brief Tileset::getItsEnemyHitTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy in hit state
     */
    QPixmap* getItsEnemyHitTile();

    /**
     * @brief Tileset::getItsSpawnerTile(unsigned short index) function declaration
     * @param unsigned short index : The index of the image you want, index=[0] for left Spawner image, index=[1] for right Spawner image
     * @return QPixmap* : A pointer to the image of a Spawner specified
     */
    QPixmap* getItsSpawnerTile(unsigned short index);

    /**
     * @brief Tileset::getItsDespawnerTile(unsigned short index) function declaration
     * @param unsigned short index : The index of the image you want, index=[0] for left Despawner image, index=[1] for right Despawner image
     * @return QPixmap* : A pointer to the image of a Despawner specified
     */
    QPixmap* getItsDespawnerTile(unsigned short index);
};

#endif // TILESET_H
