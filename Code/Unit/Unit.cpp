#include "Unit.h"

void Unit::requestState() {
	this->unitState->request();
}

void Unit::setUnitState(UnitsState * unitState) {
	if(unitState == nullptr){
		this->unitState = this->unitState->changeUnitState();
	}else{
		delete this->unitState;
		this->unitState = unitState;
	}
	
}

int Unit::getDamage(){
	return this->damage;
}

int Unit::getHealth(){
	return this->health;
}

bool Unit::takeDamage(int damage) {
	this->health = this->health - damage;
	if(this->health <= 0 ){
		this->setUnitState(new DeadState());
		return true;
	}
	return false;
}

 Unit*  Unit::split(){return NULL;}


void  Unit::join(Unit* others){}

string Unit::getBranch(){
	return "NotAClue";
}

string Unit::getAlliance(){
	return country->getAlliances()->getName();
}

void Unit::setCountry(Country* country){
	this->country = country;
}

Country* Unit::getCountry(){
    return this->country;
}

Unit::~Unit(){
	
	delete this->unitState;
    //delete this->country;
}
