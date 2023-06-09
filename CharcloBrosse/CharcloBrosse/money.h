#ifndef MONEY_H
#define MONEY_H

#include "entity.h"

enum MoneyType {RED = 100, YELLOW = 250, BILL = 500};

class Money : public Entity
{
public:
    Money();
};

#endif // MONEY_H
