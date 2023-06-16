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
#include <cmath>

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

void Jumper::move()//----   96-0.01(x-96)^2
{
    if(itsState)
    {
        if(itsJumpTime == 0xFFFF && (isOnTheGround || (itsRemaningJumpMove != 0 && itsRemaningJumpMove != 192)))
        {
            if(*itsLoopCounter % (NUMBER_LOOP_PER_SECOND/int(float(30)+float(0.059)*pow(float(itsRemaningJumpMove-float(96)),2))) == 0)
            {
                if(itsRemaningJumpMove > 96)itsY--;
                else itsY++;
                itsRemaningJumpMove--;
                if(itsRemaningJumpMove == 0)itsJumpTime = DISTANCE_JUMPER_JUMP*BLOCK_SIZE;//640
            }
        }
        else if(*itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(JUMPER_ENEMY_SPEED*BLOCK_SIZE)) == 0)
        {
            itsY += itsYSpeed;
        }
        if(*itsLoopCounter % (NUMBER_LOOP_PER_SECOND/(JUMPER_ENEMY_SPEED*BLOCK_SIZE)) == 0)
        {

            itsX += itsXSpeed;
            if(itsX == -1)itsX = 32*39;
            else if(itsX == (32*39)+1)itsX = 0;

            itsJumpTime -= (itsJumpTime != 0 && itsJumpTime != 0xFFFF ? 1 : 0);
            if(itsJumpTime == 0)
            {
                itsRemaningJumpMove = 192;
                itsJumpTime = 0xFFFF;
            }
        }
        itsRect.moveTo(itsX,itsY);
    }
}

void Jumper::display(QPainter *painter)
{
    if(itsState)
    {
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
