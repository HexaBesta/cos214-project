#include "../Battle/Battle.h"
#include "../Map/Area.h"
#include "User.h"

bool User::playerRetreat(Battle *battle)
{
    battle->getStateSummary();

    int resp;
    cout << "Retreat" << endl
         << "1. Yes \n2. Not necessary" << endl;
    cin >> resp;

    // clear buffer
    cin.ignore(30, '\n');

    if (resp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool User::checkChangeStrategy(Unit *active)
{
    // active->print();
    int resp;
    cout << "Change Strategy" << endl
         << "1. Yes \n2. Not necessary" << endl;
    cin >> resp;

    cin.ignore(30, '\n');

    if (resp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool User::requestReinforcements(Battle *battle)
{

    battle->getStateSummary();
    int resp;
    cout << "Request Reinforcements" << endl
         << "1. Yes \n2. Not necessary" << endl;
    cin >> resp;

    // clear buffer
    cin.ignore(30, '\n');

    if (resp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int User::chooseCountry(vector<Country *> country)
{
    int resp = 0;
    cout << "Choose country index to take turn:" << endl;
    int x = 0;
    for (auto it : country)
    {
        cout << it->getName() << " || Index: " << x << endl;
        x++;
    }
    cin >> resp;
    cin.ignore(30, '\n');
    return resp;
}

int User::chooseActionForCountry(){
    int resp = 0;
    cout<<"Choose action to perform: \n 0 - attack transport route \n 1 - request resources \n 2 - march into an area"<<endl;
    cin>>resp;
    cin.ignore(30, '\n');
    return resp;
}

int User::chooseAreaForAction(vector<Area*> areas){
    int resp = 0;
    cout << "Choose area index to take action in:" << endl;
    for (auto it : areas)
    {
        cout << it->getName() << " || Index: " << it->getIndex() << endl;
    }
    cin >> resp;
    cin.ignore(30, '\n');
    return resp;
}

int User::chooseAdjacentArea(vector<Area*> areas){
    int resp = 0;
    cout << "Choose adjacent area from the list below:" << endl;
    for (auto it : areas)
    {
        cout << it->getName() << " || Index: " << it->getIndex() << endl;
    }
    cin >> resp;
    cin.ignore(30, '\n');
    return resp;
}

int User::chooseResource(Area* area){
    int resp = 0;
    cout<<"Choose what resource to request for area: \n 0 - Medics  \n 1 - Ammo \n 2 - Goods"<<endl;
    cin>>resp;
    cin.ignore(30,'\n');
    if(area->getFactory(resp)==nullptr){
        area->requestFactory(resp);
        return resp;
    }else{
        area->getFactory(resp);
        return resp;
    }
}