#include "Human.h"

void Human::attack(Platoon* other){
    //we need a return random function to return a random object in the platoon to take damage
    other->takeRandom()->takeDamage(this->unitState->attackStrength(this->damage));
}