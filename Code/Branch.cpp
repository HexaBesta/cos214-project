#include "Branch.h"

Branch::Branch(Unit* unit):Unit() {
	this->unit = unit;
}

void Branch::attack(Unit* pl){
	this->unit->attack(pl);
}

void Branch::requestState(){
	this->unit->requestState();
}

void Branch::setUnitState(UnitsState* unitS){
	this->unit->setUnitState(unitS);
}

string Branch::getState()
{
	if (this->unit != NULL)
	{
		return this->unit->getState();
	}
	return "";
}

bool Branch::takeDamage(int damage, bool pewpew){
	return this->unit->takeDamage(damage, pewpew);
}

int Branch::getSize(){
	return this->unit->getSize();
}

string Branch::getBranch(){
	return "BRANCH";
}

int * Branch::getAmmo(){
	return this->unit->getAmmo();
}

string Branch::getStrategyType(){
	return this->unit->getStrategyType();
}

void Branch::changeStrategy(){
	this->unit->changeStrategy();
}

string Branch::toString(int lineLen){
	return this->unit->toString(lineLen);
}

Branch::~Branch(){
	delete this->unit;
}
