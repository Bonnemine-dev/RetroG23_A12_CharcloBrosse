/**
 * @file player.h
 * @brief Header file for class Player
 * @author Tom Bonneau
 * @date 07/06/2023
 * @version 1.3
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "typedef.h"

/**
 * @class Player
 * @brief Class representing a player entity in a game.
 * This class inherits from the Entity class and provides additional characteristics
 * for a player entity, including speed in both X and Y directions, maximum speed, a state, and the number of lives.
 * It also provides methods for getting and setting these attributes, and for moving the player.
 * @date June 2023
 */
class Player : public Entity
{
private:
     short itsLivesNb = 0; ///< Number of lives the player has.
    short itsXSpeed = 0; ///< Speed of the player on the X axis.
    short itsYSpeed = 0; ///< Speed of the player on the Y axis.
    bool isOnTheGround = false; ///< True is the player is on the ground .
    unsigned short itsRemaningJumpMove = 0;
    MoveX itsCurrentMove = NONE;
    MoveX itsNextMove = NONE;
    //short itsMaxXSpeed = 0; ///< Maximum speed of the player on the X axis.
    //short itsMaxYSpeed = 0; ///< Maximum speed of the player on the Y axis.
    //bool itsState = true; ///< State of the player.
public:
    /**
     * @brief Constructor of the Player class.
     * @param x X coordinate of the player.
     * @param y Y coordinate of the player.
     * @param height Height of the player.
     * @param width Width of the player.
     * @param sprite QPixmap sprite used for the player.
     */
    Player( short x,  short y,  short height,  short width, QPixmap * sprite);

    /**
     * @brief Gets the state of the player.
     * @return The state of the player.
     */
    bool getItsState() const;

    /**
     * @brief Moves the player.
     */
    void move();

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

    unsigned short getItsRemaningJumpMove() const;
    void setItsRemaningJumpMove(unsigned short newItsRemaningJumpMove);
    void setItsCurrentMove(MoveX newItsCurrentMove);
    void setItsNextMove(MoveX newItsNextMove);
};

#endif // PLAYER_H
