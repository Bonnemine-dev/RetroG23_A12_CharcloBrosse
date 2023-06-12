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
    //std::cout<<"La vitesse sur l'axe X de player lors de son move : "<<itsXSpeed<<"\n";
    itsX += itsXSpeed;
    std::cout<<"La vitesse sur l'axe Y de player lors de son move : "<<itsYSpeed<<"\n";
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
Player::Player( short x,  short y,  short height,  short width, QPixmap *sprite)
    : Entity(x, y, height, width, sprite)
{
    itsLivesNb = 3;
    qWarning() << height;
}

