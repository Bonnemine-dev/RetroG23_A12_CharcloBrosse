/**
 * @file despawner.cpp
 * @brief Source file for class Block
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

#include "despawner.h"

std::array<QPixmap *,2>* Despawner::itsSprite = nullptr;
//Constructeur
Despawner::Despawner(Spawner * spawner,  short x,  short y,  short height,  short width, std::array<QPixmap *,2>* sprite, Direction theDirection)
    :Entity(x, y, height, width)
{
    itsSpawner = spawner;
    itsSprite = sprite;
    itsDirection = theDirection;
}

//Methode disappear()
void Despawner::disappear(Enemy *enemy)
{
    enemy->setX(itsSpawner->getItsX()); //Met le x de l'enemy au x du spawner lié
    enemy->setY(itsSpawner->getItsY()); //Met le y de l'enemy au y du spawner lié
    enemy->setItsXSpeed(-(enemy->getItsXSpeed())); //Change la direction
}
void Despawner::display(QPainter *painter)
{
    if(itsDirection == EAST)painter->drawPixmap(itsX, itsY, *itsSprite->at(0));
    else painter->drawPixmap(itsX, itsY, *itsSprite->at(1));
}
