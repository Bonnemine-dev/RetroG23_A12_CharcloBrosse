#include "standard.h"

//Constructeur
Standard::Standard( short height,  short width, QPixmap * sprite)
    :Enemy(height, width, sprite)
{
    itsType = STANDARD;
}

