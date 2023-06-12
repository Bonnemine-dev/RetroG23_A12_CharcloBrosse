/**
 * @file accelerator.cpp
 * @brief Source file for class Accelerator
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 2.0
 */


#include "accelerator.h"

//Constructeur
Accelerator::Accelerator(short height,  short width, QPixmap * sprite)
    :Enemy(height, width, sprite)
{
    itsType = ACCELERATOR;
}

//upSpeed -> Accelerates the speed of the accelerator when it comes up
void Accelerator::upSpeed()
{
    if(itsSpeedState < 3)
    {
        itsSpeedState += 1;
        itsXSpeed += itsSpeedState * 5;
        itsYSpeed += itsSpeedState * 5;
    }
}
