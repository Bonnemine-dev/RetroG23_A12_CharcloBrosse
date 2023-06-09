#ifndef BLOCK_H
#define BLOCK_H

#include "entity.h"

/**
 * @class Block
 * @brief Class representing a block entity in a game.
 * This class inherits from the Entity class and provides additional characteristics
 * for a block entity, including a state and a counter.
 * It also provides methods for getting and setting these attributes, and for incrementing the counter.
 * @date June 2023
 */
class Block : public Entity
{
private:
    bool itsState = false; ///< State of the block.
    unsigned short itsCounter = 0; ///< Counter associated with the block.
public:
    /**
     * @brief Constructor of the Block class.
     * @param x X coordinate of the block.
     * @param y Y coordinate of the block.
     * @param height Height of the block.
     * @param width Width of the block.
     * @param sprite QPixmap sprite used for the block.
     */
    Block( short x,  short y,  short height,  short width, QPixmap * sprite);

    /**
     * @brief Gets the state of the block.
     * @return The state of the block.
     */
    bool getItsState() const;

    /**
     * @brief Sets the state of the block.
     * @param newItsState The new state of the block.
     */
    void setItsState(bool newItsState);

    /**
     * @brief Increments the block's counter.
     */
    void increment();

    /**
     * @brief Gets the counter associated with the block.
     * @return The counter.
     */
    unsigned short getItsCounter() const;
};

#endif // BLOCK_H

