#include "PlatoonBuilder.h"
using namespace std;

int getRandomNumber(int min, int max);

void PlatoonBuilder::createVehicles() {
    int population = this->country->getPopulation();
    int maxDraw = (int)(population*0.05 + 1);
    int minDraw = maxDraw -5;
    if(minDraw < 0){
        minDraw = 0;
    }
    int size = getRandomNumber(maxDraw, minDraw);
    this->vehicles.reserve(size);
    for(int i = 0; i < size; i++) {
        this->vehicles.push_back(new Vehicle(getRandomNumber(100, 200), 0, getRandomNumber(15, 20), this->country, true));
    }
}

void PlatoonBuilder::createSoldiers() {
    int population = this->country->getPopulation();
    int maxDraw = (int)(population*0.15 + 1);
    int minDraw = maxDraw - 10;
    if(minDraw < 0){
        if(population<5){
            minDraw = population;
        }else{
            minDraw = 5;
            if(minDraw = maxDraw){
                maxDraw = 4;
            }
        }
    }
    int size = getRandomNumber(maxDraw, minDraw);
    this->soldiers.reserve(size);
    for(int i = 0; i < size; i++) {
        this->soldiers.push_back(new Human(100, 100, getRandomNumber(5, 10), this->country, true));
    }
}

void PlatoonBuilder::createAmmo() {
    this->ammo[0] = getRandomNumber(120, 250); // pewpewAmmo
    this->ammo[1] = getRandomNumber(30, 50); // boomboomAmmo
}

void PlatoonBuilder::setCountry(Country* c) {
    this->country = c;
}

void PlatoonBuilder::createPlatoon() {
    this->platoon = new Platoon(this->soldiers, this->vehicles, this->ammo[0], this->ammo[1]);
    this->platoon->setCountry(this->country);
}

Unit* PlatoonBuilder::getPlatoon() {
    return this->platoon;
}

void PlatoonBuilder::setBranch(bool type) {
    if(type) {
        // LandBranch
        this->platoon = new LandBranch(this->platoon);
    } else {
        // Airbranch
        this->platoon = new AirBranch(this->platoon);
    }
}

void PlatoonBuilder::clearBuilder() {
    this->vehicles.clear();
    this->soldiers.clear();
    this->ammo[0] = 0;
    this->ammo[1] = 0;
    this->country = NULL;
    this->branch = NULL;
    this->platoon = NULL;
}

int getRandomNumber(int max, int min) {
    return ((rand() % (max - min)) + min);
}

// health, 