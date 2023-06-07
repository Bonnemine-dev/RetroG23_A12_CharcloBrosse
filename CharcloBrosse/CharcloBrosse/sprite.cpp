#include "sprite.h"

//Constructeur
Sprite::Sprite(QPixmap * image)
{
    itsImage = image;
}

//Methode display()
void Sprite::display(QPainter * painter)
{
    painter->drawPixmap(itsX, itsY, * itsImage);
}

//Methode moveTo()
void Sprite::moveTo(unsigned short x, unsigned short y)
{
    itsX = x;
    itsY = y;
}
