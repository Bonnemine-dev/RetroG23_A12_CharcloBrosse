/**
 * @file block.cpp
 * @brief Source file for class Block
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

#include "block.h"

#include "typedef.h"

std::array<QPixmap*, 4>* Block::itsSprite = nullptr;
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
            painter->drawPixmap(itsX, itsY, *itsSprite->at(1));
        }
        else
        {
            painter->drawPixmap(itsX, itsY, *itsSprite->at(0));
        }
    }
    else if(itsType == OBSTACLE)
    {
        painter->drawPixmap(itsX, itsY, *itsSprite->at(3));
    }
    else
    {
       painter->drawPixmap(itsX, itsY, *itsSprite->at(2));
    }
}

Block::Block( short x,  short y,  short height,  short width, std::array<QPixmap *, 4>* sprite,BlockType theBlockType)
    : Entity(x, y, height, width)
{
    itsType = theBlockType;
    itsSprite = sprite;
}
Block::Block( short x,  short y,  short height,  short width,BlockType theBlockType)
    : Entity(x, y, height, width)
{
    itsType = theBlockType;
}

Block::~Block() {}

