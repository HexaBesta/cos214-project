#include "AirBranch.h"

AirBranch::AirBranch(Unit* unit):Branch(unit) {
}

void AirBranch::print(){
	cout<<"AIR BRANCH"<<endl;
}

string AirBranch::getBranch(){
	return "AIR BRANCH";
}
