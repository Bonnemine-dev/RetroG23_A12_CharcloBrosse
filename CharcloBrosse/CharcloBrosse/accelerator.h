/**
 * @file accelerator.h
 * @brief Header file for class Accelerator
 * @date 05/06/2023
 * @version 2.0
 */

#ifndef ACCELERATOR_H
#define ACCELERATOR_H

#include "enemy.h"

/**
 * @class Accelerator
 * @brief Class representing an accelerator enemy in a game.
 * This class inherits from the Enemy class and represents a specific type of enemy, the Accelerator enemy.
 * @date June 2023
 * @see Enemy
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see EnemyType
 */
class Accelerator : public Enemy
{
private:
    static std::array<std::array<QPixmap *,12>*, 3>* itsSpritesList; /** @brief the list of the accelerator sprites * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
    short itsSpeedState = 1; /**  @brief The Speed State when accelerator comes up. */
    bool acceleratorDown = false;/**  @brief Boolean which say if an accelerator is down or no, necessary to avoid a bug. */
public:
    /**
     * @brief Constructor of the Accelerator class.
     * @param height Height of the accelerator enemy.
     * @param width Width of the accelerator enemy.
     * @param sprite Sprite used for the accelerator enemy.
     * @see Enemy::Enemy
     */
    Accelerator(short height,  short width, std::array<std::array<QPixmap *,12>*, 3>* theSpritesList);
    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    void display(QPainter *painter);
    /**
     * @brief addItsSpeedState accelerate the enemy
     */
    void addItsSpeedState();
    /**
     * @brief getItsSpeedState get the actual acceleration of the enemy
     * @return the current acceleration state
     */
    short getItsSpeedState() const;
    /**
     * @brief setAcceleratorDown set if the accelerator is down or not
     * @param newAcceleratorDown the new state of the accelerator
     */
    void setAcceleratorDown(bool newAcceleratorDown);
    /**
     * @brief getAcceleratorDown tell if the acccelertor is down or not
     * @return ture if the accelerator is odwn, false else
     */
    bool getAcceleratorDown() const;
};

#endif // ACCELERATOR_H
