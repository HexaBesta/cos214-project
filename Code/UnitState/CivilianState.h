#ifndef CIVILIANSTATE_H
#define CIVILIANSTATE_H
#include "FitState.h"
using namespace std;

class CivilianState : public UnitsState
{
    public: 
        virtual double attackStrength(double damage);
        virtual UnitsState * changeUnitState();
        virtual void request();
};

#endif
