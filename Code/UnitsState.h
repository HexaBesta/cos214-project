#ifndef UNITSSTATE_H
#define UNITSSTATE_H

using namespace std;

class UnitsState
{


public:
	virtual void handleUnits() = 0;

	virtual UnitsState * changeUnitState() = 0;

	void request();

};

#endif
