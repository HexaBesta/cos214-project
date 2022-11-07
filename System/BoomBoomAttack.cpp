#include "BoomBoomAttack.h"
#include "Platoon.h"

BoomBoomAttack::BoomBoomAttack(Platoon *plat) : PlatoonStrategy(plat)
{
}

void BoomBoomAttack::attack(Unit *platoonAttacked)
{
    if (this->thePlatoon->getAmmo()[1] > 0)
    {
        int damage = this->thePlatoon->getDamage() * 1.5;
        platoonAttacked->takeDamage(damage, false);
        this->thePlatoon->decreaseAmmo();
    }
    else
    {
        platoonAttacked->takeDamage(10, true);
        cout<<"Your platoon will now use a rock catapult - they have no ammo. If you survive...we recommend replenishing ammo"<<endl;
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