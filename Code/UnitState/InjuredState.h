#ifndef INJUREDSTATE_H
#define INJUREDSTATE_H

#include "DeployedState.h"
#include "DeadState.h"
using namespace std;

class InjuredState : public DeployedState
{
    public:
        /**
         * @brief Returns the actual damage that can be inflicted by a unit based on their state
         * 
         * @details In the Injured State units deal 1/2 their full potential damage
         * 
         * @param damage the unadjusted damage of the unit
         * @return the adjusted damage of the unit (1/2 damage)
         */
        virtual double attackStrength(double damage);

        /**
         * @brief change Unit's state to the default next state
         * 
         * @details Injured State will change to the Dead State
         * 
         * @return UnitsState* the new InjuredState state of the unit
         */
        virtual UnitsState * changeUnitState();

        /**
         * @brief Prints the current state 
         * 
         * @details Calls the parent class request before completing own print INJURED
         * 
         */
        virtual void request();
};

#endif