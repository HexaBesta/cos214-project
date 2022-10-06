#include "Unit.h"

void Unit::requestState() {
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

int Unit::takeDamage(int damage) {
	this->health = this->health - damage;
	if(this->health <= 0 ){
		this->setUnitState(new DeadState());
	}
}
