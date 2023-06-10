#include "player.h"
#include "qdebug.h"
#include <iostream>

//bool Player::getItsState() const
//{
//    return itsState;
//}

//Methode move
void Player::move()
{

    itsX += itsXSpeed;
    itsY += itsYSpeed;
    itsRect.moveTo((itsRect.x() + itsXSpeed),(itsRect.y() + itsYSpeed));
    if(itsX == -1)
    {
        itsX = 32*39;
        itsRect.moveTo(itsX,itsY);
    }
    else if(itsX == (32*39)+1)
    {
        itsX = 0;
        itsRect.moveTo(itsX,itsY);
    }
    itsRemaningJumpMove = (itsRemaningJumpMove != 0?itsRemaningJumpMove - 1:itsRemaningJumpMove);
}

//Setter itsXSpeed
void Player::setItsXSpeed(short newItsXSpeed)
{
    itsXSpeed = newItsXSpeed;
}

//Setter itsYSpeed
void Player::setItsYSpeed(short newItsYSpeed)
{
    itsYSpeed = newItsYSpeed;
}

//Setter itsLivesNb
void Player::setItsLivesNb(unsigned short newItsLivesNb)
{
    itsLivesNb = newItsLivesNb;
}

//Getter itsLivesNb
unsigned short Player::getItsLivesNb() const
{
    return itsLivesNb;
}

//Getter itsXSpeed
short Player::getItsXSpeed() const
{
    return itsXSpeed;
}

//Getter itsYSpeed
short Player::getItsYSpeed() const
{
    return itsYSpeed;
}

//Setter isOnTheGround
void Player::setIsOnTheGround(bool newIsOnTheGround)
{
    isOnTheGround = newIsOnTheGround;
}

//Getter isOnTheGround
bool Player::getIsOnTheGround() const
{
    return isOnTheGround;
}

//Constructeur
unsigned short Player::getItsRemaningJumpMove() const
{
    return itsRemaningJumpMove;
}

void Player::setItsRemaningJumpMove(unsigned short newItsRemaningJumpMove)
{
    itsRemaningJumpMove = newItsRemaningJumpMove;
}

Player::Player( short x,  short y,  short height,  short width, QPixmap *sprite)
    : Entity(x, y, height, width, sprite)
{
    itsLivesNb = 3;
}

