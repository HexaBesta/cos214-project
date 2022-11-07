#include "Ammunition.h"

Ammunition::Ammunition(int supply) : Transport(supply){};

int Ammunition::replenish(bool pew)
{
    if (pew)
        return (this->getAmount() + this->getAmount());
    return this->getAmount();
}