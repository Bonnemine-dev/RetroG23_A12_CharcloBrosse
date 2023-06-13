/**
 * @file accelerator.cpp
 * @brief Source file for class Accelerator
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */


#include "accelerator.h"

//Add 5 to itsSpeedState
void Accelerator::addItsSpeedState()
{
    if (itsSpeedState < 8)
    {
        itsSpeedState += 4;
    }
}

//Constructeur
short Accelerator::getItsSpeedState() const
{
    return itsSpeedState;
}

Accelerator::Accelerator(short height,  short width, QPixmap * sprite)
    :Enemy(height, width, sprite)
{
    itsType = ACCELERATOR;
}
