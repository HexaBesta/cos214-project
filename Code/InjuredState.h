#ifndef INJUREDSTATE_H
#define INJUREDSTATE_H

#include "DeployedState.h"
#include "DeadState.h"
using namespace std;

class InjuredState : public DeployedState
{
    public:
        virtual double attackStrength(double damage);
        virtual UnitsState * changeUnitState();
        virtual void request();
};

#endif