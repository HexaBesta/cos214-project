#include "CPU.h"
#include "Area.h"

bool CPU::playerRetreat(Battle *battle)
{
    battle->getStateSummary();
    if (battle->getTurn())
    {
        if (battle->getAir()->getAttacker()!=nullptr && battle->getAir()->getAttacker()->getHealth() <= 500)
        {
            return true;
        }
        else if (battle->getLand()->getAttacker()!=nullptr && battle->getLand()->getAttacker()->getHealth() <= 500)
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
        if (battle->getAir()->getDefender()!=nullptr && battle->getAir()->getDefender()->getHealth() <= 500)
        {
            return true;
        }
        else if (battle->getLand()->getDefender()!=nullptr && battle->getLand()->getDefender()->getHealth() <= 500)
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

int CPU::chooseCountry(vector<Country *> country, Map *map)
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
    int value = rand() % (4);
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

int* CPU::chooseAreasToDestroyTransportRoutes(vector<Area *> adjAreas, vector<vector<Area*>> otherAdj, Area * current){
    int * indexes= new int[2];
    indexes[0] = indexes[1] = -1;
    int destroyColour = 22;
    if(current->getColour() == 22){
        destroyColour = 160;
    }
    for(int i = 0; i<adjAreas.size(); i++){
        if(adjAreas.at(i)->getColour() == destroyColour){
            indexes[0] = i;
            for(int j = 0; j<otherAdj.at(i).size(); j++){
                if(otherAdj.at(i).at(j)->getColour() == destroyColour){
                    indexes[1] = j;
                    return indexes;
                }
            }
            for(int j = 0; j<otherAdj.at(i).size(); j++){
                if(otherAdj.at(i).at(j)->getColour() == 94){
                    indexes[1] = j;
                    return indexes;
                }
            }
        }
    }
    for(int i = 0; i<adjAreas.size(); i++){
        if(adjAreas.at(i)->getColour() == 94){
            indexes[0] = i;
            for(int j = 0; j<otherAdj.at(i).size(); j++){
                if(otherAdj.at(i).at(j)->getColour() == destroyColour){
                    indexes[1] = j;
                    return indexes;
                }
            }
            for(int j = 0; j<otherAdj.at(i).size(); j++){
                if(otherAdj.at(i).at(j)->getColour() == 94){
                    indexes[1] = j;
                    return indexes;
                }
            }
        }
    }
    delete [] indexes;
    indexes = NULL;
    return NULL;
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
    return -1;
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
    srand(2345);
    int ranNum = rand() % ((8)) + 6;
    cout << "--------------------------------------------" << endl;
    cout << "Creating " << ranNum << " countries" << endl;
    for (int i = 0; i < ranNum; i++)
    {
        int countryNumber = rand() % ((100 - 50 + 1) + 50);
        string countryName = "Country";
        countryName += to_string(countryNumber);
        Country *country = new Country(countryName, 94, this);
        map->addCountry(country);
        vector<Area *> possibleAreas = map->getAreasByColour(94);
        int randomArea = rand() % possibleAreas.size();
        Area *area = nullptr;
        area = possibleAreas.at(randomArea);
        if (area != nullptr)
        {
            area->setCountry(country);
            cout << area->toString() << endl;
        }
    }
    cout << endl;
    map->printMap();
}

int CPU::numberOfCountriesInAlliance(Map *map)
{
    vector<Country *> country = map->getCountriesByColour(94);
    int random = rand() % country.size();
    if(random<3){
        random+=3;
        if(random > country.size()){
            random = country.size();
        }
    }
    if(random == map->getCountries().size()){
        random = random*0.7;
    }
    return random;
}

Country *CPU::chooseCountryToJoinAlliance(Map *map)
{
    vector<Country *> country = map->getCountriesByColour(94);
    int random = rand() % country.size();
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

int CPU::platoonType()
{
    int random = (rand() % 3) + 1;
    return (random % 2);
}

// int CPU::chooseCountry(vector<Country *> country, Map *map)
// {
//     if (!country.empty())
//     {
//         int index = rand() % country.size();
//         return index;
//     }
//     else
//     {
//         return -1;
//     }
// }