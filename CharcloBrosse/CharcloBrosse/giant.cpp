/**
 * @file giant.cpp
 * @brief Source file for class Giant
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */

#include "giant.h"
#include "QtCore/qdebug.h"
std::array<QPixmap *,12>* Giant::itsSpritesList = nullptr;
//Constructeur de Giant
Giant::Giant( short height,  short width, std::array<QPixmap *,12>* theSpritesList)
    :Enemy(height, width)
{
    itsType = GIANT;
    itsSpritesList = theSpritesList;
}
void Giant::display(QPainter *painter)
{
    qWarning()<<"Je viends de display le geant";

    if(itsState){
        if(isOnTheGround){
            if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/GIANT_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
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
