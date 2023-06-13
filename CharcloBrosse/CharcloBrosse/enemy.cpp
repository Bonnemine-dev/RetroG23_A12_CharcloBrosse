/**
 * @file enemy.cpp
 * @brief Source file for class Enemy
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

#include "enemy.h"
#include "tileset.h"

//Getter itsXSpeed
short Enemy::getItsXSpeed() const
{
    return itsXSpeed;
}

//Getter itsYSpeed
short Enemy::getItsYSpeed() const
{
    return itsYSpeed;
}

//Getter itsState
bool Enemy::getItsState() const
{
    return itsState;
}

//Getter itsType
EnemyType Enemy::getItsType() const
{
    return itsType;
}

//Setter itsXSpeed
void Enemy::setItsXSpeed(short newItsXSpeed)
{
    itsXSpeed = newItsXSpeed;
}

//Setter itsYSpeed
void Enemy::setItsYSpeed(short newItsYSpeed)
{
    itsYSpeed = newItsYSpeed;
}

//Setter itsState
void Enemy::setItsState(bool newItsState)
{
    itsState = newItsState;
}

//move()
void Enemy::move()
{
    if(itsState)
    {
        itsX += itsXSpeed;
        if(itsX == -1)itsX = 32*39;
        else if(itsX == (32*39)+1)itsX = 0;
        itsY += itsYSpeed;
        itsRect.moveTo(itsX,itsY);
    }
}

//Setter isOnTheGround
void Enemy::setIsOnTheGround(bool newIsOnTheGround)
{
    isOnTheGround = newIsOnTheGround;
}

//Getter isOnTheGround
bool Enemy::getIsOnTheGround() const
{
    return isOnTheGround;
}

//Constructeur
short Enemy::getItsNumberLoopKO() const
{
    return itsNumberLoopKO;
}

void Enemy::setItsNumberLoopKO(short newItsNumberLoopKO)
{
    itsNumberLoopKO = newItsNumberLoopKO;
}

Enemy::Enemy( short height,  short width, QPixmap * sprite)
    : Entity(0, 0, height, width, sprite)
{
    itsState = true;
}

Enemy::~Enemy() {}

