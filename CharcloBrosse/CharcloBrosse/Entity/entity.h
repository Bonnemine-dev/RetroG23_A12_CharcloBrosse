#ifndef ENTITY_H
#define ENTITY_H

#include "utils/sprite.h"

class Entity
{
protected:
    unsigned short itsX;
    unsigned short itsY;
    unsigned short itsHeight;
    unsigned short itsWidth;
    Sprite * itsSprite;
public:
    Entity();
    unsigned short getItsX() const;
    unsigned short getItsY() const;
    unsigned short getItsHeight() const;
    unsigned short getItsWidth() const;
};

#endif // ENTITY_H
