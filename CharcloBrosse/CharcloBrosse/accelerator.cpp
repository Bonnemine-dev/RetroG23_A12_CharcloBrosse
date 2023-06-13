/**
 * @file accelerator.cpp
 * @brief Source file for class Accelerator
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */


#include "accelerator.h"
std::array<std::array<QPixmap *,12>*, 3>* Accelerator::itsSpritesList = nullptr;
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

Accelerator::Accelerator( short height,  short width, std::array<std::array<QPixmap *,12>*, 3>* theSpritesList)
    :Enemy(height, width)
{
    itsType = STANDARD;
    itsSpritesList = theSpritesList;
}

void Accelerator::display(QPainter *painter)//painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0)->at(2));
{
    unsigned short speedstate = itsSpeedState == 1?1:itsSpeedState == 5?2:3;
    if(itsState){
        if(isOnTheGround){
            if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/STANDARD_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
            {
                if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(0));
                else if(itsXSpeed == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(6));
                else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(1));
            }
            else
            {
                if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(1));
                else if(itsXSpeed == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(7));
                else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(1));
            }
        }
        else
        {
            if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(2));
            else if(itsXSpeed == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(8));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(8));
        }
    }
    else
    {
        if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/(speedstate == 1?5:speedstate == 2?10:15))*NUMBER_IMAGE_PER_ANIMATION)  == 0)
        {
            if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(4));
            else if(itsXSpeed == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(10));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(4));
        }
        else
        {
            if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(5));
            else if(itsXSpeed == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(11));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(speedstate)->at(5));
        }
    }
}
