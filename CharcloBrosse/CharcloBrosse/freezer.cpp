/**
 * @file freezer.cpp
 * @brief Source file for class Freezer
 * @author Tom Bonneau
 * @date 14/06/2023
 * @version 3.0
 */

#include "freezer.h"
#include <QDebug>

std::array<QPixmap *,12>* Freezer::itsSpritesList = nullptr;

//Constructeur de Giant
Freezer::Freezer(short height,  short width, std::array<QPixmap *,12>* theSpritesList)
    :Enemy(height, width)
{
    itsType = FREEZER;
    itsSpritesList = theSpritesList;
}

void Freezer::display(QPainter *painter)
{
    if(itsState){
        if(isOnTheGround){
            if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/FREEZER_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
            {
                if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0));
                else if(itsXSpeed == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(6));
                else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
            }
            else
            {
                if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
                else if(itsXSpeed == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(7));
                else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
            }
        }
        else
        {
            if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(2));
            else if(itsXSpeed == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(8));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(8));
        }
    }
    else
    {
        if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/FREEZER_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
        {
            if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(4));
            else if(itsXSpeed == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(10));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(4));
        }
        else
        {
            if(itsXSpeed == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(5));
            else if(itsXSpeed == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(11));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(5));
        }
    }
}
