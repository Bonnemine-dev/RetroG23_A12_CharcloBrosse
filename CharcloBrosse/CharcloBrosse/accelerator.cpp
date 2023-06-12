/**
 * @file accelerator.cpp
 * @brief Source file for class Accelerator
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */


#include "accelerator.h"
std::array<std::array<QPixmap *,12>*, 3>* Accelerator::itsSprite = nullptr;
//Add 5 to itsSpeedState
void Accelerator::addItsSpeedState()
{
    if (itsSpeedState < 8)
    {
        itsSpeedState += 4;
    }
}

//Constructeur
short Accelerator::getItsSpeedState() const
{
    return itsSpeedState;
}
void Accelerator::display(QPainter *painter)
{
    if(itsState)painter->drawPixmap(itsX, itsY, *itsSprite->at(0)->at(2));
    else painter->drawPixmap(itsX, itsY, *itsSprite->at(0)->at(4));
}
Accelerator::Accelerator( short height,  short width, std::array<std::array<QPixmap *,12>*, 3>* sprite)
    :Enemy(height, width)
{
    itsType = STANDARD;
    itsSprite = sprite;
}
