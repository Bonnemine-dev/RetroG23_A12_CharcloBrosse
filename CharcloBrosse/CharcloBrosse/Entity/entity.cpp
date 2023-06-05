#include "entity.h"

void Entity::display(QPainter * painter)
{
    itsSprite->display(painter);
}

const QRect &Entity::getItsRect() const
{
    return itsRect;
}

Entity::Entity()
{

}

