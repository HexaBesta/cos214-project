#include "Ammunition.h"

Ammunition::Ammunition(int supply):Transport(supply){};

int Ammunition::replenishPewPew(){
    return (this->getAmount() + this->getAmount());
}

int Ammunition::replenishBoomBoom(){
    return this->getAmount();
}