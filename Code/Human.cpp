#include "Human.h"

Human::Human(int health, int moral, int damage, Country *country, bool fitState) : Unit(health, moral, damage, country, fitState)
{
    // cout << "Human created" << endl;
}

void Human::attack(Unit *other)
{
    // we need a return random function to return a random object in the platoon to take damage
    other->takeRandom()->takeDamage(this->unitState->attackStrength(this->damage));
}

string Human::toString()
{
    return "Human: " + this->health;
    ;
}

Human::~Human(){
    cout<<"Deleting Human"<<endl;
}