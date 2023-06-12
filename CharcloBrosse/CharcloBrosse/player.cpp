#include "player.h"
#include <iostream>

//bool Player::getItsState() const
//{
//    return itsState;
//}

//Methode move
void Player::move()
{
    if(itsCurrentMove != itsNextMove && isOnTheGround)itsCurrentMove = itsNextMove;

    itsX += itsCurrentMove;
    if(itsX == -1)itsX = 32*39;
    else if(itsX == (32*39)+1)itsX = 0;

    itsY += itsYSpeed;
    itsRect.moveTo(itsX,itsY);

    itsRemaningJumpMove += (itsRemaningJumpMove != 0?-1:0);
}

void Player::display(QPainter * painter)
{
    painter->drawPixmap(itsX, itsY, *itsSprite);
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

void Player::setItsCurrentMove(MoveX newItsCurrentMove)
{
    itsCurrentMove = newItsCurrentMove;
}

void Player::setItsNextMove(MoveX newItsNextMove)
{
    itsNextMove = newItsNextMove;
}

Player::Player(short x,  short y,  short height,  short width, std::array<QPixmap *, 5> *sprites)
    : Entity(x, y, height, width)
{
    itsSprite = sprites;
    itsLivesNb = 3;
}

