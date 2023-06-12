/**
 * @file accelerator.h
 * @brief Header file for class Accelerator
 * @author Tom Bonneau
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
 */
class Accelerator : public Enemy
{
    short itsSpeedState = 0; ///< The Speed State when accelerator comes up.
public:
    /**
     * @brief Constructor of the Accelerator class.
     * @param height Height of the accelerator enemy.
     * @param width Width of the accelerator enemy.
     * @param sprite Sprite used for the accelerator enemy.
     */
    Accelerator(short height,  short width, QPixmap * sprite);

    /**
     * @brief upSpeed method is called when the accelerator is raised in order to increase its speed.
     */
    void upSpeed();
};

#endif // ACCELERATOR_H
