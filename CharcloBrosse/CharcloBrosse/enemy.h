/**
 * @file enemy.h
 * @brief Header file for class Enemy
 * @date 06/06/2023
 * @version 2.0
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <QPixmap>
#include "typedef.h"
#include "entity.h"


/**
 * @class Enemy
 * @brief Abstract Class representing an enemy entity in a game.
 * This class inherits from the Entity class and provides additional characteristics
 * for an enemy entity, including speed in both X and Y directions, a state, and a type.
 * @date June 2023
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see EnemyType
 */
class Enemy : public Entity
{
protected:
    short itsXSpeed = 0; /** @brief Speed of the enemy on the X axis. */
    short itsYSpeed = 0; /** @brief Speed of the enemy on the Y axis. */
    bool itsState = true; /** @brief State of the enemy. */
    short itsNumberLoopKO = 0; /** @brief The number of loop passed where the enemy is KO */
    EnemyType itsType; /** * @brief Type of the enemy. * @see EnemyType */
    bool isOnTheGround = true; /** * @brief True is the player is on the ground . */
public:
    /**
     * @brief Constructor of the Enemy class.
     * @param type Type of the enemy.
     * @param x X coordinate of the enemy.
     * @param y Y coordinate of the enemy.
     * @param height Height of the enemy.
     * @param width Width of the enemy.
     * @param sprite QPixmap sprite used for the enemy.
     */
    Enemy( short height,  short width);

    /**
     * @brief The virtual destructor of the Enemy class
     */
    virtual ~Enemy(); // Ajoutez un destructeur virtuel

    /**
     * @brief Display the current sprite at the screen
     * @param painter A pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    virtual void display(QPainter * painter);

    /**
     * @brief Gets the speed of the enemy on the X axis.
     * @return The speed on the X axis.
     */
    short getItsXSpeed() const;

    /**
     * @brief Gets the speed of the enemy on the Y axis.
     * @return The speed on the Y axis.
     */
    short getItsYSpeed() const;

    /**
     * @brief Gets the state of the enemy.
     * @return The state of the enemy.
     */
    bool getItsState() const;

    /**
     * @brief Gets the type of the enemy.
     * @return The type of the enemy.
     * @see EnemyType
     */
    EnemyType getItsType() const;

    /**
     * @brief Sets the speed of the enemy on the X axis.
     * @param newItsXSpeed The new speed on the X axis.
     */
    void setItsXSpeed(short newItsXSpeed);

    /**
     * @brief Sets the speed of the enemy on the Y axis.
     * @param newItsYSpeed The new speed on the Y axis.
     */
    void setItsYSpeed(short newItsYSpeed);

    /**
     * @brief Sets the state of the enemy.
     * @param newItsState The new state of the enemy.
     */
    void setItsState(bool newItsState);

    /**
     * @brief Change the coorfinates of the enemy
     */
    void move();

    /**
     * @brief Sets the "is on the ground" status of the entity.
     * @param newIsOnTheGround The new "is on the ground" status.
     */
    void setIsOnTheGround(bool newIsOnTheGround);

    /**
     * @brief Gets the "is on the ground" status of the entity.
     * @return The "is on the ground" status.
     */
    bool getIsOnTheGround() const;
    /**
     * @brief Gets the number of loop where the enemy is KO
     * @return "itsNumberLoopKO"
     */
    short getItsNumberLoopKO() const;
    /**
     * @brief Sets the "itsNumberLoopKO" of the entity.
     * @param newItsNumberLoopKO The new "itsNumberLoopKO" status.
     */
    void setItsNumberLoopKO(short newItsNumberLoopKO);
};

#endif // ENEMY_H

