#include "sprite.h"

Sprite::Sprite()
{

}

void Sprite::display(QPainter * painter)
{
    painter->drawPixmap(itsX, itsY, itsImage);
}

void Sprite::moveTo(unsigned short x, unsigned short y)
{
    itsX = x;
    itsY = y;
}
