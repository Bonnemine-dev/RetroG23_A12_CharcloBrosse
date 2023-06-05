#ifndef PLAYER_H
#define PLAYER_H

#include <Entity/entity.h>

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
    unsigned short itsLivesNb = 0; ///< Number of lives the player has.
    short itsXSpeed = 0; ///< Speed of the player on the X axis.
    short itsYSpeed = 0; ///< Speed of the player on the Y axis.
    short itsMaxXSpeed = 0; ///< Maximum speed of the player on the X axis.
    short itsMaxYSpeed = 0; ///< Maximum speed of the player on the Y axis.
    bool itsState = true; ///< State of the player.
public:
    /**
     * @brief Constructor of the Player class.
     * @param x X coordinate of the player.
     * @param y Y coordinate of the player.
     * @param height Height of the player.
     * @param width Width of the player.
     * @param sprite Sprite used for the player.
     */
    Player(int x, int y, int height, int width, Sprite* sprite);

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
};

#endif // PLAYER_H
