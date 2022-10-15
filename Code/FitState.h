#ifndef FITSTATAE_H
#define FITSTATE_H
#include "InjuredState.h"
using namespace std;

class FitState : public DeployedState
{
    public:
        virtual double attackStrength(double damage);
        virtual UnitsState * changeUnitState();
        virtual void request();

};

#endif
