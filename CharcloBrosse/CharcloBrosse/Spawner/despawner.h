#ifndef DESPAWNER_H
#define DESPAWNER_H

#include "spawner.h"
#include "../Entity/entity.h"
#include "../Entity/Enemy/enemy.h"

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
    Spawner * itsSpawner; ///< The associated spawner.
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
    Despawner(Spawner * spawner, unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap * sprite);

    /**
     * @brief Makes an enemy disappear.
     * @param enemy Pointer to the enemy to be despawned.
     */
    void disappear(Enemy * enemy);
};

#endif // DESPAWNER_H

