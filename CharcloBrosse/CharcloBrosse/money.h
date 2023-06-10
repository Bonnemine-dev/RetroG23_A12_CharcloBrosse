/**
 * @file money.h
 * @brief Header file for class Money
 * @author Tom Bonneau
 * @date 10/06/2023
 * @version 2.0
 */

#ifndef MONEY_H
#define MONEY_H

#include "entity.h"

/**
 * @enum MoneyType
 * @brief Enumeration representing the types of money.
 */
enum MoneyType {RED = 100, YELLOW = 250, BILL = 500};

/**
 * @class Money
 * @brief Class representing money objects in the game.
 */
class Money : public Entity
{
    MoneyType itsMoneyType; /**< The type of money. */

public:
    /**
     * @brief Constructor for Money class.
     * @param type The type of money.
     * @param x The x-coordinate of the money object.
     * @param y The y-coordinate of the money object.
     * @param height The height of the money object.
     * @param width The width of the money object.
     * @param sprite The sprite image of the money object.
     */
    Money(MoneyType type, short x, short y, short height, short width, QPixmap *sprite);

    /**
     * @brief Getter for the money type.
     * @return The type of money.
     */
    MoneyType getItsMoneyType() const;
};

#endif // MONEY_H

