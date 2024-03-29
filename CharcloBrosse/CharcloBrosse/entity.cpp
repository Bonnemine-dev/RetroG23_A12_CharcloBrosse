/**
 * @file entity.cpp
 * @brief Source file for abstract class Entity
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

#include "entity.h"

unsigned short* Entity::itsLoopCounter;
//Methode display()
void Entity::display(QPainter * painter)
{
//    painter->drawPixmap(itsX, itsY, *itsSprite);
}

//Gette itsRect
QRect * Entity::getItsRect()
{
    return &itsRect;
}

//Setter pour la coordonnée en x
void Entity::setX( short newX)
{
    itsX = newX;
    itsRect.moveTo(itsX,itsY);
}

//Setter pour la coordonnée en y
void Entity::setY( short newY)
{
    itsY = newY;
    itsRect.moveTo(itsX,itsY);
}

//Constructeur

Entity::Entity(short x,  short y,  short height,  short width)
{
    itsX = x;
    itsY = y;
    itsRect.moveTo(x,y);
    itsRect.setHeight(height);
    itsRect.setWidth(width);
}

Entity::~Entity()
{

}

//Getter getItsX
short Entity::getItsX() const
{
    return itsX;
}

//Getter getItsY
short Entity::getItsY() const
{
    return itsY;
}

//Getter getItsHeight()
short Entity::getItsHeight() const
{
    return itsRect.height();
}

//Getter getItsWidth()
short Entity::getItsWidth() const
{
    return itsRect.width();
}
