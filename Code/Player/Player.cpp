#include "Player.h"
#include "../Country/Country.h"
#include "../Alliances/Alliances.h"

void Player::initialise(Alliances * side1, Alliances * side2, Map* map){
    this->createCountries(map);
    this->initialiseSide(side1, map);
    this->initialiseSide(side2, map);
}

void Player::initialiseSide(Alliances * alliance, Map* map){
    int numCountries = this->numberOfCountriesInAlliance(map);

    for(int i = 0; i<numCountries; i++){
        Country * country = this->chooseCountryToJoinAlliance(map);
        country->setAlliance(alliance);
        alliance->addCountry(country);
    }

    vector<Country*> countries = alliance->getCountries();

    for(int i = 0; i<countries.size(); i++){
        this->addPlatoons(countries.at(i));
    }

    this->initialiseFactories(map, alliance);
}