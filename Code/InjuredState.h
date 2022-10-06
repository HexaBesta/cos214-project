#ifndef INJUREDSTATE_H
#define INJUREDSTATE_H

#include "DeployedState.h"
#include "DeadState.h"
using namespace std;

class InjuredState : public DeployedState
{
    public:
        /**
         * @brief Adjusts damage dealt based on UnitState - Injured = 1/2 * Full Damage
         * 
         * @param damage - the default damage dealt by the unit
         * @return double - the damage dealt after adjustment
         */
        virtual double attackStrength(double damage);
        
        /**
         * @brief Toggles to default next state (DEAD)
         * 
         * @return UnitState * - a DeadState() object
         */
        virtual UnitsState * changeUnitState();

        /**
         * @brief Prints the current state of the unit
         * 
         */
        virtual void request();
};

#endif