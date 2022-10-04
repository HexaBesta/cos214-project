#ifndef UNITSSTATE_H
#define UNITSSTATE_H

#include "DeployedState.h"

using namespace std;

class UnitsState
{

private:
	DeployedState *deployedState;

public:
	virtual void handleUnits() = 0;

	virtual UnitsState changeUnitState() = 0;

	void request();

	void setDeployedState(DeployedState *deployedState);
};

#endif
