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
    static std::array<QPixmap *,12>* itsSpritesList; /** @brief the list of the accelerator sprites * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
    bool jump = false; /** @brief the enenmy iss jumping : true or false */
    unsigned short itsJumpTime = DISTANCE_JUMPER_JUMP*BLOCK_SIZE; /** @brief the maximum jump distance */
    unsigned short itsRemaningJumpMove = 0; /** @brief the remaining jump move */
public:
    /**
     * @brief Constructor of the Standard class.
     * @param height Height of the standard enemy.
     * @param width Width of the standard enemy.
     * @param sprite Sprite used for the standard enemy.
     */
    Jumper(short height,  short width, std::array<QPixmap *,12>* theSpritesList);
    /**
     * @brief move the enemy on the screen and on the game
     */
    void move();
    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    void display(QPainter *painter);
    /**
     * @brief getJump get the jump state of the enemy
     * @return the jump state : true if the enemy is jumping, false else
     */
    bool getJump() const;
};

#endif // JUMPER_H
