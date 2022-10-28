#include "Goods.h"

Goods::Goods(int supply):Transport(supply){};

int Goods::replenishMoral(){
    return this->getAmount();
}