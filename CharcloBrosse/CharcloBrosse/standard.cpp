/**
 * @file standard.cpp
 * @brief Source file for class Standard
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */


#include "standard.h"

std::array<QPixmap *,12>* Standard::itsSpritesList = nullptr;

//Constructeur
Standard::Standard( short height,  short width, std::array<QPixmap *,12>* theSpritesList)
    :Enemy(height, width)
{
    itsType = STANDARD;
    itsSpritesList = theSpritesList;
}

void Standard::display(QPainter *painter)
{
    if(itsState){
        if(isOnTheGround){
            if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/STANDARD_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
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
        if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/STANDARD_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
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

