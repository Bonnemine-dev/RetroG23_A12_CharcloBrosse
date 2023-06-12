/**
 * @file entity.cpp
 * @brief Source file for abstract class Entity
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

#include "entity.h"

//Methode display()
void Entity::display(QPainter * painter)
{
    painter->drawPixmap(itsX, itsY, *itsSprite);
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

//Change la position du sprite en fonction de celle de la hit box
void Entity::moveTo()
{
}

//Constructeur
void Entity::setItsSprite(QPixmap *newItsSprite)
{
    itsSprite = newItsSprite;
}

Entity::Entity(short x,  short y,  short height,  short width, QPixmap * sprite)
{
    itsSprite = sprite;
    itsX = x;
    itsY = y;
    itsRect.moveTo(x,y);
    itsRect.setHeight(height);
    itsRect.setWidth(width);
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
