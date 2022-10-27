#include "PlatoonBuilder.h"
using namespace std;

int getRandomNumber(int min, int max);

void PlatoonBuilder::createVehicles() {
    int size = getRandomNumber(5, 10);
    this->vehicles.reserve(size);
    for(int i = 0; i < size; i++) {
        this->vehicles.push_back(new Vehicle(getRandomNumber(100, 200), 100, getRandomNumber(15, 20), this->country, true));
    }
}

void PlatoonBuilder::createSoldiers() {
    int size = getRandomNumber(20, 30);
    this->soldiers.reserve(size);
    for(int i = 0; i < size; i++) {
        this->soldiers.push_back(new Human(100, 100, getRandomNumber(5, 10), this->country, true));
    }
}

void PlatoonBuilder::createAmmo() {
    this->ammo[0] = getRandomNumber(50, 70); // pewpewAmmo
    this->ammo[1] = getRandomNumber(20, 30); // boomboomAmmo
}

void PlatoonBuilder::setCountry(Country* c) {
    this->country = c;
}

void PlatoonBuilder::createPlatoon() {
    this->platoon = new Platoon(this->soldiers, this->vehicles, this->ammo[0], this->ammo[1]);
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
    return rand() % max + min;
}

// health, 