#ifndef SPRITE_H
#define SPRITE_H

#include <QPixmap>
#include <QPainter>

/**
 * @class Sprite
 * @brief Class representing a Sprite in a game.
 * This class provides a way to manage game sprites, including displaying and moving them.
 * Each sprite has an associated image, position (X and Y coordinates), and dimensions (height and width).
 * @date June 2023
 */
class Sprite
{
private:
    QPixmap * itsImage; ///< Image of the sprite.
    unsigned short itsX; ///< X-coordinate of the sprite.
    unsigned short itsY; ///< Y-coordinate of the sprite.
    unsigned short itsHeight; ///< Height of the sprite.
    unsigned short itsWidth; ///< Width of the sprite.
public:
    /**
     * @brief Constructor of the Sprite class.
     * @param image Image of the sprite.
     */
    Sprite(QPixmap * image);

    /**
     * @brief Displays the sprite.
     * @param painter QPainter object to paint the sprite.
     */
    void display(QPainter * painter);

    /**
     * @brief Moves the sprite to the given coordinates.
     * @param x The X-coordinate to move the sprite to.
     * @param y The Y-coordinate to move the sprite to.
     */
    void moveTo(unsigned short x, unsigned short y);
};

#endif // SPRITE_H

