/**
 * @file player.h
 * @brief Header file for class Player
 * @date 07/06/2023
 * @version 2.0
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "typedef.h"
#include <array>

/**
 * @class Player
 * @brief Class representing a player entity in a game.
 * This class inherits from the Entity class and provides additional characteristics
 * for a player entity, including speed in both X and Y directions, maximum speed, a state, and the number of lives.
 * It also provides methods for getting and setting these attributes, and for moving the player.
 * @date June 2023
 *
 */
class Player : public Entity
{
private:
    short itsLivesNb = 0; /** @brief Number of lives the player has. */
    short itsXSpeed = 0; /** @brief Speed of the player on the X axis. */
    short itsYSpeed = 0; /** @brief Speed of the player on the Y axis. */
    bool isOnTheGround = false; /** @brief True is the player is on the ground .*/
    unsigned short itsRemaningJumpMove = 0; /** @brief the jump size counter */
    unsigned short itsRemaningFallMove = 0xFFFF; /** @brief The number of pixels that the player have to make make befor the max gravity speed*/
    unsigned short itsRemaningWalkMove = 0; /** @brief The number of pixels that the player have to walk before the max speed for the walking speed*/
    unsigned short itsRemaningComboTicks = 0; /** @brief the combo ticks counter */
    unsigned short comboValue = 0; /** The number of ennemies that the player killed in combo mode*/
    MoveX itsCurrentMove = NONE; /** @brief the current move on the X axis */
    MoveX itsNextMove = NONE; /** @brief the next move on the X axis */
    static std::array<QPixmap*, 12>* itsSpritesList; /** @brief the list of the Player sprites * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
    bool isFrozen = false;/** @brief Boolean which say if player is freeze by freezer or no.*/
    unsigned short int startFreeze;/** @brief Time when start player freeze.*/

public:
    /**
     * @brief Constructor of the Player class.
     * @param x X coordinate of the player.
     * @param y Y coordinate of the player.
     * @param height Height of the player.
     * @param width Width of the player.
     * @param theSpritesList the list of the Player sprites
     * @param theLoopCounter the current loop counter of the game
     */
    Player(short x,  short y,  short height,  short width, std::array<QPixmap*, 12>* theSpritesList,unsigned short* theLoopCounter);

    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
    void display(QPainter *painter);
     /**
     * @brief Gets the state of the player.
     * @return The state of the player.
     */
    bool getItsState() const;

    /**
     * @brief Moves the player on ordinate.
     */
    void moveX();

    /**
     * @brief Moves the player on abscisse.
     */
    void moveY();
    /**
     * @brief Sets the speed of the player on the X axis.
     * @param newItsXSpeed The new speed on the X axis.
     */
    void setItsXSpeed(short newItsXSpeed);

    /**
     * @brief Sets the speed of the player on the Y axis.
     * @param newItsYSpeed The new speed on the Y axis.
     */
    void setItsYSpeed(short newItsYSpeed);

    /**
     * @brief Sets the number of lives the player has.
     * @param newItsLivesNb The new number of lives.
     */
    void setItsLivesNb(unsigned short newItsLivesNb);

    /**
     * @brief Gets the number of lives the player has.
     * @return The number of lives.
     */

    unsigned short getItsLivesNb() const;
    /**
     * @brief Gets the speed of the entity on the X axis.
     * @return The speed on the X axis.
     */
    short getItsXSpeed() const;

    /**
     * @brief Gets the speed of the entity on the Y axis.
     * @return The speed on the Y axis.
     */
    short getItsYSpeed() const;

    /**
     * @brief Sets the "is on the ground" status of the entity.
     * @param newIsOnTheGround The new "is on the ground" status.
     */
    void setIsOnTheGround(bool newIsOnTheGround);

    /**
     * @brief Gets the "is on the ground" status of the entity.
     * @return The "is on the ground" status.
     */
    bool getIsOnTheGround() const;
    /**
     * @brief getItsRemaningJumpMove gets the remaining size of the jump
     * @return itsRemaningJumpMove
     */
    unsigned short getItsRemaningJumpMove() const;
    /**
     * @brief setItsRemaningJumpMove sets the reamaining size of the jump
     * @param newItsRemaningJumpMove the new remaining size of the jump
     */
    void setItsRemaningJumpMove(unsigned short newItsRemaningJumpMove);
    /**
     * @brief setItsCurrentMove sets the current move of the player
     * @param newItsCurrentMove the new movement of the player
     */
    void setItsCurrentMove(MoveX newItsCurrentMove);
    /**
     * @brief setItsNextMove sets the next move of the player
     * @param newItsNextMove the new next move of the player
     */
    void setItsNextMove(MoveX newItsNextMove);
    /**
     * @brief getItsAnimCounter gets the animation counter of the player
     * @return the current counter of the animation
     */
    short getItsAnimCounter() const;
    /**
     * @brief setItsAnimCounter sets the animation counter
     * @param newItsAnimCounter the new animation counter
     */
    void setItsAnimCounter(short newItsAnimCounter);

    /**
 * @brief Retrieves the value of itsRemaningComboTicks.
 * @return The value of itsRemaningComboTicks.
 */
    unsigned short getItsRemaningComboTicks() const;

    /**
 * @brief Sets the value of itsRemaningComboTicks.
 * @param newItsRemaningComboTicks The new value of itsRemaningComboTicks.
 */
    void setItsRemaningComboTicks(unsigned short newItsRemaningComboTicks);

    /**
 * @brief Retrieves the value of ComboValue.
 * @return The value of ComboValue.
 */
    unsigned short getComboValue() const;

    /**
 * @brief Sets the value of ComboValue.
 * @param newComboValue The new value of ComboValue.
 */
    void setComboValue(unsigned short newComboValue);

    /**
 * @brief Retrieves the value of itsRemaningFallMove.
 * @return The value of itsRemaningFallMove.
 */
    unsigned short getItsRemaningFallMove() const;

    /**
 * @brief Sets the value of itsRemaningFallMove.
 * @param newItsRemaningFallMove The new value of itsRemaningFallMove.
 */
    void setItsRemaningFallMove(unsigned short newItsRemaningFallMove);

    /**
 * @brief Sets the value of itsRemaningWalkMove.
 * @param newItsRemaningWalkMove The new value of itsRemaningWalkMove.
 */
    void setItsRemaningWalkMove(unsigned short newItsRemaningWalkMove);

    /**
 * @brief Retrieves the value of itsRemaningWalkMove.
 * @return The value of itsRemaningWalkMove.
 */
    unsigned short getItsRemaningWalkMove() const;

    /**
 * @brief Sets the value of isFrozen.
 * @param newIsFrozen The new value of isFrozen.
 */
    void setIsFrozen(bool newIsFrozen);

    /**
 * @brief Retrieves the value of isFrozen.
 * @return The value of isFrozen.
 */
    bool getIsFrozen() const;

    /**
 * @brief Sets the value of startFreeze.
 * @param newStartFreeze The new value of startFreeze.
 */
    void setStartFreeze(unsigned short newStartFreeze);

    /**
 * @brief Retrieves the value of startFreeze.
 * @return The value of startFreeze.
 */
    unsigned short getStartFreeze() const;
};

#endif // PLAYER_H
