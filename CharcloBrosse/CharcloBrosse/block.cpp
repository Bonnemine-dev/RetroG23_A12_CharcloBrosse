#include "block.h"

#include "typedef.h"

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
void Block::increment()
{
    itsCounter += 1;
    if (itsCounter >= COUNTER_VALUE) //Reset l'état du bloc au compteur = COUNTER_VALUE
    {
        setItsState(false);
    }

}

//Constructeur
Block::Block( short x,  short y,  short height,  short width, QPixmap * sprite)
    : Entity(x, y, height, width, sprite)
{

}

