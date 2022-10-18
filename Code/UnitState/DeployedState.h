#ifndef DEPLOYEDSTATE_H
#define DEPLOYEDSTATE_H
#include "UnitsState.h"
using namespace std;

class DeployedState : public UnitsState
{
	public:

        /**
         * @brief Prints the current state "Deployed: "
         * 
         */
        virtual void request();

};

#endif
