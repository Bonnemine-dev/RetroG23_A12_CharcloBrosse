/**
 * @file jumper.h
 * @brief Source file for class Jumper
 * @author Tom Bonneau
 * @date 14/06/2023
 * @version 3.0
 */

#include "jumper.h"
#include "typedef.h"
#include <QDebug>
#include <iostream>
#include <ostream>

std::array<QPixmap *,12>* Jumper::itsSpritesList = nullptr;

//Constructeur
bool Jumper::getJump() const
{
    return jump;
}

Jumper::Jumper(short height,  short width, std::array<QPixmap *,12>* theSpritesList)
    :Enemy(height, width)
{
    itsType = JUMPER;
    itsSpritesList = theSpritesList;
}

void Jumper::move()
{
    if(jump)
    {
        std::cout<<"jump true"<<std::endl;
        jumpTime--;
        if(jumpTime>0)
        {
            std::cout<<YStart<<std::endl;
            if(itsY != (YStart - 96))
            {
                itsYSpeed = -1;
            }
            else
            {
                itsYSpeed = 0;
            }
            std::cout<<itsY<<std::endl;
        }
        else
        {
            jump = false;
        }
        std::cout<<jumpTime<<std::endl;
    }
    else
    {
        std::cout<<"jump false"<<std::endl;
        if(!isOnTheGround)
        {
            itsYSpeed = +1;
        }
        else
        {
            jumpTime++;
            if(jumpTime >= 200)
            {
                jump = true;
                YStart = itsY;
            }
        }
    }
    itsX += itsXSpeed;
    itsY += itsYSpeed;
    itsRect.moveTo(itsX,itsY);
}

void Jumper::display(QPainter *painter)
{
    this->move();
    if(itsState){
        if(isOnTheGround){
            if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/JUMPER_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
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
        if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/JUMPER_ENEMY_SPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
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
