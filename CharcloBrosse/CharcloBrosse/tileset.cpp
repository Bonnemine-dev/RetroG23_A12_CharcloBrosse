/**
 * @file tileset.cpp
 * @brief Source file for class Tileset
 * @author Melvin WARNET
 * @date 05/06/2023
 * @version 1.2
 */

#include <ostream>

#include "tileset.h"
#include <QDebug>

std::array<QPixmap*, 12> TileSet::itsPlayerTilesList;
std::array<QPixmap*, 12> TileSet::itsEnnemyStandardTilesList;
std::array<std::array<QPixmap*, 12>*, 3> TileSet::itsEnnemyAcceleratorTilesList;
std::array<QPixmap*, 12> TileSet::itsEnnemyGiantTilesList;
std::array<QPixmap*, 6> TileSet::itsBlockTilesList;
QPixmap* TileSet::itsNoTextureTile;
QPixmap* TileSet::itsBackground;
std::array<std::array<QPixmap*, 2>*, 3> TileSet::itsMoneyTilesList;
std::array<QPixmap*, 2> TileSet::itsSpawnerTilesList;
std::array<QPixmap*, 2> TileSet::itsDespawnerTilesList;

/**
 * @brief Tileset class constructor implementation
 * Generate and stock all images from the file specified
 * @param string aFilePath : The path to the file which contains all images (tileset)
 */

std::array<QPixmap *, 12> *TileSet::getItsPlayerTilesList()
{
    return &itsPlayerTilesList;
}

std::array<QPixmap *, 12> *TileSet::getItsEnnemyStandardTilesList()
{
    return &itsEnnemyStandardTilesList;
}

std::array<std::array<QPixmap *, 12> *, 3> *TileSet::getItsEnnemyAcceleratorTilesList()
{
    return &itsEnnemyAcceleratorTilesList;
}

std::array<QPixmap *, 12> *TileSet::getItsEnnemyGiantTilesList()
{
    return &itsEnnemyGiantTilesList;
}

std::array<QPixmap *, 6> *TileSet::getItsBlockTilesList()
{
    return &itsBlockTilesList;
}

std::array<std::array<QPixmap *, 2> *, 3> *TileSet::getItsMoneyTilesList()
{
    return &itsMoneyTilesList;
}

std::array<QPixmap *, 2> *TileSet::getItsSpawnerTilesList()
{
    return &itsSpawnerTilesList;
}

std::array<QPixmap *, 2> *TileSet::getItsDespawnerTilesList()
{
    return &itsDespawnerTilesList;
}

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
       //< Chargement et stockage de chaque image une par une en précisant leur position et leur taille (possibilité de mettre des constantes à termes
       // Pour l'inversion horizontale
       QTransform mirror;
       mirror.scale(-1, 1);

       // Charclo droite court
       itsPlayerTilesList.at(0) = new QPixmap(tileset.copy(1, 2, 32, 64));
       itsPlayerTilesList.at(1) = new QPixmap(tileset.copy(34, 2, 32, 64));
       // Charclo droite saute
       itsPlayerTilesList.at(2) = new QPixmap(tileset.copy(67, 2, 32, 64));
       itsPlayerTilesList.at(3) = new QPixmap(32, 64);//---------------------Crée un qpixmap rouge pour simuler qu'il ne bouge pas à changer
       itsPlayerTilesList.at(3)->fill(Qt::red);
       // Charclo droite frappe
       itsPlayerTilesList.at(4) = new QPixmap(tileset.copy(100, 2, 32, 64));
       itsPlayerTilesList.at(5) = new QPixmap(tileset.copy(133, 2, 32, 64));


       // Charclo gauche court
       itsPlayerTilesList.at(6) = new QPixmap(tileset.copy(1, 2, 32, 64).transformed(mirror));
       itsPlayerTilesList.at(7) = new QPixmap(tileset.copy(34, 2, 32, 64).transformed(mirror));
       // Charclo gauche saute
       itsPlayerTilesList.at(8) = new QPixmap(tileset.copy(67, 2, 32, 64).transformed(mirror));
       itsPlayerTilesList.at(9) = nullptr;
       // Charclo gauche frappe
       itsPlayerTilesList.at(10) = new QPixmap(tileset.copy(100, 2, 32, 64).transformed(mirror));
       itsPlayerTilesList.at(11) = new QPixmap(tileset.copy(133, 2, 32, 64).transformed(mirror));

       // Ennemi droit standard court  0
       // Ennemi droit standard court  1
       // Ennemi droite standard tombe 2
       // Rien                         3
       // Ennemi droite standard immobilisé 4
       // Ennemi droite standard immobilisé 5
       // Ennemi gauche standard court 6
       // Ennemi gauche standard court 7
       // Ennemi gauche standard tombe 8
       // Rien                         9
       // Ennemi gauche standard immobilisé 10
       // Ennemi gauche standard immobilisé 11

       // Ennemi droite standard court
       itsEnnemyStandardTilesList.at(0) = new QPixmap(tileset.copy(1, 67, 32, 32));
       itsEnnemyStandardTilesList.at(1) = new QPixmap(tileset.copy(34, 67, 32, 32));
       // Ennemi droite standard tombe
       itsEnnemyStandardTilesList.at(2) = new QPixmap(tileset.copy(67, 67, 32, 32));
       itsEnnemyStandardTilesList.at(3) = nullptr;
       // Ennemi droite standard immobilisé
       itsEnnemyStandardTilesList.at(4) = new QPixmap(tileset.copy(100, 67, 32, 32));
       itsEnnemyStandardTilesList.at(5) = new QPixmap(tileset.copy(133, 67, 32, 32));


       // Ennemi gauche standard court
       itsEnnemyStandardTilesList.at(6) = new QPixmap(tileset.copy(1, 67, 32, 32).transformed(mirror));
       itsEnnemyStandardTilesList.at(7) = new QPixmap(tileset.copy(34, 67, 32, 32).transformed(mirror));
       // Ennemi gauche standard tombe
       itsEnnemyStandardTilesList.at(8) = new QPixmap(tileset.copy(67, 67, 32, 32).transformed(mirror));
       itsEnnemyStandardTilesList.at(9) = nullptr;
       // Ennemi gauche standard immobilisé
       itsEnnemyStandardTilesList.at(10) = new QPixmap(tileset.copy(100, 67, 32, 32).transformed(mirror));
       itsEnnemyStandardTilesList.at(11) = new QPixmap(tileset.copy(133, 67, 32, 32).transformed(mirror));

       for (size_t i = 0; i < itsEnnemyAcceleratorTilesList.size(); i++)
       {
           itsEnnemyAcceleratorTilesList.at(i) = new std::array<QPixmap*, 12>;
       }

       // Ennemi droite accélérateur état1 court
       itsEnnemyAcceleratorTilesList.at(0)->at(0) = new QPixmap(tileset.copy(1, 100, 32, 32));
       itsEnnemyAcceleratorTilesList.at(0)->at(1) = new QPixmap(tileset.copy(34, 100, 32, 32));
       // Ennemi droite accélérateur état1 tombe
       itsEnnemyAcceleratorTilesList.at(0)->at(2) = new QPixmap(tileset.copy(67, 100, 32, 32));
       itsEnnemyAcceleratorTilesList.at(0)->at(3) = nullptr;
       // Ennemi droite accélérateur état1 immobilisé
       itsEnnemyAcceleratorTilesList.at(0)->at(4) = new QPixmap(tileset.copy(100, 100, 32, 32));
       itsEnnemyAcceleratorTilesList.at(0)->at(5) = new QPixmap(tileset.copy(133, 100, 32, 32));

       // Ennemi gauche accélérateur état1 court
       itsEnnemyAcceleratorTilesList.at(0)->at(6) = new QPixmap(tileset.copy(1, 100, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(0)->at(7) = new QPixmap(tileset.copy(34, 100, 32, 32).transformed(mirror));
       // Ennemi gauche accélérateur état1 tombe
       itsEnnemyAcceleratorTilesList.at(0)->at(8) = new QPixmap(tileset.copy(67, 100, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(0)->at(9) = nullptr;
       // Ennemi gauche accélérateur état1 immobilisé
       itsEnnemyAcceleratorTilesList.at(0)->at(10) = new QPixmap(tileset.copy(100, 100, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(0)->at(11) = new QPixmap(tileset.copy(133, 100, 32, 32).transformed(mirror));

       // Ennemi droite accélérateur état2 court
       itsEnnemyAcceleratorTilesList.at(1)->at(0) = new QPixmap(tileset.copy(1, 133, 32, 32));
       itsEnnemyAcceleratorTilesList.at(1)->at(1) = new QPixmap(tileset.copy(34, 133, 32, 32));
       // Ennemi droite accélérateur état2 tombe
       itsEnnemyAcceleratorTilesList.at(1)->at(2) = new QPixmap(tileset.copy(67, 133, 32, 32));
       itsEnnemyAcceleratorTilesList.at(1)->at(3) = nullptr;
       // Ennemi droite accélérateur état2 immobilisé
       itsEnnemyAcceleratorTilesList.at(1)->at(4) = new QPixmap(tileset.copy(100, 133, 32, 32));
       itsEnnemyAcceleratorTilesList.at(1)->at(5) = new QPixmap(tileset.copy(133, 133, 32, 32));

       // Ennemi gauche accélérateur état2 court
       itsEnnemyAcceleratorTilesList.at(1)->at(6) = new QPixmap(tileset.copy(1, 133, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(1)->at(7) = new QPixmap(tileset.copy(34, 133, 32, 32).transformed(mirror));
       // Ennemi gacuhe accélérateur état2 tombe
       itsEnnemyAcceleratorTilesList.at(1)->at(8) = new QPixmap(tileset.copy(67, 133, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(1)->at(9) = nullptr;
       // Ennemi gauche accélérateur état2 immobilisé
       itsEnnemyAcceleratorTilesList.at(1)->at(10) = new QPixmap(tileset.copy(100, 133, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(1)->at(11) = new QPixmap(tileset.copy(133, 133, 32, 32).transformed(mirror));


       // Ennemi droite accélérateur état3 court
       itsEnnemyAcceleratorTilesList.at(2)->at(0) = new QPixmap(tileset.copy(1, 166, 32, 32));
       itsEnnemyAcceleratorTilesList.at(2)->at(1) = new QPixmap(tileset.copy(34, 166, 32, 32));
       // Ennemi droite accélérateur état3 tombe
       itsEnnemyAcceleratorTilesList.at(2)->at(2) = new QPixmap(tileset.copy(67, 166, 32, 32));
       itsEnnemyAcceleratorTilesList.at(2)->at(3) = nullptr;
       // Ennemi droite accélérateur état3 immobilisé
       itsEnnemyAcceleratorTilesList.at(2)->at(4) = new QPixmap(tileset.copy(100, 166, 32, 32));
       itsEnnemyAcceleratorTilesList.at(2)->at(5) = new QPixmap(tileset.copy(133, 166, 32, 32));


       // Ennemi gauche accélérateur état3 court
       itsEnnemyAcceleratorTilesList.at(2)->at(6) = new QPixmap(tileset.copy(1, 166, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(2)->at(7) = new QPixmap(tileset.copy(34, 166, 32, 32).transformed(mirror));
       // Ennemi gauche accélérateur état3 tombe
       itsEnnemyAcceleratorTilesList.at(2)->at(8) = new QPixmap(tileset.copy(67, 166, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(2)->at(9) = nullptr;
       // Ennemi gauche accélérateur état3 immobilisé
       itsEnnemyAcceleratorTilesList.at(2)->at(10) = new QPixmap(tileset.copy(100, 166, 32, 32).transformed(mirror));
       itsEnnemyAcceleratorTilesList.at(2)->at(11) = new QPixmap(tileset.copy(133, 166, 32, 32).transformed(mirror));



       // Ennemi droite Giant court
       itsEnnemyGiantTilesList.at(0) = new QPixmap(tileset.copy(1, 199, 32, 96));
       itsEnnemyGiantTilesList.at(1) = new QPixmap(tileset.copy(34, 199, 32, 96));
       // Ennemi droite Giant tombe
       itsEnnemyGiantTilesList.at(2) = new QPixmap(tileset.copy(67, 199, 32, 96));
       itsEnnemyGiantTilesList.at(3) = nullptr;
       // Ennemi droite Giant immobilisé
       itsEnnemyGiantTilesList.at(4) = new QPixmap(tileset.copy(100, 199, 32, 96));
       itsEnnemyGiantTilesList.at(5) = new QPixmap(tileset.copy(133, 199, 32, 96));


       // Ennemi gauche Giant court
       itsEnnemyGiantTilesList.at(6) = new QPixmap(tileset.copy(1, 199, 32, 96).transformed(mirror));
       itsEnnemyGiantTilesList.at(7) = new QPixmap(tileset.copy(34, 199, 32, 96).transformed(mirror));
       // Ennemi gauche Giant tombe
       itsEnnemyGiantTilesList.at(8) = new QPixmap(tileset.copy(67, 199, 32, 96).transformed(mirror));
       itsEnnemyGiantTilesList.at(9) = nullptr;
       // Ennemi gauche Giant immobilisé
       itsEnnemyGiantTilesList.at(10) = new QPixmap(tileset.copy(100, 199, 32, 96).transformed(mirror));
       itsEnnemyGiantTilesList.at(11) = new QPixmap(tileset.copy(133, 199, 32, 96).transformed(mirror));


       // Block normal
       itsBlockTilesList.at(0) = new QPixmap(tileset.copy(1, 296, 32, 32));
       // Block frappé
       itsBlockTilesList.at(1) = new QPixmap(tileset.copy(34, 296, 32, 32));

       // Block ground
       itsBlockTilesList.at(2) = new QPixmap(tileset.copy(67, 296, 32, 32));

       // Obstacle
       itsBlockTilesList.at(3) = new QPixmap(tileset.copy(100, 296, 32, 32));

       // Block POW normal
       itsBlockTilesList.at(4) = new QPixmap(tileset.copy(1, 329, 32, 32));
       // Block POW frappé
       itsBlockTilesList.at(5) = new QPixmap(tileset.copy(34, 329, 32, 32));



       for (size_t i = 0; i < itsMoneyTilesList.size(); i++)
       {
           itsMoneyTilesList.at(i) = new std::array<QPixmap*, 2>;
       }

       // Money rouge
       itsMoneyTilesList.at(0)->at(0) = new QPixmap(tileset.copy(166, 100, 32, 32));
       itsMoneyTilesList.at(0)->at(1) = new QPixmap(tileset.copy(199, 100, 32, 32));
       // Money jaune
       itsMoneyTilesList.at(1)->at(0) = new QPixmap(tileset.copy(232, 100, 32, 32));
       itsMoneyTilesList.at(1)->at(1) = new QPixmap(tileset.copy(265, 100, 32, 32));
       // Money billet
       itsMoneyTilesList.at(2)->at(0) = new QPixmap(tileset.copy(298, 100, 32, 32));
       itsMoneyTilesList.at(2)->at(1) = new QPixmap(tileset.copy(331, 100, 32, 32));

       // Spawner gauche
       itsSpawnerTilesList.at(0) = new QPixmap(tileset.copy(166, 2, 64, 96));
       // Spawner droite
       itsSpawnerTilesList.at(1) = new QPixmap(tileset.copy(231, 2, 64, 96));

       // Dispawner gauche
       itsDespawnerTilesList.at(0) = new QPixmap(tileset.copy(295, 2, 64, 96));
       // Dispawner droite
       itsDespawnerTilesList.at(1) = new QPixmap(tileset.copy(361, 2, 64, 96));

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
    /*{
        //< Chargement et stockage de chaque image une par une en précisant leur position et leur taille (possibilité de mettre des constantes à termes
        // Pour l'inversion horizontale
        QTransform mirror;
        mirror.scale(-1, 1);

        // Charclo droite court
        itsPlayerRightTilesList[0][0] = new QPixmap(tileset.copy(1, 2, 32, 64));
        itsPlayerRightTilesList[0][1] = new QPixmap(tileset.copy(34, 2, 32, 64));
        // Charclo droite saute
        itsPlayerRightTilesList[1][0] = new QPixmap(tileset.copy(67, 2, 32, 64));
        itsPlayerRightTilesList[1][1] = nullptr;
        // Charclo droite frappe
        itsPlayerRightTilesList[2][0] = new QPixmap(tileset.copy(100, 2, 32, 64));
        itsPlayerRightTilesList[2][1] = new QPixmap(tileset.copy(133, 2, 32, 64));


        // Charclo gauche court
        itsPlayerLeftTilesList[0][0] = new QPixmap(tileset.copy(1, 2, 32, 64).transformed(mirror));
        itsPlayerLeftTilesList[0][1] = new QPixmap(tileset.copy(34, 2, 32, 64).transformed(mirror));
        // Charclo gauche saute
        itsPlayerLeftTilesList[1][0] = new QPixmap(tileset.copy(67, 2, 32, 64).transformed(mirror));
        itsPlayerLeftTilesList[1][1] = nullptr;
        // Charclo gauche frappe
        itsPlayerLeftTilesList[2][0] = new QPixmap(tileset.copy(100, 2, 32, 64).transformed(mirror));
        itsPlayerLeftTilesList[2][1] = new QPixmap(tileset.copy(133, 2, 32, 64).transformed(mirror));


        // Ennemi droite standard court
        itsEnemyRightTilesList[0][0][0] = new QPixmap(tileset.copy(1, 67, 32, 32));
        itsEnemyRightTilesList[0][0][1] = new QPixmap(tileset.copy(34, 67, 32, 32));
        // Ennemi droite standard tombe
        itsEnemyRightTilesList[0][1][0] = new QPixmap(tileset.copy(67, 67, 32, 32));
        itsEnemyRightTilesList[0][1][1] = nullptr;
        // Ennemi droite standard immobilisé
        itsEnemyRightTilesList[0][2][0] = new QPixmap(tileset.copy(100, 67, 32, 32));
        itsEnemyRightTilesList[0][2][1] = new QPixmap(tileset.copy(133, 67, 32, 32));


        // Ennemi gauche standard court
        itsEnemyLeftTilesList[0][0][0] = new QPixmap(tileset.copy(1, 67, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[0][0][1] = new QPixmap(tileset.copy(34, 67, 32, 32).transformed(mirror));
        // Ennemi gauche standard tombe
        itsEnemyLeftTilesList[0][1][0] = new QPixmap(tileset.copy(67, 67, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[0][1][1] = nullptr;
        // Ennemi gauche standard immobilisé
        itsEnemyLeftTilesList[0][2][0] = new QPixmap(tileset.copy(100, 67, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[0][2][1] = new QPixmap(tileset.copy(133, 67, 32, 32).transformed(mirror));



        // Ennemi droite accélérateur état1 court
        itsEnemyRightTilesList[1][0][0] = new QPixmap(tileset.copy(1, 100, 32, 32));
        itsEnemyRightTilesList[1][0][1] = new QPixmap(tileset.copy(34, 100, 32, 32));
        // Ennemi droite accélérateur état1 tombe
        itsEnemyRightTilesList[1][1][0] = new QPixmap(tileset.copy(67, 100, 32, 32));
        itsEnemyRightTilesList[1][1][1] = nullptr;
        // Ennemi droite accélérateur état1 immobilisé
        itsEnemyRightTilesList[1][2][0] = new QPixmap(tileset.copy(100, 100, 32, 32));
        itsEnemyRightTilesList[1][2][1] = new QPixmap(tileset.copy(133, 100, 32, 32));


        // Ennemi gauche accélérateur état1 court
        itsEnemyLeftTilesList[1][0][0] = new QPixmap(tileset.copy(1, 100, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[1][0][1] = new QPixmap(tileset.copy(34, 100, 32, 32).transformed(mirror));
        // Ennemi gauche accélérateur état1 tombe
        itsEnemyLeftTilesList[1][1][0] = new QPixmap(tileset.copy(67, 100, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[1][1][1] = nullptr;
        // Ennemi gauche accélérateur état1 immobilisé
        itsEnemyLeftTilesList[1][2][0] = new QPixmap(tileset.copy(100, 100, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[1][2][1] = new QPixmap(tileset.copy(133, 100, 32, 32).transformed(mirror));


        // Ennemi droite accélérateur état2 court
        itsEnemyRightTilesList[2][0][0] = new QPixmap(tileset.copy(1, 133, 32, 32));
        itsEnemyRightTilesList[2][0][1] = new QPixmap(tileset.copy(34, 133, 32, 32));
        // Ennemi droite accélérateur état2 tombe
        itsEnemyRightTilesList[2][1][0] = new QPixmap(tileset.copy(67, 133, 32, 32));
        itsEnemyRightTilesList[2][1][1] = nullptr;
        // Ennemi droite accélérateur état2 immobilisé
        itsEnemyRightTilesList[2][2][0] = new QPixmap(tileset.copy(100, 133, 32, 32));
        itsEnemyRightTilesList[2][2][1] = new QPixmap(tileset.copy(133, 133, 32, 32));


        // Ennemi gauche accélérateur état2 court
        itsEnemyLeftTilesList[2][0][0] = new QPixmap(tileset.copy(1, 133, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[2][0][1] = new QPixmap(tileset.copy(34, 133, 32, 32).transformed(mirror));
        // Ennemi gacuhe accélérateur état2 tombe
        itsEnemyLeftTilesList[2][1][0] = new QPixmap(tileset.copy(67, 133, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[2][1][1] = nullptr;
        // Ennemi gauche accélérateur état2 immobilisé
        itsEnemyLeftTilesList[2][2][0] = new QPixmap(tileset.copy(100, 133, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[2][2][1] = new QPixmap(tileset.copy(133, 133, 32, 32).transformed(mirror));


        // Ennemi droite accélérateur état3 court
        itsEnemyRightTilesList[3][0][0] = new QPixmap(tileset.copy(1, 166, 32, 32));
        itsEnemyRightTilesList[3][0][1] = new QPixmap(tileset.copy(34, 166, 32, 32));
        // Ennemi droite accélérateur état3 tombe
        itsEnemyRightTilesList[3][1][0] = new QPixmap(tileset.copy(67, 166, 32, 32));
        itsEnemyRightTilesList[3][1][1] = nullptr;
        // Ennemi droite accélérateur état3 immobilisé
        itsEnemyRightTilesList[3][2][0] = new QPixmap(tileset.copy(100, 166, 32, 32));
        itsEnemyRightTilesList[3][2][1] = new QPixmap(tileset.copy(133, 166, 32, 32));


        // Ennemi gauche accélérateur état3 court
        itsEnemyLeftTilesList[3][0][0] = new QPixmap(tileset.copy(1, 166, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[3][0][1] = new QPixmap(tileset.copy(34, 166, 32, 32).transformed(mirror));
        // Ennemi gauche accélérateur état3 tombe
        itsEnemyLeftTilesList[3][1][0] = new QPixmap(tileset.copy(67, 166, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[3][1][1] = nullptr;
        // Ennemi gauche accélérateur état3 immobilisé
        itsEnemyLeftTilesList[3][2][0] = new QPixmap(tileset.copy(100, 166, 32, 32).transformed(mirror));
        itsEnemyLeftTilesList[3][2][1] = new QPixmap(tileset.copy(133, 166, 32, 32).transformed(mirror));



        // Ennemi droite Giant court
        itsEnemyRightTilesList[4][0][0] = new QPixmap(tileset.copy(1, 199, 32, 96));
        itsEnemyRightTilesList[4][0][1] = new QPixmap(tileset.copy(34, 199, 32, 96));
        // Ennemi droite Giant tombe
        itsEnemyRightTilesList[4][1][0] = new QPixmap(tileset.copy(67, 199, 32, 96));
        itsEnemyRightTilesList[4][1][1] = nullptr;
        // Ennemi droite Giant immobilisé
        itsEnemyRightTilesList[4][2][0] = new QPixmap(tileset.copy(100, 199, 32, 96));
        itsEnemyRightTilesList[4][2][1] = new QPixmap(tileset.copy(133, 199, 32, 96));


        // Ennemi gauche Giant court
        itsEnemyLeftTilesList[4][0][0] = new QPixmap(tileset.copy(1, 199, 32, 96).transformed(mirror));
        itsEnemyLeftTilesList[4][0][1] = new QPixmap(tileset.copy(34, 199, 32, 96).transformed(mirror));
        // Ennemi gauche Giant tombe
        itsEnemyLeftTilesList[4][1][0] = new QPixmap(tileset.copy(67, 199, 32, 96).transformed(mirror));
        itsEnemyLeftTilesList[4][1][1] = nullptr;
        // Ennemi gauche Giant immobilisé
        itsEnemyLeftTilesList[4][2][0] = new QPixmap(tileset.copy(100, 199, 32, 96).transformed(mirror));
        itsEnemyLeftTilesList[4][2][1] = new QPixmap(tileset.copy(133, 199, 32, 96).transformed(mirror));


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
}*/
/*
QPixmap *TileSet::getItsPlayerRunningRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsPlayerRightTilesList[0][0];
    }
    else if (aFrame == 1)
    {
        return itsPlayerRightTilesList[0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsPlayerJumpingRightTile()
{
    return itsPlayerRightTilesList[1][0];
}

QPixmap *TileSet::getItsPlayerHittingRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsPlayerRightTilesList[2][0];
    }
    else if (aFrame == 1)
    {
        return itsPlayerRightTilesList[2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsPlayerRunningLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsPlayerLeftTilesList[0][0];
    }
    else if (aFrame == 1)
    {
        return itsPlayerLeftTilesList[0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsPlayerJumpingLeftTile()
{
    return itsPlayerLeftTilesList[1][0];
}

QPixmap *TileSet::getItsPlayerHittingLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsPlayerLeftTilesList[2][0];
    }
    else if (aFrame == 1)
    {
        return itsPlayerLeftTilesList[2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyStandardRunningRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[0][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[0][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyStandardJumpingRightTile()
{
    return itsEnemyRightTilesList[0][1][0];
}

QPixmap *TileSet::getItsEnemyStandardHittedRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[0][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[0][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyStandardRunningLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[0][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[0][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyStandardJumpingLeftTile()
{
    return itsEnemyLeftTilesList[0][1][0];
}

QPixmap *TileSet::getItsEnemyStandardHittedLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[0][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[0][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}


QPixmap *TileSet::getItsEnemyAccelerator1RunningRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[1][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[1][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator1JumpingRightTile()
{
    return itsEnemyRightTilesList[1][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator1HittedRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[1][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[1][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator1RunningLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[1][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[1][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator1JumpingLeftTile()
{
    return itsEnemyLeftTilesList[1][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator1HittedLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[1][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[1][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator2RunningRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[2][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[2][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator2JumpingRightTile()
{
    return itsEnemyRightTilesList[2][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator2HittedRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[2][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[2][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator2RunningLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[2][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[2][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator2JumpingLeftTile()
{
    return itsEnemyLeftTilesList[2][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator2HittedLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[2][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[2][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator3RunningRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[3][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[3][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator3JumpingRightTile()
{
    return itsEnemyRightTilesList[3][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator3HittedRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[3][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[3][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator3RunningLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[3][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[3][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyAccelerator3JumpingLeftTile()
{
    return itsEnemyLeftTilesList[3][1][0];
}

QPixmap *TileSet::getItsEnemyAccelerator3HittedLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[3][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[3][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyGiantRunningRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[4][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[4][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyGiantdJumpingRightTile()
{
    return itsEnemyRightTilesList[4][1][0];
}

QPixmap *TileSet::getItsEnemyGiantHittedRightTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyRightTilesList[4][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyRightTilesList[4][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyGiantRunningLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[4][0][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[4][0][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}

QPixmap *TileSet::getItsEnemyGiantdJumpingLeftTile()
{
    return itsEnemyLeftTilesList[4][1][0];
}

QPixmap *TileSet::getItsEnemyGiantHittedLeftTile(unsigned short aFrame)
{
    if(aFrame == 0)
    {
        return itsEnemyLeftTilesList[4][2][0];
    }
    else if (aFrame == 1)
    {
        return itsEnemyLeftTilesList[4][2][1];
    }
    else
    {
        return itsNoTextureTile;
    }
}
*/

///**
// * @brief Tileset::getItsBlockTile() function implementation
// * @return QPixmap* : A pointer to the image of a Block in a normal state
// */

//QPixmap* TileSet::getItsBlockTile()
//{
//    return itsBlockTilesList[0];
//}

///**
// * @brief Tileset::getItsBlockHitTile() function implementation
// * @return QPixmap* : A pointer to the image of a Block in a hit state
// */
//QPixmap* TileSet::getItsBlockHittedTile()
//{
//    return itsBlockTilesList[1];
//}

///**
// * @brief Tileset::getItsGroundTile() function implementation
// * @return QPixmap* : A pointer to the image of a ground Block
// */
//QPixmap *TileSet::getItsGroundTile()
//{
//    return itsGroundTile;
//}

//QPixmap *TileSet::getItsPOWBlockTile()
//{
//    return itsBlockTilesList[0];
//}

//QPixmap *TileSet::getItsPOWBlockHittedTile()
//{
//    return itsBlockTilesList[1];
//}

//QPixmap *TileSet::getItsObstacleTile()
//{
//    return itsObstacleTile;
//}

//QPixmap *TileSet::getItsRedCoinTile(unsigned short aFrame)
//{
//    if(aFrame == 0)
//    {
//        return itsMoneyTilesList[0][0];
//    }
//    else if (aFrame == 1)
//    {
//        return itsMoneyTilesList[0][1];
//    }
//    else
//    {
//        return itsNoTextureTile;
//    }
//}

//QPixmap *TileSet::getItsYellowCoinTile(unsigned short aFrame)
//{
//    if(aFrame == 0)
//    {
//        return itsMoneyTilesList[1][0];
//    }
//    else if (aFrame == 1)
//    {
//        return itsMoneyTilesList[1][1];
//    }
//    else
//    {
//        return itsNoTextureTile;
//    }
//}

//QPixmap *TileSet::getItsBillTile(unsigned short aFrame)
//{
//    if(aFrame == 0)
//    {
//        return itsMoneyTilesList[2][0];
//    }
//    else if (aFrame == 1)
//    {
//        return itsMoneyTilesList[2][1];
//    }
//    else
//    {
//        return itsNoTextureTile;
//    }
//}



///**
// * @brief Tileset::getItsSpawnerTile(unsigned short index) function implementation
// * @param unsigned short index : The index of the image you want, index=[0] for left Spawner image, index=[1] for right Spawner image
// * @return QPixmap* : A pointer to the image of a Spawner specified
// */
//QPixmap* TileSet::getItsSpawnerTile(unsigned short index)
//{
//    return itsSpawnerTilesList[index];
//}

///**
// * @brief Tileset::getItsDespawnerTile(unsigned short index) function implementation
// * @param unsigned short index : The index of the image you want, index=[0] for left Despawner image, index=[1] for right Despawner image
// * @return QPixmap* : A pointer to the image of a Despawner specified
// */
//QPixmap *TileSet::getItsDespawnerTile(unsigned short index)
//{
//    return itsDespawnerTilesList[index];
//}

QPixmap *TileSet::getItsNoTextureTile()
{
    return itsNoTextureTile;
}

QPixmap *TileSet::getItsBackground()
{
    return itsBackground;
}

