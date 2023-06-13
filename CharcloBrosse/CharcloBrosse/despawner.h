/**
 * @file desspawner.h
 * @brief Header file for class Despawner
 * @author Tom Bonneau
 * @date 06/06/2023
 * @version 1.2
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
 */
class Despawner : public Entity
{
private:
    Direction itsDirection;
    Spawner * itsSpawner; ///< The associated spawner.
    static std::array<QPixmap *,2>* itsSpritesList;
public:
    /**
     * @brief Constructor of the Despawner class.
     * @param spawner Pointer to the associated spawner.
     * @param x X coordinate of the despawner.
     * @param y Y coordinate of the despawner.
     * @param height Height of the despawner.
     * @param width Width of the despawner.
     * @param sprite Sprite used for the despawner.
     */
    Despawner(Spawner * spawner,  short x,  short y,  short height,  short width, std::array<QPixmap *,2>* theSpritesList, Direction theDirection);
    void display(QPainter *painter);

    /**
     * @brief Makes an enemy disappear.
     * @param enemy Pointer to the enemy to be despawned.
     */
    void disappear(Enemy * enemy);
};

#endif // DESPAWNER_H

