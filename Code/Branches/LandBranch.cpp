#include "LandBranch.h"

LandBranch::LandBranch(Unit* unit):Branch(unit) {
}

void LandBranch::print(){
	cout<<"LAND BRANCH"<<endl;
}

string LandBranch::getBranch(){
	return "LAND BRANCH";
}

 LandBranch::~LandBranch(){
	
 }