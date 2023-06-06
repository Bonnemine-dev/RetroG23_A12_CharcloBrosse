#include "entity.h"

//Methode display()
void Entity::display(QPainter * painter)
{
    itsSprite->display(painter);
}

//Gette itsRect
QRect * Entity::getItsRect()
{
    return &itsRect;
}

//Setter pour la coordonnée en x
void Entity::setX(unsigned short newX)
{
    itsRect.setX(newX);
}

//Setter pour la coordonnée en y
void Entity::setY(unsigned short newY)
{
    itsRect.setX(newY);
}

//Constructeur
Entity::Entity(unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap * sprite)
{
    itsSprite = new Sprite(sprite);
    itsRect.setX(x);
    itsRect.setY(y);
    itsRect.setHeight(height);
    itsRect.setWidth(width);
}
