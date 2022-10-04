#ifndef DEPLOYEDSTATE_H
#define DEPLOYEDSTATE_H
#include "UnitsState.h"
using namespace std;

class DeployedState : public UnitsState
{

public:
	virtual void handleDeployed() = 0;

	virtual DeployedState * changeDeployedState() = 0;
};

#endif
