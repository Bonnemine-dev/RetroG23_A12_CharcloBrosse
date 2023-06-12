#include "spawner.h"
#include "typedef.h"
#include <iostream>

//Constructeur
Spawner::Spawner( short x,  short y,  short height,  short width, QPixmap * sprite)
    :Entity(x, y, height, width, sprite)
{

}

//Methode appears()
void Spawner::appears(Enemy * enemy)
{
    //Fait apparaitre l'enemy aux coordonnées du spawner
    enemy->setX(itsRect.x()+16);//16
    enemy->setY(itsRect.y()+60);//Enlever le +60 à terme
    enemy->setItsXSpeed(NONE);
}

