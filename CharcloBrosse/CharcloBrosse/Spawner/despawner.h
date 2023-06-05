
#ifndef DESPAWNER_H
#define DESPAWNER_H

#include "Entity/entity.h"
#include "Spawner/spawner.h"
#include "Entity/Enemy/enemy.h"


class Despawner : public Entity
{
private:
    Spawner * itsSpawner;
public:
    Despawner();
    void disappear(Enemy *);
};

#endif // DESPAWNER_H
