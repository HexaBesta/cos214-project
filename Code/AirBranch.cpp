#include "AirBranch.h"

AirBranch::AirBranch(Unit* unit):Branch(unit) {
}

string AirBranch::toString(){
	return "AIR BRANCH " + this->unit->toString();
}

string AirBranch::getBranch(){
	return "AIR BRANCH";
}

Unit *AirBranch::split(){
	if(this->unit != NULL){
		return new AirBranch(this->unit->split());
	}
	else{
		return NULL;
	}
}
