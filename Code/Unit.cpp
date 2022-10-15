#include "Unit.h"

void Unit::request() {
	this->unitState->request();
}

void Unit::setUnitState(UnitsState * unitState = nullptr) {
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

int Unit::takeDamage(int damage) {
	this->health = this->health - damage;
	if(this->health <= 0 ){
		this->setUnitState(new DeadState());
	}
}
