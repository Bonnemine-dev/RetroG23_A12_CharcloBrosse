#include "entity.h"

void Entity::display(QPainter * painter)
{
    itsSprite->display(painter);
}

const QRect &Entity::getItsRect() const
{
    return itsRect;
}

Entity::Entity(int x, int y, int height, int width, Sprite * sprite)
{
    itsRect.setX(x);
    itsRect.setY(y);
    itsRect.setHeight(height);
    itsRect.setWidth(width);
    itsSprite = sprite;
}

