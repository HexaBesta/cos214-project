#include "Vehicle.h"

Vehicle::Vehicle(int health, int moral, int damage, Country* country, bool fitState) : Unit(health, moral, damage, country, fitState) {
    // cout << "Human created" << endl;
}

void Vehicle::attack(Unit* other){
    //we need a return random function to return a random object in the platoon to take damage
    other->takeRandom()->takeDamage(this->unitState->attackStrength(this->damage));
}

string Vehicle::toString(){
    return "Human: " + this->health;;
}

Vehicle::~Vehicle(){
    
}