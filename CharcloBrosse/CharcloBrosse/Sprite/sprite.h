#ifndef SPRITE_H
#define SPRITE_H

#include <QPixmap>
#include <QPainter>

class Sprite
{
private:
    QPixmap itsImage;
    unsigned short itsX;
    unsigned short itsY;
    unsigned short itsHeight;
    unsigned short itsWidth;
public:
    Sprite();
    void display(QPainter * painter);
    void moveTo(unsigned short x, unsigned short y);
};

#endif // SPRITE_H
