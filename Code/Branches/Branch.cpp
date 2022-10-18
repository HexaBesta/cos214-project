#include "Branch.h"

Branch::Branch(Unit* unit) {
	this->unit = unit;
}

void Branch::attack(Platoon* pl){
	this->unit->attack(pl);
}

void Branch::requestState(){
	this->unit->requestState();
}

void Branch::setUnitState(UnitsState* unitS){
	this->unit->setUnitState(unitS);
}

int Branch::takeDamage(int damage){
	return this->unit->takeDamage(damage);
}
