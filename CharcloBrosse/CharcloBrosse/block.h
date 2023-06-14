/**
 * @file block.h
 * @brief Header file for class Block
 * @date 09/06/2023
 * @version 2.0
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
 * @see Entity
 * @see <a href="https://doc.qt.io/qt-6/qrect.html" target="_blank">QRect</a>
 * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
 * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>
 * @see BlockType
 */
class Block : public Entity
{
private:
    bool itsState = false; /** @brief itsState State of the block. */
    unsigned short itsCounter = 0; /** * @brief itsCounter Counter associated with the block. */
    BlockType itsType; /** * @brief itsType the type of the block * @see BlockType */
    static std::array<QPixmap*, 6>* itsSpritesList; /** * @brief itsSpritesList * @see <a href="https://doc.qt.io/qt-6/qpixmap.html" target="_blank">QPixMap</a>*/
public:
    /**
     * @brief Constructor of the Block class.
     * @param x X coordinate of the block.
     * @param y Y coordinate of the block.
     * @param height Height of the block.
     * @param width Width of the block.
     * @param theSpritesList the list containings all the sprites of the block
     * @param theBlockType thtype of the block
     */
    Block(short x,  short y,  short height,  short width, std::array<QPixmap *, 6>* theSpritesList, BlockType theBlockType);
    /**
     * @brief Constructor of the Block class.
     * @param x X coordinate of the block.
     * @param y Y coordinate of the block.
     * @param height Height of the block.
     * @param width Width of the block.
     * @param theBlockType thtype of the block
     */
    Block( short x,  short y,  short height,  short width, BlockType theBlockType);

    /**
     * @brief ~Block the destructor of block class
     */
    virtual ~Block();

    /**
     * @brief Gets the state of the block.
     * @return The state of the block.
     */
    bool getItsState() const;

    /**
     * @brief display display the current sprite at the screen
     * @param painter a pointer to a painter associated to th screen where to display
     * @see <a href="https://doc.qt.io/qt-5/qpainter.html" target="_blank">QPainter</a>
     */
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
    /**
     * @brief setItsCounter set the counter associated with the block
     * @param newItsCounter the new counter
     */
    void setItsCounter(unsigned short newItsCounter);
    /**
     * @brief getItsType get the type of the block
     * @return
     */
    BlockType getItsType() const;
};

#endif // BLOCK_H

