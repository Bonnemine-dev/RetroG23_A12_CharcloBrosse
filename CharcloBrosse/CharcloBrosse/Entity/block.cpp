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
void Block::increment()
{
    itsCounter += 1;
}

//Constructeur
Block::Block(unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap * sprite)
    : Entity(x, y, height, width, sprite)
{

}

