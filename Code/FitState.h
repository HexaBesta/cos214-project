#ifndef FITSTATAE_H
#define FITSTATE_H
#include "InjuredState.h"
using namespace std;

class FitState : public DeployedState
{
    public:
        /**
         * @brief Adjusts damage dealt based on UnitState - Fit = Full Damage
         * 
         * @param damage - the default damage dealt by the unit
         * @return double - the damage dealt after adjustment
         */
        virtual double attackStrength(double damage);

        /**
         * @brief Toggles to default next state (Deployed INJURED)
         * 
         * @return UnitState * - a InjuredState() object
         */
        virtual UnitsState * changeUnitState();

        /**
         * @brief Prints the current state of the unit
         * 
         */
        virtual void request();

};

#endif
