
#include "enemy.h"

Enemy::Enemy(EnemyType type, int x, int y, int height, int width, Sprite* sprite)
    : Entity(x, y, height, width, sprite)
{
    itsType = type;
}

