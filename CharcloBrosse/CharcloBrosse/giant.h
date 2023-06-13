/**
 * @file giant.cpp
 * @brief Header file for class Giant
 * @author Tom Bonneau
 * @date 10/06/2023
 * @version 2.0
 */

#ifndef GIANT_H
#define GIANT_H

#include "enemy.h"

/**
 * @class Giant
 * @brief Class representing a Giant enemy in a game.
 * This class inherits from the Enemy class and represents a specific type of enemy, the Giant enemy.
 * @date June 2023
 */
class Giant : public Enemy
{
private:
    static std::array<QPixmap *,12>* itsSpritesList;
public:
    /**
     * @brief Constructor of the Giant class.
     * @param height Height of the Giant enemy.
     * @param width Width of the Giant enemy.
     * @param sprite Sprite used for the Giant enemy.
     */
    Giant(short height,  short width, std::array<QPixmap *,12>* theSpritesList);
    void display(QPainter *painter);
};

#endif // GIANT_H
