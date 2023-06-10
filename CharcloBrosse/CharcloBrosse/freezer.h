/**
 * @file freezer.cpp
 * @brief Header file for class Freezer
 * @author Tom Bonneau
 * @date 10/06/2023
 * @version 2.0
 */

#ifndef FREEZER_H
#define FREEZER_H

#include "enemy.h"

/**
 * @class Freezer
 * @brief Class representing a Freezer enemy in a game.
 * This class inherits from the Enemy class and represents a specific type of enemy, the Freezer enemy.
 * @date June 2023
 */
class Freezer : public Enemy
{
public:
    /**
     * @brief Constructor of the Freezer class.
     * @param height Height of the Freezer enemy.
     * @param width Width of the Freezer enemy.
     * @param sprite Sprite used for the Freezer enemy.
     */
    Freezer(short height,  short width, QPixmap * sprite);
};

#endif // FREEZER_H
