#ifndef UNITSSTATE_H
#define UNITSSTATE_H

#include <string>
#include <iostream>

using namespace std;

class UnitsState {
	public:
		//Took out - same as attackStrength
		//virtual void handleUnits() = 0;

		//changed method - just returns different values based on state eg injured<fit
		/**
         * @brief Pure virtual method implemented by concrete states that returns the actual damage that can be inflicted by a unit based on their state
         *
         * @param damage the unadjusted damage of the unit
         * @return the adjusted damage of the unit (full damage)
         */
		virtual double attackStrength(double damage) = 0;

		/**
		 * @brief Pure virtual function implemented by concrete state to return default next state
		 * 
		 * @return UnitsState* 
		 */
		virtual UnitsState * changeUnitState() = 0;

		/**
         * @brief Pure virtual function implemented by concrete states to print the current state
         * 
         */
		virtual void request() = 0;

		/**
		 * @brief Returns the name of the state
		 * 
		 */
		virtual string getState()=0;

};

#endif
