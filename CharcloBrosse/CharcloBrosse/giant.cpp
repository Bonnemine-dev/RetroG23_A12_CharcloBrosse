/**
 * @file giant.cpp
 * @brief Source file for class Giant
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */

#include "giant.h"

//Constructeur de Giant
Giant::Giant(short height,  short width, QPixmap * sprite)
    :Enemy(height, width, sprite)
{
    itsType = GIANT;
}
