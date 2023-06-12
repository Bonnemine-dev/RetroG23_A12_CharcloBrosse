/**
 * @file tileset.cpp
 * @brief Source file for class Tileset
 * @author Melvin WARNET
 * @date 05/06/2023
 * @version 1.2
 */

#include <ostream>

#include "tileset.h"


/**
 * @brief Tileset class constructor implementation
 * Generate and stock all images from the file specified
 * @param string aFilePath : The path to the file which contains all images (tileset)
 */
TileSet::TileSet(std::string aTileSetFilePath, std::string aBackgroundFilePath)
{
    //< Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre
    QString tileSetFilePath = QString::fromStdString(aTileSetFilePath);
    QPixmap tileset(tileSetFilePath);
    //> Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre

    //< Vérification de l'ouverture du fichier et lancement d'une exception si non
    if(tileset.isNull())
    {
       throw std::string("Tileset file unfound (Tileset::Tileset(const std::string aFilePath)");
    }
    else
    {
        //< Chargement et stockage de chaque image une par une en précisant leur position et leur taille (possibilité de mettre des constantes à termes)
        // Charclo court
        itsPlayerTilesList[0][0] = new QPixmap(tileset.copy(1, 2, 32, 64));
        itsPlayerTilesList[0][1] = new QPixmap(tileset.copy(34, 2, 32, 64));
        // Charclo saute
        itsPlayerTilesList[1][0] = new QPixmap(tileset.copy(67, 2, 32, 64));
        itsPlayerTilesList[1][1] = nullptr;
        // Charclo frappe
        itsPlayerTilesList[2][0] = new QPixmap(tileset.copy(100, 2, 32, 64));
        itsPlayerTilesList[2][1] = new QPixmap(tileset.copy(133, 2, 32, 64));


        // Ennemi standard court
        itsEnemyTilesList[0][0][0] = new QPixmap(tileset.copy(1, 67, 32, 32));
        itsEnemyTilesList[0][0][1] = new QPixmap(tileset.copy(34, 67, 32, 32));
        // Ennemi standard tombe
        itsEnemyTilesList[0][1][0] = new QPixmap(tileset.copy(67, 67, 32, 32));
        itsEnemyTilesList[0][1][1] = nullptr;
        // Ennemi standard immobilisé
        itsEnemyTilesList[0][2][0] = new QPixmap(tileset.copy(100, 67, 32, 32));
        itsEnemyTilesList[0][2][1] = new QPixmap(tileset.copy(133, 67, 32, 32));


        // Ennemi accélérateur état1 court
        itsEnemyTilesList[1][0][0] = new QPixmap(tileset.copy(1, 100, 32, 32));
        itsEnemyTilesList[1][0][1] = new QPixmap(tileset.copy(34, 100, 32, 32));
        // Ennemi accélérateur état1 tombe
        itsEnemyTilesList[1][1][0] = new QPixmap(tileset.copy(67, 100, 32, 32));
        itsEnemyTilesList[1][1][1] = nullptr;
        // Ennemi accélérateur état1 immobilisé
        itsEnemyTilesList[1][2][0] = new QPixmap(tileset.copy(100, 100, 32, 32));
        itsEnemyTilesList[1][2][1] = new QPixmap(tileset.copy(133, 100, 32, 32));


        // Ennemi accélérateur état2 court
        itsEnemyTilesList[2][0][0] = new QPixmap(tileset.copy(1, 133, 32, 32));
        itsEnemyTilesList[2][0][1] = new QPixmap(tileset.copy(34, 133, 32, 32));
        // Ennemi accélérateur état2 tombe
        itsEnemyTilesList[2][1][0] = new QPixmap(tileset.copy(67, 133, 32, 32));
        itsEnemyTilesList[2][1][1] = nullptr;
        // Ennemi accélérateur état2 immobilisé
        itsEnemyTilesList[2][2][0] = new QPixmap(tileset.copy(100, 133, 32, 32));
        itsEnemyTilesList[2][2][1] = new QPixmap(tileset.copy(133, 133, 32, 32));


        // Ennemi accélérateur état2 court
        itsEnemyTilesList[3][0][0] = new QPixmap(tileset.copy(1, 166, 32, 32));
        itsEnemyTilesList[3][0][1] = new QPixmap(tileset.copy(34, 166, 32, 32));
        // Ennemi accélérateur état2 tombe
        itsEnemyTilesList[3][1][0] = new QPixmap(tileset.copy(67, 166, 32, 32));
        itsEnemyTilesList[3][1][1] = nullptr;
        // Ennemi accélérateur état2 immobilisé
        itsEnemyTilesList[3][2][0] = new QPixmap(tileset.copy(100, 166, 32, 32));
        itsEnemyTilesList[3][2][1] = new QPixmap(tileset.copy(133, 166, 32, 32));



        // Ennemi Giant court
        itsEnemyTilesList[4][0][0] = new QPixmap(tileset.copy(1, 199, 32, 96));
        itsEnemyTilesList[4][0][1] = new QPixmap(tileset.copy(34, 199, 32, 96));
        // Ennemi Giant tombe
        itsEnemyTilesList[4][1][0] = new QPixmap(tileset.copy(67, 199, 32, 96));
        itsEnemyTilesList[4][1][1] = nullptr;
        // Ennemi Giant immobilisé
        itsEnemyTilesList[4][2][0] = new QPixmap(tileset.copy(100, 199, 32, 96));
        itsEnemyTilesList[4][2][1] = new QPixmap(tileset.copy(133, 199, 32, 96));


        // Block normal
        itsBlockTilesList[0] = new QPixmap(tileset.copy(1, 296, 32, 32));
        // Block frappé
        itsBlockTilesList[1] = new QPixmap(tileset.copy(34, 296, 32, 32));

        // Block ground
        itsGroundTile = new QPixmap(tileset.copy(67, 296, 32, 32));

        // Obstacle
        itsObstacleTile = new QPixmap(tileset.copy(100, 296, 32, 32));

        // Block POW normal
        itsPOWTilesList[0] = new QPixmap(tileset.copy(1, 329, 32, 32));
        // Block POW frappé
        itsPOWTilesList[1] = new QPixmap(tileset.copy(34, 329, 32, 32));




        // Money rouge
        itsMoneyTilesList[0][0] = new QPixmap(tileset.copy(166, 100, 32, 32));
        itsMoneyTilesList[0][1] = new QPixmap(tileset.copy(199, 100, 32, 32));
        // Money jaune
        itsMoneyTilesList[1][0] = new QPixmap(tileset.copy(232, 100, 32, 32));
        itsMoneyTilesList[1][1] = new QPixmap(tileset.copy(265, 100, 32, 32));
        // Money billet
        itsMoneyTilesList[2][0] = new QPixmap(tileset.copy(298, 100, 32, 32));
        itsMoneyTilesList[2][1] = new QPixmap(tileset.copy(331, 100, 32, 32));

        // Spawner gauche
        itsSpawnerTilesList[0] = new QPixmap(tileset.copy(166, 2, 64, 96));
        // Spawner droite
        itsSpawnerTilesList[1] = new QPixmap(tileset.copy(231, 2, 64, 96));

        // Dispawner gauche
        itsDespawnerTilesList[0] = new QPixmap(tileset.copy(295, 2, 64, 96));
        // Dispawner droite
        itsDespawnerTilesList[1] = new QPixmap(tileset.copy(361, 2, 64, 96));

        // Texture par default
        itsNoTextureTile = new QPixmap(tileset.copy(1, 362, 32, 32));

        //> Chargement et stockage de chaque image une par une en précisant leur position et leur taille (possibilité de mettre des constantes à termes)
    }
    //> Vérification de l'ouverture du fichier et lancement d'une exception si non



    //< Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre
    QString backgroundFilePath = QString::fromStdString(aBackgroundFilePath);
    QPixmap background(backgroundFilePath);
    //> Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre

    //< Vérification de l'ouverture du fichier et lancement d'une exception si non
    if(background.isNull())
    {
       throw std::string("Background file unfound (Tileset::Tileset(const std::string aFilePath)");
    }
    else
    {
        // Chargement et stockage du background
        itsBackground = new QPixmap(background);
    }
    //> Vérification de l'ouverture du fichier et lancement d'une exception si non
}

QPixmap *TileSet::getItsPlayerRunningTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsPlayerTilesList[0][0];
    }
    else if (aFrame == 1)
    {
        return itsPlayerTilesList[0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsPlayerJumpingTile()
{
    return itsPlayerTilesList[1][0];
}

QPixmap *TileSet::getItsPlayerHittingTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsPlayerTilesList[2][0];
    }
    else if (aFrame == 1)
    {
        return itsPlayerTilesList[2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyStandardRunningTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[0][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[0][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyStandardJumpingTile()
{
    return itsEnemyTilesList[0][1][0];
}

QPixmap *TileSet::getItsEnemyStandardHittedTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[0][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[0][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}


QPixmap *TileSet::getItsEnemyAccelerator1RunningTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[1][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[1][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator1JumpingTile()
{
    return itsEnemyTilesList[1][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator1HittedTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[1][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[1][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator2RunningTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[2][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[2][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator2JumpingTile()
{
    return itsEnemyTilesList[2][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator2HittedTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[2][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[2][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator3RunningTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[3][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[3][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator3JumpingTile()
{
    return itsEnemyTilesList[3][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator3HittedTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[3][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[3][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyGiantRunningTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[4][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[4][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyGiantdJumpingTile()
{
    return itsEnemyTilesList[4][1][0];
}

QPixmap *TileSet::getItsEnemyGiantHittedTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyTilesList[4][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyTilesList[4][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
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
QPixmap* TileSet::getItsBlockHittedTile()
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

QPixmap *TileSet::getItsPOWBlockTile()
{
    return itsBlockTilesList[0];
}

QPixmap *TileSet::getItsPOWBlockHittedTile()
{
    return itsBlockTilesList[1];
}

QPixmap *TileSet::getItsObstacleTile()
{
    return itsObstacleTile;
}

QPixmap *TileSet::getItsRedCoinTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsMoneyTilesList[0][0];
    }
    else if (aFrame == 1)
    {
        return itsMoneyTilesList[0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsYellowCoinTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsMoneyTilesList[1][0];
    }
    else if (aFrame == 1)
    {
        return itsMoneyTilesList[1][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsBillTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsMoneyTilesList[2][0];
    }
    else if (aFrame == 1)
    {
        return itsMoneyTilesList[2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
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

QPixmap *TileSet::getItsNoTextureTile()
{
    return itsNoTextureTile;
}

QPixmap *TileSet::getItsBackground()
{
    return itsBackground;
}

