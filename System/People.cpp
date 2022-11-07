#include "People.h"

People::People(int supply) : Transport(supply){};

int People::replenish(bool doublePre)
{
    return this->getAmount();
}