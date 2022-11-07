#ifndef DEADSTATE_H
#define DEADSTATE_H
#include "UnitsState.h"
using namespace std;

class DeadState : public UnitsState
{
    public:
        /**
         * @brief Returns the actual damage that can be inflicted by a unit based on their state
         * 
         * @details In the Dead State units do not deal damage
         * 
         * @param damage the unadjusted damage of the unit
         * @return 0
         */
        virtual double attackStrength(double damage);

        /**
         * @brief change Unit's state to the default next state
         * 
         * @details Dead State cannot change State
         * 
         * @return this
         */
        virtual UnitsState * changeUnitState();

         /**
         * @brief Prints the current state "DEAD"
         * 
         */
        virtual void request();

        /**
		 * @brief Returns the name of the state: "Dead"
		 * 
		 */
		virtual string getState();

};

#endif
