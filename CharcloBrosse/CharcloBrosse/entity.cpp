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

//Change la position du sprite en fonction de celle de la hit box
void Entity::moveTo()
{
    itsSprite->moveTo(itsRect.x(), itsRect.y());
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

//Getter getItsX
unsigned short Entity::getItsX() const
{
    return itsRect.x();
}

//Getter getItsY
unsigned short Entity::getItsY() const
{
    return itsRect.y();
}

//Getter getItsHeight()
unsigned short Entity::getItsHeight() const
{
    return itsRect.height();
}

//Getter getItsWidth()
unsigned short Entity::getItsWidth() const
{
    return itsRect.width();
}
