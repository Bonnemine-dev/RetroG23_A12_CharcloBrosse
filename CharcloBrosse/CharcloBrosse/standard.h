/**
 * @file standard.h
 * @brief Header file for class Standard
 * @date 05/06/2023
 * @version 2.0
 */

#ifndef STANDARD_H
#define STANDARD_H

#include "enemy.h"

/**
 * @class Standard
 * @brief Class representing a standard enemy in a game.
 * This class inherits from the Enemy class and represents a specific type of enemy, the Standard enemy.
 * @date June 2023
 * @see Enemy
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see EnemyType
 */
class Standard : public Enemy
{
private:
    static std::array<QPixmap *,12>* itsSpritesList; /** @brief the list of the standard sprites * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
public:
    /**
     * @brief Constructor of the Standard class.
     * @param height Height of the standard enemy.
     * @param width Width of the standard enemy.
     * @param theSpritesList the list of the standard sprites
     */
    Standard(short height,  short width, std::array<QPixmap *,12>* theSpritesList);
    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    void display(QPainter *painter);
};

#endif // STANDARD_H

