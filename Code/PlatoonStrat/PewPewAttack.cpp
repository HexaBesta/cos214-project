#include "PewPewAttack.h"

void PewPewAttack::attack(Unit* platoonAttacked){
    platoonAttacked->takeDamage(23,true);
}

PlatoonStrategy* PewPewAttack::toggleStrategy(){
    PlatoonStrategy* newStrat = new BoomBoomAttack();
    return newStrat;
}

string PewPewAttack::getPlatoonStrategy(){
    string pewpew = "pew";
    return pewpew;
}