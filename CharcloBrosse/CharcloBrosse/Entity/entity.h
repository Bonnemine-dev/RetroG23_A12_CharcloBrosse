#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include "../Sprite/sprite.h"

/**
 * @class Entity
 * @brief Class representing a game entity.
 * This class provides a generic representation for an entity in a game,
 * including its dimensions, position, and associated sprite.
 * It provides methods for getting entity's dimensions and for displaying the entity.
 * @date June 2023
 */
class Entity
{
protected:
    QRect itsRect; ///< Rectangle representing the entity's dimensions and position.
    Sprite * itsSprite; ///< Sprite associated with the entity.
public:
    /**
     * @brief Constructor of the Entity class.
     * @param x X coordinate of the entity.
     * @param y Y coordinate of the entity.
     * @param height Height of the entity.
     * @param width Width of the entity.
     * @param sprite QPixmap sprite used for the entity.
     */
    Entity(unsigned short x, unsigned short y, unsigned short height, unsigned short width, QPixmap *sprite);

    /**
     * @brief Gets the X coordinate of the entity.
     * @return The X coordinate.
     */
    unsigned short getItsX() const;

    /**
     * @brief Gets the Y coordinate of the entity.
     * @return The Y coordinate.
     */
    unsigned short getItsY() const;

    /**
     * @brief Gets the height of the entity.
     * @return The height.
     */
    unsigned short getItsHeight() const;

    /**
     * @brief Gets the width of the entity.
     * @return The width.
     */
    unsigned short getItsWidth() const;

    /**
     * @brief Displays the entity.
     * @param painter QPainter object used for painting.
     */
    void display(QPainter * painter);

    /**
     * @brief Gets the QRect object representing the entity's dimensions and position.
     * @return The QRect object.
     */
    QRect * getItsRect();

    /**
     * @brief Sets the X coordinate of the sprite.
     * @param newX The new X coordinate.
     */
    void setX(unsigned short newX);

    /**
     * @brief Sets the Y coordinate of the sprite.
     * @param newY The new Y coordinate.
     */
    void setY(unsigned short newY);

};

#endif // ENTITY_H

