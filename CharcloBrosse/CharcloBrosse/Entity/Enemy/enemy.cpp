
#include "enemy.h"

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

//Constructeur
Enemy::Enemy(unsigned short height, unsigned short width, QPixmap * sprite)
    : Entity(0, 0, height, width, sprite)
{

}

