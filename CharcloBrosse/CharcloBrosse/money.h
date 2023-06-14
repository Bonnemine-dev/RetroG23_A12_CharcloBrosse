/**
 * @file money.h
 * @brief Header file for class Money
 * @date 10/06/2023
 * @version 2.0
 */

#ifndef MONEY_H
#define MONEY_H

#include "entity.h"
#include "typedef.h"

/**
 * @class Money
 * @brief Class representing money objects in the game.
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see MoneyType
 */
class Money : public Entity
{
private:
    static std::array<std::array<QPixmap*, 2>*, 3>* itsSpritesList; /** @brief the list of all the sprites of the money @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a> */
    MoneyType itsMoneyType; /** @brief The type of money. * @see MoneyType*/

public:
    /**
     * @brief Constructor for Money class.
     * @param type The type of money.
     * @param x The x-coordinate of the money object.
     * @param y The y-coordinate of the money object.
     * @param height The height of the money object.
     * @param width The width of the money object.
     * @param theSpritesList the list of all the sprites of the money
     * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
     */
    Money(MoneyType type, short x, short y, short height, short width, std::array<std::array<QPixmap*, 2>*, 3>* theSpritesList);

    /**
     * @brief Getter for the money type.
     * @return The type of money.
     * @see MoneyType
     */
    MoneyType getItsMoneyType() const;
    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    void display(QPainter *painter);
};

#endif // MONEY_H
