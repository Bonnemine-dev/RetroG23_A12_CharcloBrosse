#ifndef ENEMY_H
#define ENEMY_H

#include <Entity/entity.h>


enum EnemyType {Standard, Accelerator, Giant, Jumper, Freezer};

class Enemy : public Entity
{
protected:
    short itsXSpeed;
    short itsYSpeed;
    bool itsState;
    EnemyType itsType;
public:
    Enemy();
};

#endif // ENEMY_H
