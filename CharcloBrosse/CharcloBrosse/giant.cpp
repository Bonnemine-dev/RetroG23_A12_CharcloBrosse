/**
 * @file giant.cpp
 * @brief Source file for class Giant
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */

#include "giant.h"
std::array<QPixmap *,12>* Giant::itsSprite = nullptr;
//Constructeur de Giant
Giant::Giant( short height,  short width, std::array<QPixmap *,12>* sprite)
    :Enemy(height, width)
{
    itsType = STANDARD;
    itsSprite = sprite;
}
void Giant::display(QPainter *painter)
{
    if(itsState)painter->drawPixmap(itsX, itsY, *itsSprite->at(2));
    else painter->drawPixmap(itsX, itsY, *itsSprite->at(4));
}
