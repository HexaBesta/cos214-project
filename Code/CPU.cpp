#include "CPU.h"
#include "Area.h"

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
    return false;
}

bool CPU::checkChangeStrategy(Unit *active)
{
    int random = rand() % (1 + 1);
    if (random == 0)
    {
        return true;
    }
    else
    {
        return false;
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
    return false;
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
    int value = rand() % (5);
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
        return 0;
    }
    else if (area->getFactory(1) == nullptr)
    {
        return 1;
    }
    else if (area->getFactory(2) == nullptr)
    {
        return 2;
    }
    int randomV = rand() % (2 + 1);
    return randomV;
}

bool CPU::changePlayer()
{
    int resp = 0;
    do
    {
        cout << "Would you like to change from CPU -> User: \n 0 - No\n 1 - Yes" << endl;
        cin >> resp;
        if (resp == 0)
        {
            return false;
        }
        else if (resp == 1)
        {
            return true;
        }
    } while (resp != 0 || resp != 1);
    return false;
}

Player *CPU::togglePlayer()
{
    Player *togglePlayer = new User();
    return togglePlayer;
}

void CPU::createCountries(Map *map)
{
    int ranNum = rand() % (5) + 1;
    cout<<"--------------------------------------------"<<endl;
    cout<<"Creating "<< ranNum << " countries"<<endl;
    for (int i = 0; i < ranNum; i++)
    {
        int random = rand() % (1 + 1);
        int countryNumber = rand() % (100 - 50 + 1) + 50;
        string countryName = "Country";
        countryName += countryNumber;
        if (random == 0)
        {
            Country *country = new Country(countryName, 22, this);
            map->addCountry(country);
        }
        else if (random == 1)
        {
            Country *country = new Country(countryName, 160, this);
            map->addCountry(country);
        }
        cout<<endl;
    }
}

int CPU::numberOfCountriesInAlliance(Map *map)
{
    vector<Country *> country = map->getCountriesByColour(94);
    int size = country.size();
    int random = rand() % size;
    return random;
}

Country *CPU::chooseCountryToJoinAlliance(Map *map)
{
    vector<Country *> country = map->getCountriesByColour(94);
    int size = country.size();
    int random = rand() % size;
    return country.at(random);
}

void CPU::addPlatoons(Country *country, Map *map)
{
    country->recruitPlatoon(map);
}

void CPU::initialiseFactories(Map *map, Alliances *alliance)
{
    vector<Area *> areas = map->getAreasByColour(alliance->getColour());
    int random = rand() % areas.size();
    if (areas.at(random)->getFactory(0) == nullptr)
    {
        map->requestFactoryForArea(areas.at(random), 0);
    }
    else if (areas.at(random)->getFactory(1) == nullptr)
    {
        map->requestFactoryForArea(areas.at(random), 1);
    }
    else if (areas.at(random)->getFactory(2) == nullptr)
    {
        map->requestFactoryForArea(areas.at(random), 2);
    }
}

int CPU::platoonType(){
    return rand()%2;
}