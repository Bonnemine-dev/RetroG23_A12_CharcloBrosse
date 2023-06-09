#include "despawner.h"

//Constructeur
Despawner::Despawner(Spawner * spawner,  short x,  short y,  short height,  short width, QPixmap *sprite)
    :Entity(x, y, height, width, sprite)
{
    itsSpawner = spawner;
}

//Methode disappear()
void Despawner::disappear(Enemy *enemy)
{
    enemy->setX(itsSpawner->getItsX()); //Met le x de l'enemy au x du spawner lié
    enemy->setY(itsSpawner->getItsY()); //Met le y de l'enemy au y du spawner lié
    enemy->setItsXSpeed(-(enemy->getItsXSpeed())); //Change la direction
}
