/**
 * @file tileset.h
 * @brief Header file for class TileSet
 * @date 05/06/2023
 * @version 2.0
 */
#ifndef TILESET_H
#define TILESET_H

#include <QPixmap>
#include <string>
#include <array>


/**
 * @class TileSet class
 * @brief The TileSet class generate and stock all images of the game
 * Functions of TileSet class give access to images wanted. Reed documentation to know how to get a specified image.
 */
class TileSet
{
private:
    /**
     * @brief itsPlayerTilesList the player sprites list
     */
    static std::array<QPixmap*, 12> itsPlayerTilesList;
    /**
     * @brief itsEnnemyStandardTilesList the standard enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyStandardTilesList;
    /**
     * @brief itsEnnemyAcceleratorTilesList the accelerator enemy sprites
     */
    static std::array<std::array<QPixmap*, 12>*, 3> itsEnnemyAcceleratorTilesList;
    /**
     * @brief itsEnnemyGiantTilesList the giant enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyGiantTilesList;
    /**
     * @brief itsEnnemyJumperTilesList the jumper enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyJumperTilesList;
    /**
     * @brief itsEnnemyFreezerTilesList the freezer enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyFreezerTilesList;
    /**
     * @brief itsBlockTilesList the blocks sprites
     */
    static std::array<QPixmap*, 6> itsBlockTilesList;
    /**
     * @brief itsNoTextureTile texture with no sprites
     */
    static QPixmap *itsNoTextureTile;
    /**
     * @brief itsBackground the background
     */
    static QPixmap *itsBackground;
    /**
     * @brief itsMoneyTilesList the moneys sprites
     */
    static std::array<std::array<QPixmap*, 2>*, 3> itsMoneyTilesList;
    /**
     * @brief itsSpawnerTilesList the spawners sprites
     */
    static std::array<QPixmap*, 2> itsSpawnerTilesList;
    /**
     * @brief itsDespawnerTilesList the despawners sprites
     */
    static std::array<QPixmap*, 2> itsDespawnerTilesList;
public:
    /**
     * @brief Tileset class constructor declaration
     * Generate and stock all images from the file specified
     * @param string aFilePath : The path to the file which contains all images (tileset)
     */
    TileSet(std::string aTileSetFilePath);

    /**
     * @brief Tileset class destructor
     * delete all images in array
     */
    ~TileSet();

    /**
     * @brief Tileset::getItsNoTextureTile() function declaration
     * @return QPixmap* : A pointer to the the default image
     */
    QPixmap* getItsNoTextureTile();

    /**
     * @brief Tileset::getItsBackground() function declaration
     * @return QPixmap* : A pointer to the background image
     */
    QPixmap* getItsBackground();
    /**
     * @brief getItsPlayerTilesList gets itsPlayerList
     * @return the list of all the player sprites
     */
    std::array<QPixmap *, 12> *getItsPlayerTilesList();
    /**
     * @brief getItsEnnemyStandardTilesList gets itsEnemyStandardTilesList
     * @return the list of all the standard enemy sprites
     */
    std::array<QPixmap *, 12> *getItsEnnemyStandardTilesList();
    /**
     * @brief getItsEnnemyAcceleratorTilesList get itsEnemyAcceleratorTilesList
     * @return the list of all the accelerator enemy sprites
     */
    std::array<std::array<QPixmap *, 12> *, 3> *getItsEnnemyAcceleratorTilesList();
    /**
     * @brief getItsEnnemyGiantTilesList gets itsEnemyGiantTilesList
     * @return the lits of all the Giant enemy sprites
     */
    std::array<QPixmap *, 12> *getItsEnnemyGiantTilesList();
    /**
     * @brief getItsEnnemyJumperTilesList
     * @return
     */
    std::array<QPixmap *, 12> *getItsEnnemyJumperTilesList();
    /**
     * @brief getItsEnnemyFreezerTilesList
     * @return
     */
    std::array<QPixmap *, 12> *getItsEnnemyFreezerTilesList();
    /**
     * @brief getItsBlockTilesList gets itsBlockTilesList
     * @return the list of all the blocks sprites
     */
    std::array<QPixmap *, 6> *getItsBlockTilesList();
    /**
     * @brief getItsMoneyTilesList gets itsMoneyTilesList
     * @return the list of all the moneys sprites
     */
    std::array<std::array<QPixmap *, 2> *, 3> *getItsMoneyTilesList();
    /**
     * @brief getItsSpawnerTilesList gets itsSpawnerTilesList
     * @return the list of all the spawners sprites
     */
    std::array<QPixmap *, 2> *getItsSpawnerTilesList();
    /**
     * @brief getItsDespawnerTilesList gets itsDespawnerTilesList
     * @return the list of all the despawners sprites
     */
    std::array<QPixmap *, 2> *getItsDespawnerTilesList();

};

#endif // TILESET_H
