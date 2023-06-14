/**
 * @file spawner.h
 * @brief Header file for class Spawner
 * @date 06/06/2023
 * @version 2.0
 */

#ifndef SPAWNER_H
#define SPAWNER_H

#include "entity.h"
#include "enemy.h"

/**
 * @class Spawner
 * @brief Class representing a spawner entity in a game.
 * This class inherits from the Entity class and provides functionality
 * for spawning enemies at its location.
 * It can make enemies appear at its location when called upon.
 * It is associated with a specific sprite and has its own position and dimensions.
 * @date June 2023
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see Direction
 */
class Spawner : public Entity
{
private:
    Direction itsDirection; /** @brief the direction of the spawner * @see Direction */
    static std::array<QPixmap *,2>* itsSpritesList; /** @brief the list of the spawners sprites * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
public:
    /**
     * @brief Constructor of the Spawner class.
     * @param x X coordinate of the spawner.
     * @param y Y coordinate of the spawner.
     * @param height Height of the spawner.
     * @param width Width of the spawner.
     * @param theSpritesList the list of the spawners sprites
     * @param theDirection the direction of the spawner
     * @see Direction
     * @see <a href="https://doc.qt.io/qt-6/qpixmap.html">QPixMap</a>
     */
    Spawner( short x,  short y,  short height,  short width, std::array<QPixmap *,2>* theSpritesList, Direction theDirection);
    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    void display(QPainter *painter);

    /**
     * @brief Makes an enemy appear at the spawner's location.
     * @param enemy Pointer to the enemy to be spawned.
     * @see Enemy
     */
    void appears(Enemy * enemy);
};

#endif // SPAWNER_H

