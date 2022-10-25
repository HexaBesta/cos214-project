#include "BoomBoomAttack.h"

void BoomBoomAttack::attack(Unit* platoonAttacked){
    platoonAttacked->takeDamage(23,false);
}

PlatoonStrategy* BoomBoomAttack::toggleStrategy(){
    PlatoonStrategy* newStrat = new PewPewAttack();
    return newStrat;
}

string BoomBoomAttack::getPlatoonStrategy(){
    string boomboom = "boom";
    return boomboom;
}