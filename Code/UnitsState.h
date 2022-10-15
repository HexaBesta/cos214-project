#ifndef UNITSSTATE_H
#define UNITSSTATE_H

#include <string>
#include <iostream>

using namespace std;

class UnitsState
{


public:
	
	//Took out - same as attackStrength
	//virtual void handleUnits() = 0;

    //changed method - just returns different values based on state eg injured<fit
	virtual double attackStrength(double damage) = 0;

	virtual void request()=0;

	virtual UnitsState * changeUnitState() = 0;

};

#endif
