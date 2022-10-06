#ifndef DEADSTATE_H
#define DEADSTATE_H
#include "UnitsState.h"
using namespace std;

class DeadState : public UnitsState
{
    public:

        /**
         * @brief Adjusts damage dealt based on UnitState 
         * 
         * @param damage - the default damage dealt by the unit
         * @return double - the damage dealt after adjustment - 0
         */
        virtual double attackStrength(double damage);

        /**
         * @brief Cannot transfer from Dead
         * 
         * @return Return NULL
         */
        virtual UnitsState * changeUnitState();

        /**
         * @brief Prints the current state of the unit
         * 
         */
        virtual void request();

};

#endif
