#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "block.h"

class Obstacle : public Block
{
public:
    Obstacle(short x,  short y,  short height,  short width, QPixmap * sprite);
};

#endif // OBSTACLE_H
