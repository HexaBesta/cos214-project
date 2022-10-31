#include "Goods.h"

Goods::Goods(int supply):Transport(supply){};

int Goods::replenish(bool doubleRep = false){
    return this->getAmount();
}