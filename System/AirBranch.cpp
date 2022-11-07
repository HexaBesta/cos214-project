#include "AirBranch.h"

AirBranch::AirBranch(Unit *unit) : Branch(unit)
{
}

string AirBranch::toString()
{
	return "AIR BRANCH " + this->unit->toString();
}

string AirBranch::getBranch()
{
	return "AIR BRANCH";
}
