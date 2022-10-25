#ifndef PLATOONSTRATEGY_H
#define PLATOONSTRATEGY_H

#include "../Platoon/Platoon.h"

using namespace std;

class PlatoonStrategy
{
public:

	/**
	 * @brief This is a pure virtual method which will attack a platoon from a different alliance
	 * baised on the current strategy of the chosen platoon
	 * 
	 * @param plankton is the platoon that will be attacked 
	 */
	virtual void attack(Unit *plankton) = 0;

	/**
	 * @brief This method allows for a platoon to change its current strategy to the other strategy available
	 * 
	 * @return PlatoonStrategy*
	 */
	virtual PlatoonStrategy* toggleStrategy() = 0;

	/**
	 * @brief Get the Platoon Strategy string
	 * 
	 * @return string of the current strategy
	 */
	virtual string getPlatoonStrategy() = 0;
};

#endif
