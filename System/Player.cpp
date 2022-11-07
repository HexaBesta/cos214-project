#include "Player.h"
#include "Country.h"
#include "Alliances.h"
#include "Map.h"
#include "Area.h"

void Player::initialise(Alliances * side1, Alliances * side2, Map* map,sf::RenderWindow* window){
    this->createCountries(map,window);
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Countries created"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    this->initialiseSide(side1, map,window);
    this->initialiseSide(side2, map,window);
     cout<<"-----------------------------------------------------"<<endl;
    cout<<"Map after initialisation of "<<side2->getName()<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}

void Player::initialiseSide(Alliances * alliance, Map* map,sf::RenderWindow* window){
    cout<<"----------------------------------------------------"<<endl;
    cout<<alliance->getName()<<" is being initialised"<<endl;
    cout<<"----------------------------------------------------"<<endl;

    cout<<"- - - - - - - - - Choose countries- - - - - - - - - -"<<endl;
    int numCountries = this->numberOfCountriesInAlliance(map,window);

    for(int i = 0; i<numCountries; i++){
        Country * country = this->chooseCountryToJoinAlliance(map,window);
        country->setAlliance(alliance);
        alliance->addCountry(country);
        vector<Area *> areas = map->getAreasByCountry(country);
        for (auto area : areas)
        {
            area->setColour();
        }
    }

    vector<Country *> countries = alliance->getCountries();

    cout << "- - - - - - - - - Add platoons - - - - - - - - -" << endl;

    for(int i = 0; i<countries.size(); i++){
        this->addPlatoons(countries.at(i),map,window,{});
    }
}

void Player::inspect(Map *map) {}