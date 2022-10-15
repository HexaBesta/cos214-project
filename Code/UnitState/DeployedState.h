#ifndef DEPLOYEDSTATE_H
#define DEPLOYEDSTATE_H
#include "UnitsState.h"
using namespace std;

class DeployedState : public UnitsState
{
	public:
        virtual void request();

};

#endif
