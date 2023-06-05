
#include "player.h"

bool Player::getItsState() const
{
    return itsState;
}

void Player::move()
{
    itsRect.setX(itsRect.x() + itsXSpeed);
    itsRect.setY(itsRect.y() + itsYSpeed);
}

void Player::setItsXSpeed(short newItsXSpeed)
{
    itsXSpeed = newItsXSpeed;
}

void Player::setItsYSpeed(short newItsYSpeed)
{
    itsYSpeed = newItsYSpeed;
}

void Player::setItsLivesNb(unsigned short newItsLivesNb)
{
    itsLivesNb = newItsLivesNb;
}

unsigned short Player::getItsLivesNb() const
{
    return itsLivesNb;
}

Player::Player(int x, int y, int height, int width, Sprite* sprite)
    : Entity(x, y, height, width, sprite)
{

}

