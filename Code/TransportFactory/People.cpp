#include "People.h"

People::People(int supply):Transport(supply){};

int People::replenishHealth(){
    return this->getAmount();
}