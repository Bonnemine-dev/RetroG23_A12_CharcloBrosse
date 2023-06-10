/**
 * @file freezer.cpp
 * @brief Source file for class Freezer
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */

#include "freezer.h"

//Constructeur de Freezer
Freezer::Freezer(short height,  short width, QPixmap * sprite)
    :Enemy(height, width, sprite)
{
    itsType = FREEZER;
}
