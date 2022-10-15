#ifndef DEADSTATE_H
#define DEADSTATE_H
#include "UnitsState.h"
using namespace std;

class DeadState : public UnitsState
{
    public:
        virtual double attackStrength(double damage);
        virtual UnitsState * changeUnitState();
        virtual void request();

};

#endif
