#include "spawner.h"
#include "typedef.h"
#include <iostream>

std::array<QPixmap *,2>* Spawner::itsSpritesList = nullptr;
//Constructeur
Spawner::Spawner( short x,  short y,  short height,  short width, std::array<QPixmap *,2>* theSpritesList, Direction theDirection)
    :Entity(x, y, height, width)
{
    itsSpritesList = theSpritesList;
    itsDirection = theDirection;
}

//Methode appears()
void Spawner::appears(Enemy * enemy)
{
    //Fait apparaitre l'enemy aux coordonnées du spawner
    enemy->setX(itsRect.x()+16);//16
    enemy->setY(itsRect.y()+itsRect.height() - enemy->getItsHeight());//Enlever le +60 à terme
    enemy->setItsXSpeed(STANDARD_ENEMY_SPEED);
}
void Spawner::display(QPainter *painter)
{
    if(itsDirection == EAST)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0));
    else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
}

