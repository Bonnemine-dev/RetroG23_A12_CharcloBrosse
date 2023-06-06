#include "block.h"

//Getter du itsState
bool Block::getItsState() const
{
    return itsState;
}

//Setter du itsState
void Block::setItsState(bool newItsState)
{
    itsState = newItsState;
}

//Getter du itsCounter
unsigned short Block::getItsCounter() const
{
    return itsCounter;
}

//Incrétente le compteur de 1
void Block::increment(unsigned int nb)
{
    itsCounter += 1;
    if (itsCounter >= 100) //Reset l'état du bloc au compteur = 100 soit 1,5 seconde environ (à 60 fps)
    {
        setItsState(false);
    }
    if (itsCounter >= nb) //Passe l'état du bloc à false (frappé) au compteur = nb -> à définir
    {
        setItsState(true);
        itsCounter = 0;
    }
}

//Constructeur
Block::Block(unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap * sprite)
    : Entity(x, y, height, width, sprite)
{

}

