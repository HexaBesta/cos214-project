#ifndef FITSTATAE_H
#define FITSTATE_H
#include "InjuredState.h"
using namespace std;

class FitState : public DeployedState
{
    public:
        /**
         * @brief Returns the actual damage that can be inflicted by a unit based on their state
         * 
         * @details In the Fit State units deal their full potential damage
         * 
         * @param damage the unadjusted damage of the unit
         * @return the adjusted damage of the unit (full damage)
         */
        virtual double attackStrength(double damage);

        /**
         * @brief change Unit's state to the default next state
         * 
         * @details Fit State will change to (Deployed) Injured State
         * 
         * @return UnitsState* the new InjuredState state of the unit
         */
        virtual UnitsState * changeUnitState();

        /**
         * @brief Prints the current state 
         * 
         * @details Calls the parent class request before completing own print FIT
         * 
         */
        virtual void request();

};

#endif
