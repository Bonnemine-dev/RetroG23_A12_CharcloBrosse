#ifndef ENEMY_H
#define ENEMY_H

#include <Entity/entity.h>

enum EnemyType {Standard=100, Accelerator=200, Jumper=300, Giant=400, Freezer=500};

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
public:
    /**
     * @brief Constructor of the Enemy class.
     * @param type Type of the enemy.
     * @param x X coordinate of the enemy.
     * @param y Y coordinate of the enemy.
     * @param height Height of the enemy.
     * @param width Width of the enemy.
     * @param sprite Sprite used for the enemy.
     */
    Enemy(EnemyType type, int x, int y, int height, int width, Sprite* sprite);
};

#endif // ENEMY_H

