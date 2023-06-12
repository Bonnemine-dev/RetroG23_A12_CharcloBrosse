/**
 * @file standard.cpp
 * @brief Source file for class Standard
 * @author Tom Bonneau
 * @date 05/06/2023
 * @version 1.1
 */


#include "standard.h"

//Constructeur
Standard::Standard( short height,  short width, QPixmap * sprite)
    :Enemy(height, width, sprite)
{
    itsType = STANDARD;
}

