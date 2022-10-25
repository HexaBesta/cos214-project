#include "BoomBoomAttack.h"
#include "../Platoon/Platoon.h"

BoomBoomAttack::BoomBoomAttack(Platoon *plat) : PlatoonStrategy(plat)
{
}

void BoomBoomAttack::attack(Unit *platoonAttacked)
{
    if (this->thePlatoon->getAmmo()[1] > 0)
    {
        int damage = this->thePlatoon->getDamage() / 2;
        platoonAttacked->takeDamage(damage, false);
        this->thePlatoon->decreaseAmmo();
    }
}

PlatoonStrategy *BoomBoomAttack::toggleStrategy()
{
    PlatoonStrategy *newStrat = new PewPewAttack(this->thePlatoon);
    return newStrat;
}

string BoomBoomAttack::getPlatoonStrategy()
{
    string boomboom = "boom";
    return boomboom;
}