#ifndef CIVILIANSTATE_H
#define CIVILIANSTATE_H
#include "FitState.h"
using namespace std;

class CivilianState : public UnitsState
{
    public: 
        /**
         * @brief Adjusts damage dealt based on UnitState - Civilian = 1/3 Full
         * 
         * @param damage - the default damage dealt by the unit
         * @return double - the damage dealt after adjustment
         */
        virtual double attackStrength(double damage);

        /**
         * @brief Toggles to default next state (Deployed FIT)
         * 
         * @return UnitState * - a FitState() object
         */
        virtual UnitsState * changeUnitState();

        /**
         * @brief Prints the current state of the unit
         * 
         */
        virtual void request();
};

#endif
