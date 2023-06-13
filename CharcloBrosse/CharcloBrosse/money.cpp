/**
 * @file money.cpp
 * @brief Source file for class Money
 * @author Tom Bonneau
 * @date 10/06/2023
 * @version 2.0
 */

#include "money.h"

//Getter pour itsMoneyType
MoneyType Money::getItsMoneyType() const
{
    return itsMoneyType;
}

//Constructeur de Money
Money::Money(MoneyType type, short x,  short y,  short height,  short width, QPixmap *sprite)
        : Entity(x, y, height, width, sprite)
{
    itsMoneyType = type;
}
