#include <sstream>

#include "Battle.h"
#include "Area.h"
#include "User.h"

bool User::playerRetreat(Battle *battle)
{
    battle->getStateSummary();

    // int resp;
    // cout << "Retreat" << endl
    //      << "0. Yes \n1. Not necessary" << endl;
    // cin >> resp;

    // // clear buffer
    // cin.ignore(30, '\n');

    // if (resp == 0)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    string resp = "";

    cout << "Retreat?" << endl
         << "0 - Yes" << endl
         << "1 - No" << endl;

    while (1)
    {
        getline(cin, resp);

        if (resp.compare("") == 0)
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (!((resp.compare("0") == 0) || (resp.compare("1") == 0)))
        {

            cout << "Invalid input - try again" << endl;
        }

        else if (resp.compare("0") == 0)
        {
            cin.ignore(30, '\n');
            return true;
        }

        else
        {
            cin.ignore(30, '\n');
            return false;
        }
    }
}

bool User::checkChangeStrategy(Unit *active)
{
    // // active->print();
    // int resp;
    // cout << "Change Strategy" << endl
    //      << "0. Yes \n1. Not necessary" << endl;
    // cin >> resp;

    // cin.ignore(30, '\n');

    // if (resp == 0)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    string resp = "";

    cout << "Change Strategy?" << endl
         << "0 - Yes" << endl
         << "1 - Not necessary" << endl;

    while (1)
    {
        getline(cin, resp);

        if (resp.compare("") == 0)
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (!((resp.compare("0") == 0) || (resp.compare("1") == 0)))
        {

            cout << "Invalid input - try again" << endl;
        }

        else if (resp.compare("0") == 0)
        {
            cin.ignore(30, '\n');
            return true;
        }

        else
        {
            cin.ignore(30, '\n');
            return false;
        }
    }
}

bool User::requestReinforcements(Battle *battle)
{

    battle->getStateSummary();
    // int resp;
    // cout << "Request Reinforcements" << endl
    //      << "0. Yes \n1. Not necessary" << endl;
    // cin >> resp;

    // // clear buffer
    // cin.ignore(30, '\n');

    // if (resp == 0)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    string resp = "";

    cout << "Request Reinforcements?" << endl
         << "0 - Yes" << endl
         << "1 - Not necessary" << endl;

    while (1)
    {
        getline(cin, resp);

        if (resp.compare("") == 0)
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (!((resp.compare("0") == 0) || (resp.compare("1") == 0)))
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (resp.compare("0") == 0)
        {
            cin.ignore(30, '\n');
            return true;
        }

        else
        {
            cin.ignore(30, '\n');
            return false;
        }
    }
}

int User::chooseCountry(vector<Country *> country, Map *map)
{
    int resp = 0;
    cout << "Choose country index to take turn:" << endl;
    int x = 0;
    for (auto it : country)
    {
        vector<Area *> areas = map->getAreasByCountry(it);
        cout << it->getName() << ": \tAreas: {";
        for (auto areasIt : areas)
        {
            cout << "( " << areasIt->getName() << "," << areasIt->getIndex() << ") ";
        }
        cout << "} || Index: " << x++ << endl;
    }
    cin >> resp;
    cin.ignore(30, '\n');
    return resp;
}

int User::chooseActionForCountry()
{
    // int resp = 0;
    // cout << "Choose action to perform: \n 0 - attack transport route \n 1 - request resources \n 2 - march into an area \n 3 - end turn" << endl;
    // cin >> resp;
    // cin.ignore(30, '\n');
    // return resp;

    string resp = "";

    cout << "Choose action to perform:" << endl
         << "0 - Attack transport route" << endl
         << "1 - Request resources" << endl
         << "2 - March into area" << endl
         << "3 - End turn" << endl;

    while (1)
    {
        getline(cin, resp);

        if (resp.compare("") == 0)
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (!((resp.compare("0") == 0) || (resp.compare("1") == 0) || (resp.compare("2") == 0) || (resp.compare("3") == 0)))
        {
            cout << "Invalid input - try again" << endl;
        }

        else
        {
            stringstream ss;
            int intResp = 0;
            ss << resp;
            ss >> intResp;
            cin.ignore(30, '\n');
            return intResp;
        }
    }
}

int User::chooseAreaForAction(vector<Area *> areas)
{
    int resp = 0;
    cout << "Choose area index to take action in:" << endl;
    int x = 0;
    for (auto it : areas)
    {
        cout << it->getName() << " (" << it->getIndex() << ") || Index: " << x++ << endl;
    }
    cin >> resp;
    cin.ignore(30, '\n');
    return resp;
}

int User::chooseAdjacentArea(vector<Area *> areas)
{
    int resp = 0;
    cout << "Choose adjacent area from the list below:" << endl;
    int x = 0;
    for (auto it : areas)
    {
        cout << it->getName() << " (" << it->getIndex() << ")  || Index: " << x++ << endl;
    }
    cin >> resp;
    cin.ignore(30, '\n');
    return resp;
}

int User::chooseResource(Area *area)
{
    // int resp = 0;
    // cout << "Choose what resource to request for area: \n 0 - Medics  \n 1 - Ammo \n 2 - Goods" << endl;
    // cin >> resp;
    // cin.ignore(30, '\n');
    // if (resp >= 0 && resp <= 2)
    // {
    //     return resp;
    // }
    // else
    // {
    //     return 0;
    // }

    string resp = "";

    cout << "Choose what resource to request for area: " << endl
         << "0 - Medics" << endl
         << "1 - Ammunition" << endl
         << "2 - Goods" << endl;

    while (1)
    {
        getline(cin, resp);

        if (resp.compare("") == 0)
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (!((resp.compare("0") == 0) || (resp.compare("1") == 0) || (resp.compare("2") == 0)))
        {
            cout << "Invalid input - try again" << endl;
        }

        else
        {
            stringstream ss;
            int intResp = 0;
            ss << resp;
            ss >> intResp;
            cin.ignore(30, '\n');
            return intResp;
        }
    }
}

bool User::changePlayer()
{
    // int resp = 0;
    // do
    // {
    //     cout << "Would you like to change from User -> CPU: \n0 - No\n1 - Yes" << endl;
    //     cin >> resp;
    //     if (resp == 0)
    //     {
    //         return false;
    //     }
    //     else if (resp == 1)
    //     {
    //         return true;
    //     }
    // } while (resp != 0 || resp != 1);
    // return false;

    string resp = "";

    cout << "Would you like to change from User -> CPU" << endl
         << "0 - No" << endl
         << "1 - Yes" << endl;

    while (1)
    {

        getline(cin, resp);

        if (resp.compare("") == 0)
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (!((resp.compare("0") == 0) || (resp.compare("1") == 0)))
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (resp.compare("0") == 0) // RETURNS FALSE
        {
            cin.ignore(30, '\n');
            return false;
        }

        else // RETURNS TRUE
        {
            cin.ignore(30, '\n');
            return true;
        }
    }
}

Player *User::togglePlayer()
{
    Player *togglePlayer = new CPU();
    return togglePlayer;
}

void User::createCountries(Map *map)
{
    int resp = 0;
    cout << "How many countries would you like to initialise? ";
    cin >> resp;
    cout << endl
         << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- " << endl;
    while (resp > 0)
    {
        string countryName = "";
        cout << "Please enter country name: ";
        cin >> countryName;
        // int alliance = 0;
        // cout << "Choose the alliance: \nGreen - 0\nRed - 1" << endl;
        // cin >> alliance;
        Country *country = new Country(countryName, 94, this);
        if (map == NULL)
        {
            cout << "Map is NULL in User" << endl;
        }
        map->addCountry(country);
        map->printMap();
        Area *area = NULL;
        do
        {
            cout << "Where must " << country->getName() << " start? ";
            int areaIn = -1;
            cin >> areaIn;
            area = map->getAreaByIndex(areaIn);
        } while (area == NULL || !area->setCountry(country));
        // cout<<"Country added to map"<<endl;
        resp--;
    }
}

int User::numberOfCountriesInAlliance(Map *map)
{
    vector<Country *> country = map->getCountriesByColour(94);
    int resp = 0;
    cout << "The number of countries that are neutral " << country.size() << "\n Choose the amount you want to join your alliance: ";
    cin >> resp;
    return resp;
}

Country *User::chooseCountryToJoinAlliance(Map *map)
{
    vector<Country *> country = map->getCountriesByColour(94);
    cout << "Choose from the list of countries below to join alliance. Select the index" << endl;
    int x = 0;
    int resp = 0;
    for (auto it : country)
    {
        vector<Area *> areas = map->getAreasByCountry(it);
        cout << it->getName() << ": \tAreas: {";
        for (auto areasIt : areas)
        {
            cout << "( " << areasIt->getName() << "," << areasIt->getIndex() << ") ";
        }
        cout << "} || Index: " << x++ << endl;
    }
    cin >> resp;
    return country.at(resp);
}

void User::addPlatoons(Country *country, Map *map)
{
    country->recruitPlatoon(map);
}

void User::initialiseFactories(Map *map, Alliances *alliances)
{
    vector<Area *> areas = map->getAreasByColour(alliances->getColour());
    map->printMap();
    cout << "Choose area to create factory in: " << endl;
    int x = 0;
    for (auto it : areas)
    {
        cout << it->getName() << " (" << it->getIndex() << ")"
             << "|| Index: " << x << endl;
        x++;
    }
    int resp = 0;
    cin >> resp;
    cout << "Now choose what factory you want to create at the chosen area: \n0 - Medics\n1 - Ammo\n2 - Goods" << endl;
    int resp1 = 0;
    cin >> resp1;
    map->requestFactoryForArea(areas.at(resp), resp1);
}

void User::inspect(Map *map)
{
    int resp = 0;
    do
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "Would you like to inspect an area?\n1. Yes \n2. No" << endl;
        cin >> resp;
        if (resp == 1)
        {
            cout << endl
                 << "Which area would you like to inspect? ";
            cin >> resp;
            Area *area = map->getAreaByIndex(resp);
            if (area != NULL)
            {
                cout << area->toString();
            }
        }
    } while (resp != 2);
}

int User::platoonType()
{
    // int resp = 0;
    // cout << endl
    //      << "Which branch do you want to create?\n0. Land\n1. Air " << endl;
    // cin >> resp;
    // return resp;

    string resp = "";

    cout << "Which branch do you want to create?" << endl
    << "0 - Land" << endl
    << "1 - Air"  << endl;

    while (1)
    {
        getline(cin, resp);

        if (resp.compare("") == 0)
        {
            cout << "Invalid input - try again" << endl;
        }

        else if (!((resp.compare("0") == 0) || (resp.compare("1") == 0)))
        {

            cout << "Invalid input - try again" << endl;
        }

        else
        {
            stringstream ss;
            int intResp = 0;
            ss << resp;
            ss >> intResp;
            cin.ignore(30, '\n');
            return 0;
        }
    }
}