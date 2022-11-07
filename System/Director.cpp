#include "Director.h"

using namespace std;

Director::Director()
{
    this->builder = new PlatoonBuilder();
}

Director::~Director()
{
    delete this->builder;
    this->builder = NULL;
}

Unit *Director::construct(bool type, Country *c)
{
    builder->setCountry(c);    // sets the country of the builder
    builder->createSoldiers(); // creates soldiers
    builder->createVehicles(); // creates vehicles
    builder->createAmmo();     // creates ammo
    builder->createPlatoon();  // creates the platoon
    builder->setBranch(type);  // sets the branch of the platoon

    Unit *plat = builder->getPlatoon();

    builder->clearBuilder();

    return plat;
}