#ifndef PLATOONSTRATEGY_H
#define PLATOONSTRATEGY_H

#include "../Platoon/Platoon.h"

using namespace std;

class PlatoonStrategy
{

public:
	virtual void attack(Unit *plankton) = 0;
	virtual PlatoonStrategy* toggleStrategy() = 0;
};

#endif
