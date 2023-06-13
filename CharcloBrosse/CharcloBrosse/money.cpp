/**
 * @file money.cpp
 * @brief Source file for class Money
 * @author Tom Bonneau
 * @date 10/06/2023
 * @version 2.0
 */

#include "money.h"

std::array<std::array<QPixmap*, 2>*, 3>* Money::itsSpritesList = nullptr;

//Getter pour itsMoneyType
MoneyType Money::getItsMoneyType() const
{
    return itsMoneyType;
}

//Constructeur de Money
Money::Money(MoneyType type, short x,  short y,  short height,  short width, std::array<std::array<QPixmap*, 2>*, 3>* theSpritesList)
        : Entity(x, y, height, width)
{
    itsSpritesList = theSpritesList;
    itsMoneyType = type;
}
void Money::display(QPainter *painter)
{
    if((((*itsLoopCounter/(NUMBER_LOOP_PER_SECOND/FPS))*(NUMBER_LOOP_PER_SECOND/FPS))/TIME_FOR_ANIMATION_CYCLE)%(NUMBER_IMAGE_PER_ANIMATION)  == 0){
        switch (itsMoneyType) {
        case RED:
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0)->at(0));
            break;
        case YELLOW:
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1)->at(0));
            break;
        case BILL:
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(2)->at(0));
            break;
        default:
            break;
        }
    }
    else
    {
        switch (itsMoneyType) {
        case RED:
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(0)->at(1));
            break;
        case YELLOW:
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(1)->at(1));
            break;
        case BILL:
            painter->drawPixmap(itsX, itsY, *itsSpritesList->at(2)->at(1));
            break;
        default:
            break;
        }
    }
}
