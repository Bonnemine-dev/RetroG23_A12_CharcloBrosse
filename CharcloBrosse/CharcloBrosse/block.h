/**
 * @file block.h
 * @brief Header file for class Block
 * @author Tom Bonneau
 * @date 09/06/2023
 * @version 1.3
 */

#ifndef BLOCK_H
#define BLOCK_H

#include "entity.h"
#include "typedef.h"

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
    BlockType itsType;
    static std::array<QPixmap*, 6>* itsSpritesList; ///< ----------refaire-------------------refaire-------------------refaire---------
public:
    /**
     * @brief Constructor of the Block class.
     * @param x X coordinate of the block.
     * @param y Y coordinate of the block.
     * @param height Height of the block.
     * @param width Width of the block.
     * @param sprite QPixmap sprite used for the block.
     */
    Block(short x,  short y,  short height,  short width, std::array<QPixmap *, 6>* theSpritesList, BlockType theBlockType);
    Block( short x,  short y,  short height,  short width, BlockType theBlockType);

    virtual ~Block();

    /**
     * @brief Gets the state of the block.
     * @return The state of the block.
     */
    bool getItsState() const;
    void display(QPainter *painter);
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
    void setItsCounter(unsigned short newItsCounter);
    BlockType getItsType() const;
};

#endif // BLOCK_H

