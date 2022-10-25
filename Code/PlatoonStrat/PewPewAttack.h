#ifndef PEWPEWATTACK_H
#define PEWPEWATTACK_H

#include "PlatoonStrategy.h"

using namespace std;

class PewPewAttack : public PlatoonStrategy
{

public:

	virtual void attack(Unit *plankton);

	virtual PlatoonStrategy* toggleStrategy();

	virtual string getPlatoonStrategy();
};

#endif
