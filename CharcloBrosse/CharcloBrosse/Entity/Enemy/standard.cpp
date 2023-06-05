#include "standard.h"

//Constructeur
Standard::Standard(unsigned short height, unsigned short width, QPixmap * sprite)
    :Enemy(height, width, sprite)
{
    itsType = STANDARD;
}

