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

//Constructeur
Entity::Entity(unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap * sprite)
{
    itsSprite = new Sprite(sprite);
    itsRect.setX(x);
    itsRect.setY(y);
    itsRect.setHeight(height);
    itsRect.setWidth(width);
}

