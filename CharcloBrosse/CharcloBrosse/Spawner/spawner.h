
#ifndef SPAWNER_H
#define SPAWNER_H

#include "Entity/entity.h"
#include "Entity/Enemy/enemy.h"

class Spawner : Entity
{
public:
    Spawner();
    void appears(Enemy *);
};

#endif // SPAWNER_H
