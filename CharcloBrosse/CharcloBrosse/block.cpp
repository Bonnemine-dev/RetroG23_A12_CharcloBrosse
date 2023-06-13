/**
 * @file block.cpp
 * @brief Source file for class Block
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

#include "block.h"

#include "typedef.h"

std::array<QPixmap*, 6>* Block::itsSpritesList = nullptr;
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

void Block::display(QPainter *painter)
{
    if(itsType == BRICK)
    {
        if(itsState)
        {
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1));
        }
        else
        {
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0));
        }
    }
    else if(itsType == OBSTACLE)
    {
        painter->drawPixmap(itsX, itsY, *itsSpritesList->at(3));
    }
    else if(itsType == GROUND)
    {
       painter->drawPixmap(itsX, itsY, *itsSpritesList->at(2));
    }
    else
    {
       if(itsState)
       {
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(5));
       }
       else
       {
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(4));
       }
    }
}

Block::Block( short x,  short y,  short height,  short width, std::array<QPixmap *, 6>* theSpritesList,BlockType theBlockType)
    : Entity(x, y, height, width)
{
    itsType = theBlockType;
    itsSpritesList = theSpritesList;
}
Block::Block( short x,  short y,  short height,  short width,BlockType theBlockType)
    : Entity(x, y, height, width)
{
    itsType = theBlockType;
}

Block::~Block() {}

