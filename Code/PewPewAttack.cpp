#include "PewPewAttack.h"
#include "Platoon.h"

PewPewAttack::PewPewAttack(Platoon *plat) : PlatoonStrategy(plat){};

void PewPewAttack::attack(Unit *platoonAttacked)
{
    int min = (this->thePlatoon->getAmmo()[0] < platoonAttacked->getSize()) ? this->thePlatoon->getAmmo()[0] : platoonAttacked->getSize();
    if (this->thePlatoon->getAmmo()[0] > 0)
    {
        for (int x = 0; x < min; x++)
        {
            int damage = this->thePlatoon->getDamage() / platoonAttacked->getSize();
            platoonAttacked->takeDamage(damage, true);
            this->thePlatoon->decreaseAmmo();
        }
    }
}

PlatoonStrategy *PewPewAttack::toggleStrategy()
{
    PlatoonStrategy *newStrat = new BoomBoomAttack(this->thePlatoon);
    return newStrat;
}

string PewPewAttack::getPlatoonStrategy()
{
    string pewpew = "pew";
    return pewpew;
}