/**
 * @file standard.cpp
 * @brief Source file for class Standard
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */


#include "standard.h"

std::array<QPixmap *,12>* Standard::itsSprite = nullptr;

//Constructeur
Standard::Standard( short height,  short width, std::array<QPixmap *,12>* sprite)
    :Enemy(height, width)
{
    itsType = STANDARD;
    itsSprite = sprite;
}

void Standard::display(QPainter *painter)
{
    if(itsState)painter->drawPixmap(itsX, itsY, *itsSprite->at(2));
    else painter->drawPixmap(itsX, itsY, *itsSprite->at(4));
}

