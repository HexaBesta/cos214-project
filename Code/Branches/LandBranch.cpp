#include "LandBranch.h"

LandBranch::LandBranch(Unit* unit):Branch(unit) {
}

string LandBranch::toString(){
	return "LAND BRANCH " + this->unit->toString();
}

string LandBranch::getBranch(){
	return "LAND BRANCH";
}

 LandBranch::~LandBranch(){
	
 }