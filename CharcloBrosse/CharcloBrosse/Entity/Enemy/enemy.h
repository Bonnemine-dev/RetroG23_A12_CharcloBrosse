#ifndef ENEMY_H
#define ENEMY_H

#include <QPixmap>

#include <Entity/entity.h>

enum EnemyType {STANDARD=100, ACCELERATOR=200, JUMPER=300, GIANT=400, FREEZER=500};

/**
 * @class Enemy
 * @brief Class representing an enemy entity in a game.
 * This class inherits from the Entity class and provides additional characteristics
 * for an enemy entity, including speed in both X and Y directions, a state, and a type.
 * @date June 2023
 */
class Enemy : public Entity
{
protected:
    short itsXSpeed = 0; ///< Speed of the enemy on the X axis.
    short itsYSpeed = 0; ///< Speed of the enemy on the Y axis.
    bool itsState = true; ///< State of the enemy.
    EnemyType itsType; ///< Type of the enemy.
    bool isOnTheGround = true;
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
    Enemy(unsigned short height, unsigned short width, QPixmap * sprite);
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
};

#endif // ENEMY_H

