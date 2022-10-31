#ifndef CIVILIANSTATE_H
#define CIVILIANSTATE_H
#include "FitState.h"
using namespace std;

class CivilianState : public UnitsState
{
    public: 
        /**
         * @brief Returns the actual damage that can be inflicted by a unit based on their state
         * 
         * @details In the Civilian State units deal 1/3 of their potential full damage
         * 
         * @param damage the unadjusted damage of the unit
         * @return the adjusted damage of the unit
         */
        virtual double attackStrength(double damage);

        /**
         * @brief change Unit's state to the default next state
         * 
         * @details Civilian State will change to (Deployed) Fit State
         * 
         * @return UnitsState* the new FitState state of the unit
         */
        virtual UnitsState * changeUnitState();

        /**
         * @brief Prints the current state "CIVILIAN"
         * 
         */
        virtual void request();

        /**
		 * @brief Returns the name of the state
		 * 
		 */
		virtual string getState();
};

#endif
