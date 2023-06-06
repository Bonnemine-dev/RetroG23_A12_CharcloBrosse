#include "player.h"

//bool Player::getItsState() const
//{
//    return itsState;
//}

//Methode move
void Player::move()
{
    itsRect.setX(itsRect.x() + itsXSpeed);
    itsRect.setY(itsRect.y() + itsYSpeed);
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

//Constructeur
Player::Player(unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap *sprite)
    : Entity(x, y, height, width, sprite)
{

}

