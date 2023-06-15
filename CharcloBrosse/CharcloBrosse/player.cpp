#include "player.h"
#include <iostream>

std::array<QPixmap*, 12>* Player::itsSpritesList = nullptr;

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
    if(isOnTheGround){
        if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%((10/PLAYERMAXSPEED)*NUMBER_IMAGE_PER_ANIMATION)  == 0)
        {
            if(itsCurrentMove == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0));
            else if(itsCurrentMove == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(6));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
        }
        else
        {
            if(itsCurrentMove == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
            else if(itsCurrentMove == LEFT_X) painter->drawPixmap(itsX, itsY, *itsSpritesList->at(7));
            else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
        }
    }
    else
    {
        if(itsCurrentMove == RIGHT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(2));
        else if(itsCurrentMove == LEFT_X)painter->drawPixmap(itsX, itsY, *itsSpritesList->at(8));
        else painter->drawPixmap(itsX, itsY, *itsSpritesList->at(8));
    }
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


unsigned short Player::getItsRemaningComboTicks() const
{
    return itsRemaningComboTicks;
}

void Player::setItsRemaningComboTicks(unsigned short newItsRemaningComboTicks)
{
    itsRemaningComboTicks = newItsRemaningComboTicks;
}

unsigned short Player::getComboValue() const
{
    return comboValue;
}

void Player::setComboValue(unsigned short newComboValue)
{
    comboValue = newComboValue;
}

void Player::setIsFrozen(bool newIsFrozen)
{
    isFrozen = newIsFrozen;
}

bool Player::getIsFrozen() const
{
    return isFrozen;
}

void Player::setStartFreeze(unsigned short newStartFreeze)
{
    startFreeze = newStartFreeze;
}

unsigned short Player::getStartFreeze() const
{
    return startFreeze;
}

Player::Player(short x,  short y,  short height,  short width, std::array<QPixmap *, 12> *theSpritesList,unsigned short* theLoopCounter)
    : Entity(x, y, height, width)
{
    itsSpritesList = theSpritesList;
    itsLivesNb = MAX_LIFE;
    itsLoopCounter = theLoopCounter;
}

