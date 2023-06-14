/**
 * @file desspawner.h
 * @brief Header file for class Despawner
 * @date 06/06/2023
 * @version 2.0
 */

#ifndef DESPAWNER_H
#define DESPAWNER_H

#include "spawner.h"
#include "entity.h"
#include "enemy.h"

/**
 * @class Despawner
 * @brief Class representing a despawner entity in a game.
 * This class inherits from the Entity class and provides additional functionality
 * for despawning enemies that come in contact with it.
 * It has an associated spawner and can make enemies disappear.
 * @date June 2023
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see Spawner
 * @see Direction
 * @see Enemy
 */
class Despawner : public Entity
{
private:
    Direction itsDirection; /** * @brief itsDirection the direction of the Despawner * @see Direction */
    Spawner * itsSpawner; /** @brief itsSpawner The associated spawner. @see Spawner*/
    static std::array<QPixmap *,2>* itsSpritesList; /** @brief itsSpriteList the list containings all the sprite of the dispawner * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
public:
    /**
     * @brief Constructor of the Despawner class.
     * @param spawner Pointer to the associated spawner.
     * @param x X coordinate of the despawner.
     * @param y Y coordinate of the despawner.
     * @param height Height of the despawner.
     * @param width Width of the despawner.
     * @param sprite Sprite used for the despawner.
     * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
     * @see Spawner
     * @see Enemy
     * @see Direction
     */
    Despawner(Spawner * spawner,  short x,  short y,  short height,  short width, std::array<QPixmap *,2>* theSpritesList, Direction theDirection);

    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html>QPainter</a>
     */
    void display(QPainter *painter);

    /**
     * @brief Makes an enemy disappear.
     * @param enemy Pointer to the enemy to be despawned.
     * @see Enemy
     */
    void disappear(Enemy * enemy);
};

#endif // DESPAWNER_H

