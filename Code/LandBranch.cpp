#include "LandBranch.h"

LandBranch::LandBranch(Unit* unit):Branch(unit) {
}

string LandBranch::toString(){
	return "LAND BRANCH " + this->unit->toString();
}

string LandBranch::getBranch(){
	return "LAND BRANCH";
}

Unit *LandBranch::split(){
	if(this->unit != NULL){
		return new LandBranch(this->unit->split());
	}
	else{
		return NULL;
	}
}

 LandBranch::~LandBranch(){
	
 }