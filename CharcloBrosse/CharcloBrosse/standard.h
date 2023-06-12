/**
 * @file standard.h
 * @brief Header file for class Standard
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */

#ifndef STANDARD_H
#define STANDARD_H

#include "enemy.h"

/**
 * @class Standard
 * @brief Class representing a standard enemy in a game.
 * This class inherits from the Enemy class and represents a specific type of enemy, the Standard enemy.
 * @date June 2023
 */
class Standard : public Enemy
{
public:
    /**
     * @brief Constructor of the Standard class.
     * @param height Height of the standard enemy.
     * @param width Width of the standard enemy.
     * @param sprite Sprite used for the standard enemy.
     */
    Standard(short height,  short width, QPixmap * sprite);
};

#endif // STANDARD_H
