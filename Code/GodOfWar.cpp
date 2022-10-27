#include "GodOfWar.h"

GodOfWar::GodOfWar(string setupFile)
{

    ifstream inputFile(setupFile);
    vector<string> lines;
    string line;

    while (getline(inputFile, line) && line.at(0) != '#')
    {
        lines.push_back(line);
    }

    inputFile.close();

    string name = "";
    int colour = 0;
    string temp = "";
    for (int i = 0; i < lines.at(0).length(); i++)
    {
        if (lines.at(0).at(i) == ':')
        {
            name = temp;
            temp = "";
        }
        else
        {
            temp += (lines.at(0).at(i));
            if (i == lines.at(0).length() - 1)
            {
                colour = stoi(temp);
                temp = "";
            }
        }
    }
    groupOne = new Alliances(name, colour);

    for (int i = 0; i < lines.at(0).length(); i++)
    {
        if (lines.at(0).at(i) == ':')
        {
            name = temp;
            temp = "";
        }
        else
        {
            temp += (lines.at(0).at(i));
            if (i == lines.at(0).length() - 1)
            {
                colour = stoi(temp);
                temp = "";
            }
        }
    }
    groupTwo = new Alliances(name, colour);

    map = new Map(setupFile);

    this->turn = true;
}

void GodOfWar::takeTurn(int actions)
{
    this->map->printMap();
    Alliances *active = (turn) ? this->groupOne : this->groupTwo;
    while (actions > 0)
    {
        /*
        Choose a country
        */
        vector<Country *> countries = this->map->getCountriesByColour(active->getColour());
        int countryIndex = 0;
        if (countries.size() == 0)
        {
            cout << "This alliance has no countries left" << endl;
            cout << "END OF WAR" << endl;
            return;
        }
        else if (countries.size() == 1)
        {
            countryIndex = 0;
        }
        else
        {
            countryIndex = this->player->chooseCountry(countries);
        }

        /*
        Get areas occupied by this country
        */
        vector<Area *> areas = this->map->getAreasByCountry(countries.at(countryIndex));

        /*
        Choose area to take action in
        */
        int areaIndex = -1;
        if (areas.size() == 0)
        {
            cout << "This country occupies no areas - lose turn" << endl;
            break;
        }
        else if (areas.size() == 1)
        {
            areaIndex = 0;
        }
        else
        {
            areaIndex = this->player->chooseAreaForAction(areas);
        }

        /*
        Select an action
        */
        int action = this->player->chooseActionForCountry();

        /*
        Chosen to attack transport route
        */
        if (action == 0)
        {
            /*
            List of adjacent areas to destroy transport routes between
            */
            vector<Area *> adjacentAreas = this->map->listAdjacent(areas.at(areaIndex), true);
            int adjAreaIndex = -1;
            if (adjacentAreas.size() == 0)
            {
                cout << "No adjacent transport routes to destroy" << endl;
                break;
            }
            else if (adjacentAreas.size() == 1)
            {
                adjAreaIndex = 0;
            }
            else
            {
                adjAreaIndex = this->player->chooseAdjacentArea(adjacentAreas);
            }

            cout << "Destroying route between:" << endl
                 << areas.at(areaIndex)->toString() << endl
                 << adjacentAreas.at(adjAreaIndex)->toString() << endl;

            this->map->destroyTransportRoute(areas.at(areaIndex), adjacentAreas.at(adjAreaIndex));
        }
        /*
        Request resources 
        */
        else if(action ==1){
            int resource = this->player->chooseResource(areas.at(areaIndex));
            if(areas.at(areaIndex)->requestFactory(resource)){
                cout<<"Factory succesfully acquired"<<endl;
                cout<<areas.at(areaIndex)->toString();
            }else{
                cout<<"Area could not acquire requested factory"<<endl;
            }
        }
        /*
        March to adjacent area
        */
       else{
            /*
            List of adjacent areas to march to
            */
            vector<Area *> adjacentAreas = this->map->listAdjacent(areas.at(areaIndex), false);
            int adjAreaIndex = -1;
            if (adjacentAreas.size() == 0)
            {
                cout << "No adjacent areas" << endl;
                break;
            }
            else if (adjacentAreas.size() == 1)
            {
                adjAreaIndex = 0;
            }
            else
            {
                adjAreaIndex = this->player->chooseAdjacentArea(adjacentAreas);
            }

            cout<<"Marching from "<<areas.at(areaIndex)->getName()<<" to "<<adjacentAreas.at(adjAreaIndex)->getName()<<endl;
            areas.at(areaIndex)->marchOut(adjacentAreas.at(adjAreaIndex));
       }

    }
}