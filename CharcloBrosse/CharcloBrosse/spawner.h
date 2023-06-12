/**
 * @file spawner.h
 * @brief Header file for class Spawner
 * @author Tom Bonneau
 * @date 06/06/2023
 * @version 1.2
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
 */
class Spawner : public Entity
{
public:
    /**
     * @brief Constructor of the Spawner class.
     * @param x X coordinate of the spawner.
     * @param y Y coordinate of the spawner.
     * @param height Height of the spawner.
     * @param width Width of the spawner.
     * @param sprite Sprite used for the spawner.
     */
    Spawner( short x,  short y,  short height,  short width, QPixmap * sprite);

    /**
     * @brief Makes an enemy appear at the spawner's location.
     * @param enemy Pointer to the enemy to be spawned.
     */
    void appears(Enemy * enemy);
};

#endif // SPAWNER_H

