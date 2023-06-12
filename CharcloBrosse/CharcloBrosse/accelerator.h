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
private:
    static std::array<std::array<QPixmap *,12>*, 3>* itsSprite;
    short itsSpeedState = 1; ///< The Speed State when accelerator comes up.
public:
    /**
     * @brief Constructor of the Accelerator class.
     * @param height Height of the accelerator enemy.
     * @param width Width of the accelerator enemy.
     * @param sprite Sprite used for the accelerator enemy.
     */
    Accelerator(short height,  short width, std::array<std::array<QPixmap *,12>*, 3>* sprite);
    void display(QPainter *painter);
    void addItsSpeedState();
    short getItsSpeedState() const;
};

#endif // ACCELERATOR_H
