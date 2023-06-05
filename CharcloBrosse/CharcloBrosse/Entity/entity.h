#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>

#include "utils/sprite.h"

class Entity
{
protected:
    QRect itsRect;
    Sprite * itsSprite;
public:
    Entity();
    unsigned short getItsX() const;
    unsigned short getItsY() const;
    unsigned short getItsHeight() const;
    unsigned short getItsWidth() const;
    void display(QPainter * painter);
    const QRect &getItsRect() const;
};

#endif // ENTITY_H
