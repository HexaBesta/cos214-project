#ifndef PLATOONSTRATEGY_H
#define PLATOONSTRATEGY_H

#include "Platoon.h"

using namespace std;

class PlatoonStrategy
{

public:
	virtual void attack(Platoon *plankton) = 0;
};

#endif
