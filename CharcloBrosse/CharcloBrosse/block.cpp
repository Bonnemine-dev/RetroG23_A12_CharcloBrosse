/**
 * @file block.cpp
 * @brief Source file for class Block
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

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
void Block::setItsCounter(unsigned short newItsCounter)
{
    itsCounter = newItsCounter;
}

BlockType Block::getItsType() const
{
    return itsType;
}

Block::Block( short x,  short y,  short height,  short width, QPixmap * sprite,BlockType theBlockType)
    : Entity(x, y, height, width, sprite)
{
    itsType = theBlockType;
}

