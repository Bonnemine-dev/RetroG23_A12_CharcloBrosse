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
std::array<QPixmap*, 12> TileSet::itsEnnemyFreezerTilesList;
std::array<QPixmap*, 12> TileSet::itsEnnemyJumperTilesList;
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

std::array<QPixmap *, 12> *TileSet::getItsEnnemyJumperTilesList()
{
    return &itsEnnemyJumperTilesList;
}

std::array<QPixmap *, 12> *TileSet::getItsEnnemyFreezerTilesList()
{
    return &itsEnnemyFreezerTilesList;
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

QPixmap *TileSet::getItsNoTextureTile()
{
    return itsNoTextureTile;
}

std::array<QPixmap *, 2> *TileSet::getItsDespawnerTilesList()
{
    return &itsDespawnerTilesList;
}

TileSet::TileSet(std::string aTileSetFilePath)
{
    //< Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre
    QString tileSetFilePath = QString::fromStdString(aTileSetFilePath);
    QPixmap tileset(tileSetFilePath);
    //> Conversion en QString car le constructeur QPixmap() ne prend pas de string en paramètre
    //< Vérification de l'ouverture du fichier et lancement d'une exception si non
    if(tileset.isNull())
    {
       throw std::runtime_error("Tileset file unfound (Tileset::Tileset(const std::string aFilePath)");
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

       for (unsigned short i = 0; i < itsEnnemyAcceleratorTilesList.size(); i++)
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



       // Ennemi droite Jumper court
       itsEnnemyJumperTilesList.at(0) = new QPixmap(tileset.copy(166, 232, 32, 32));
       itsEnnemyJumperTilesList.at(1) = new QPixmap(tileset.copy(199, 232, 32, 32));
       // Ennemi droite Jumper tombe
       itsEnnemyJumperTilesList.at(2) = new QPixmap(tileset.copy(232, 232, 32, 32));
       itsEnnemyJumperTilesList.at(3) = nullptr;
       // Ennemi droite Jumper immobilisé
       itsEnnemyJumperTilesList.at(4) = new QPixmap(tileset.copy(265, 232, 32, 32));
       itsEnnemyJumperTilesList.at(5) = new QPixmap(tileset.copy(298, 232, 32, 32));


       // Ennemi gauche Jumper court
       itsEnnemyJumperTilesList.at(6) = new QPixmap(tileset.copy(166, 232, 32, 32).transformed(mirror));
       itsEnnemyJumperTilesList.at(7) = new QPixmap(tileset.copy(199, 232, 32, 32).transformed(mirror));
       // Ennemi gauche Jumper tombe
       itsEnnemyJumperTilesList.at(8) = new QPixmap(tileset.copy(232, 232, 32, 32).transformed(mirror));
       itsEnnemyJumperTilesList.at(9) = nullptr;
       // Ennemi gauche Jumper immobilisé
       itsEnnemyJumperTilesList.at(10) = new QPixmap(tileset.copy(265, 232, 32, 32).transformed(mirror));
       itsEnnemyJumperTilesList.at(11) = new QPixmap(tileset.copy(298, 232, 32, 32).transformed(mirror));



       // Ennemi droite Freezer court
       itsEnnemyFreezerTilesList.at(0) = new QPixmap(tileset.copy(166, 199, 32, 32));
       itsEnnemyFreezerTilesList.at(1) = new QPixmap(tileset.copy(199, 199, 32, 32));
       // Ennemi droite Freezer tombe
       itsEnnemyFreezerTilesList.at(2) = new QPixmap(tileset.copy(232, 199, 32, 32));
       itsEnnemyFreezerTilesList.at(3) = nullptr;
       // Ennemi droite Freezer immobilisé
       itsEnnemyFreezerTilesList.at(4) = new QPixmap(tileset.copy(265, 199, 32, 32));
       itsEnnemyFreezerTilesList.at(5) = new QPixmap(tileset.copy(298, 199, 32, 32));


       // Ennemi gauche Freezer court
       itsEnnemyFreezerTilesList.at(6) = new QPixmap(tileset.copy(166, 199, 32, 32).transformed(mirror));
       itsEnnemyFreezerTilesList.at(7) = new QPixmap(tileset.copy(199, 199, 32, 32).transformed(mirror));
       // Ennemi gauche Freezer tombe
       itsEnnemyFreezerTilesList.at(8) = new QPixmap(tileset.copy(232, 199, 32, 32).transformed(mirror));
       itsEnnemyFreezerTilesList.at(9) = nullptr;
       // Ennemi gauche Freezer immobilisé
       itsEnnemyFreezerTilesList.at(10) = new QPixmap(tileset.copy(265, 199, 32, 32).transformed(mirror));
       itsEnnemyFreezerTilesList.at(11) = new QPixmap(tileset.copy(298, 199, 32, 32).transformed(mirror));




       // Block normal
       itsBlockTilesList.at(0) = new QPixmap(tileset.copy(1, 296, 32, 32));
       // Block frappé
       itsBlockTilesList.at(1) = new QPixmap(tileset.copy(34, 296, 32, 32));

       // Block ground
       itsBlockTilesList.at(2) = new QPixmap(tileset.copy(67, 296, 32, 32));

       // Obstacle
       itsBlockTilesList.at(3) = new QPixmap(tileset.copy(100, 296, 32, 32));

       // Block POW normal
       itsBlockTilesList.at(4) = new QPixmap(tileset.copy(166, 133, 64, 64));
       // Block POW frappé
       itsBlockTilesList.at(5) = new QPixmap(tileset.copy(231, 133, 64, 64));



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
       itsDespawnerTilesList.at(0) = new QPixmap(tileset.copy(296, 2, 64, 96));
       // Dispawner droite
       itsDespawnerTilesList.at(1) = new QPixmap(tileset.copy(361, 2, 64, 96));

       // Texture par default
       itsNoTextureTile = new QPixmap(tileset.copy(1, 362, 32, 32));
       //> Chargement et stockage de chaque image une par une en précisant leur position et leur taille (possibilité de mettre des constantes à termes)
    }
    //> Vérification de l'ouverture du fichier et lancement d'une exception si non


    //< Vérification de l'ouverture du fichier et lancement d'une exception si non

    //> Vérification de l'ouverture du fichier et lancement d'une exception si non
}

TileSet::~TileSet()
{
    // Libérer la mémoire des tableaux de QPixmap
    // itsPlayerTilesList
    for (QPixmap* pixmap : itsPlayerTilesList)
    {
       delete pixmap;
    }

    // itsEnnemyStandardTilesList
    for (QPixmap* pixmap : itsEnnemyStandardTilesList)
    {
       delete pixmap;
    }

    // itsEnnemyAcceleratorTilesList
    for (std::array<QPixmap*, 12>* array : itsEnnemyAcceleratorTilesList)
    {
       for (QPixmap* pixmap : *array)
       {
           delete pixmap;
       }
       delete array;
    }

    // itsEnnemyGiantTilesList
    for (QPixmap* pixmap : itsEnnemyGiantTilesList)
    {
       delete pixmap;
    }

    // itsEnnemyJumperTilesList
    for (QPixmap* pixmap : itsEnnemyJumperTilesList)
    {
       delete pixmap;
    }

    // itsEnnemyFreezerTilesList
    for (QPixmap* pixmap : itsEnnemyFreezerTilesList)
    {
       delete pixmap;
    }

    // itsBlockTilesList
    for (QPixmap* pixmap : itsBlockTilesList)
    {
       delete pixmap;
    }

    // itsNoTextureTile
    delete itsNoTextureTile;

    // itsBackground
    delete itsBackground;

    // itsMoneyTilesList
    for (std::array<QPixmap*, 2>* array : itsMoneyTilesList)
    {
       for (QPixmap* pixmap : *array)
       {
           delete pixmap;
       }
       delete array;
    }

    // itsSpawnerTilesList
    for (QPixmap* pixmap : itsSpawnerTilesList)
    {
       delete pixmap;
    }

    // itsDespawnerTilesList
    for (QPixmap* pixmap : itsDespawnerTilesList)
    {
       delete pixmap;
    }
}

