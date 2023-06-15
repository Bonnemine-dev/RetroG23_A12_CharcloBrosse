/**
 * @file jumper.h
 * @brief Header file for class Jumper
 * @author Tom Bonneau
 * @date 14/06/2023
 * @version 3.0
 */

#ifndef JUMPER_H
#define JUMPER_H

#include "enemy.h"

/**
 * @class Standard
 * @brief Class representing a standard enemy in a game.
 * This class inherits from the Enemy class and represents a specific type of enemy, the Standard enemy.
 * @date June 2023
 */
class Jumper : public Enemy
{
private:
    static std::array<QPixmap *,12>* itsSpritesList;
    bool jump = false;
    unsigned short itsJumpTime = DISTANCE_JUMPER_JUMP*BLOCK_SIZE;
    unsigned short itsRemaningJumpMove = 0;
public:
    /**
     * @brief Constructor of the Standard class.
     * @param height Height of the standard enemy.
     * @param width Width of the standard enemy.
     * @param sprite Sprite used for the standard enemy.
     */
    Jumper(short height,  short width, std::array<QPixmap *,12>* theSpritesList);
    void move();
    void display(QPainter *painter);
    bool getJump() const;
};

#endif // JUMPER_H
