#include "spawner.h"

//Constructeur
Spawner::Spawner(unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap * sprite)
    :Entity(x, y, height, width, sprite)
{

}

//Methode appears()
void Spawner::appears(Enemy * enemy)
{
    //Fait apparaitre l'enemy aux coordonnées du spawner
    enemy->setX(itsRect.x()+16);
    enemy->setY(itsRect.y());
}

