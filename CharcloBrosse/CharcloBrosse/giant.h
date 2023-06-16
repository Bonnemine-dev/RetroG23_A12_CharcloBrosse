/**
 * @file giant.cpp
 * @brief Header file for class Giant
 * @date 10/06/2023
 * @version 2.0
 */

#ifndef GIANT_H
#define GIANT_H

#include "enemy.h"

/**
 * @class Giant
 * @brief Class representing a Giant enemy in a game.
 * This class inherits from the Enemy class and represents a specific type of enemy, the Giant enemy.
 * @date June 2023
 * @see Enemy
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see EnemyType
 */
class Giant : public Enemy
{
private:
    static std::array<QPixmap *,12>* itsSpritesList; /** @brief the list of the accelerator sprites * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
public:
    /**
     * @brief Constructor of the Giant class.
     * @param height Height of the Giant enemy.
     * @param width Width of the Giant enemy.
     * @param theSpritesList the list containings all the sprites of the giant enemy
     * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
     */
    Giant(short height,  short width, std::array<QPixmap *,12>* theSpritesList);
    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    void display(QPainter *painter);
};

#endif // GIANT_H
