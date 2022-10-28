#include "CPU.h"

bool CPU::playerRetreat(Battle *battle)
{
    battle->getStateSummary();
    if (battle->getTurn())
    {
        if (battle->getAir()->getAttacker()->getHealth() <= 500)
        {
            return true;
        }
        else if (battle->getLand()->getAttacker()->getHealth() <= 500)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (battle->getAir()->getDefender()->getHealth() <= 500)
        {
            return true;
        }
        else if (battle->getLand()->getDefender()->getHealth() <= 500)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool CPU::checkChangeStrategy(Unit *active)
{
    string stratType = active->getStrategyType();
    if (stratType.compare("pew") == true)
    {
        active->changeStrategy();
    }
    else if (stratType.compare("boom") == true)
    {
        active->changeStrategy();
    }
}

bool CPU::requestReinforcements(Battle *battle)
{
    battle->getStateSummary();
    if (battle->getTurn() == true)
    {
        int totalHealth = 0;
        int totalDamage = 0;

        if (battle->getAir()->getAttacker() != nullptr)
        {
            totalHealth += battle->getAir()->getAttacker()->getHealth();
        }
        if (battle->getLand()->getAttacker() != nullptr)
        {
            totalHealth += battle->getLand()->getAttacker()->getHealth();
        }

        if (battle->getAir()->getDefender() != nullptr)
        {
            totalDamage += battle->getAir()->getDefender()->getDamage();
        }
        if (battle->getLand()->getDefender() != nullptr)
        {
            totalDamage += battle->getLand()->getDefender()->getDamage();
        }

        if (totalHealth <= (totalDamage * 2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (battle->getTurn() == false)
    {
        int totalHealth = 0;
        int totalDamage = 0;

        if (battle->getAir()->getAttacker() != nullptr)
        {
            totalDamage += battle->getAir()->getAttacker()->getHealth();
        }
        if (battle->getLand()->getAttacker() != nullptr)
        {
            totalDamage += battle->getLand()->getAttacker()->getHealth();
        }

        if (battle->getAir()->getDefender() != nullptr)
        {
            totalHealth += battle->getAir()->getDefender()->getDamage();
        }
        if (battle->getLand()->getDefender() != nullptr)
        {
            totalHealth += battle->getLand()->getDefender()->getDamage();
        }

        if (totalHealth <= (totalDamage * 2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int CPU::chooseCountry(vector<Country *> country)
{
    if (!country.empty())
    {
        int index = rand() % country.size();
        return index;
    }
    else
    {
        return -1;
    }
}

int CPU::chooseActionForCountry()
{
    int value = rand() % ((2 - 0 + 1) + 0);
    return value;
}

int CPU::chooseAreaForAction(vector<Area *> area)
{
    if (!area.empty())
    {
        int index = rand() % area.size();
        return index;
    }
    else
    {
        return -1;
    }
}

int CPU::chooseAdjacentArea(vector<Area *> adjacentArea)
{
    if (!adjacentArea.empty())
    {
        int index = rand() % adjacentArea.size();
        return index;
    }
    else
    {
        return -1;
    }
}

int CPU::chooseResource(Area *area)
{
    
        if (area->getFactory(0) == nullptr)
        {
            area->requestFactory(0);
            return 0;
        }
        else if (area->getFactory(1) == nullptr)
        {
            area->requestFactory(1);
            return 1;
        }
        else if (area->getFactory(2) == nullptr)
        {
            area->requestFactory(2);
            return 2;
        }
        int randomV = rand()%(2+1);
        area->getFactory(randomV);
        return randomV;
}