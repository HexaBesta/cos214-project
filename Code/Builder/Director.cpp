#include "Director.h"

using namespace std;

Unit* Director::construct(bool type, Country* c) {
    builder->setCountry(c); // sets the country of the builder
    builder->createSoldiers(); // creates soldiers
    builder->createVehicles(); // creates vehicles
    builder->createAmmo(); // creates ammo
    builder->createPlatoon(); // creates the platoon
    builder->setBranch(type); // sets the branch of the platoon
    return builder->getPlatoon(); // returns the platoon
}