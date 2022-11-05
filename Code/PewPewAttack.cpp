#include "PewPewAttack.h"
#include "Platoon.h"

PewPewAttack::PewPewAttack(Platoon *plat) : PlatoonStrategy(plat){};

void PewPewAttack::attack(Unit *platoonAttacked)
{
    int minAmmoUse = (this->thePlatoon->getAmmo()[0] < platoonAttacked->getSize()) ? this->thePlatoon->getAmmo()[0] : platoonAttacked->getSize();
    if (this->thePlatoon->getAmmo()[0] > 0)
    {
        for (int x = 0; x < minAmmoUse; x++)
        {
            int denominator = (platoonAttacked->getSize() / 3);
            if (denominator == 0)
            {
                denominator++;
            }
            int damage = this->thePlatoon->getDamage() / (denominator);
            platoonAttacked->takeDamage(damage, true);
            if (platoonAttacked->getState().compare("Dead") == 0)
            {
                break;
            }
            else
            {
                this->thePlatoon->decreaseAmmo();
            }
        }
    }
    else
    {
        platoonAttacked->takeDamage(2, true);
        cout<<"Platoon will now throw rocks - You do not have ammo. If you survive...we recommend replenishing ammo"<<endl;
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