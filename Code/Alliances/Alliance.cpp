#include "Alliances.h"
#include "../Country/Country.h"

Alliances::Alliances(string name, int colour)
{
    this->name = name;
    this->colour = colour;
};

string Alliances::getName()
{
    return name;
};
int Alliances::getColour()
{
    return colour;
};

void Alliances::addCountry(Country *country)
{
    this->countries.push_back(country);
}

void Alliances::withdrawCountry(Country *country){
    for(int i = 0; i<this->countries.size(); i++){
        if(countries.at(i) == country){
            countries.erase(countries.begin() + i);
            cout<<country->getName()<<" succesfully withdrawn from "<<this->getName()<<endl;
            return;
        }
    }
    cout<<country->getName()<<" is not part of "<<this->getName()<<endl;
}

string Alliances::accessCountryMoral(){
    string out = "";
    for(auto country: this->countries){
        out += country->getName();
        out += ": \n" ;
        int morale = country->getCountryMoral();
       if(morale == 0){
        out += "\tLow Morale - Withdrawn\n";
       }else{
        out += "\tMorale - ";
        out += morale;
        out += "\n";
       }
    }
    return out;
}

vector<Country*> Alliances::getCountries(){
    return this->countries;
}