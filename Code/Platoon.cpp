#include "Platoon.h"

Platoon::Platoon(vector<Unit*> human, vector<Unit*> vehicles, vector<Weapon*> weapons){
	this->humans = human;
	this->vehicles = vehicles;
	this->weapons = weapons;
//	this->strategy = new PewPewAttack();
}

void  Platoon::construct() {
	// TODO - implement Platoon::construct
	throw "Not yet implemented";
}

void  Platoon::changeStrategy() {
	this->strategy = this->strategy->toggleStrategy();
}

 Platoon*  Platoon::splitPlatoon() {
	size_t const half_sizeH = this->humans.size() / 2;
	vector<Unit*> human1(this->humans.begin(), this->humans.begin() + half_sizeH);
	vector<Unit*> human2(this->humans.begin() + half_sizeH, this->humans.end());

	size_t const half_sizeV = this->vehicles.size() / 2;
	vector<Unit*> vehicles1(this->vehicles.begin(), this->vehicles.begin() + half_sizeV);
	vector<Unit*> vehicles2(this->vehicles.begin() + half_sizeV, this->vehicles.end());

	size_t const half_sizeW = this->weapons.size() / 2;
	vector<Weapon*> weapon1(this->weapons.begin(), this->weapons.begin() + half_sizeW);
	vector<Weapon*> weapon2(this->weapons.begin() + half_sizeW, this->weapons.end());

	this->humans = human1;
	this->vehicles = vehicles1;
	this->weapons = weapon1;

	Platoon* split = new Platoon(human2, vehicles2, weapon2);
	return split;
	
}

void  Platoon::joinPlatoon( Platoon* platoon) {
	// TODO - implement Platoon::joinPlatoon
	throw "Not yet implemented";
}

//added

	// int takeDamage(int damage);

	// virtual void attack(Platoon *other);