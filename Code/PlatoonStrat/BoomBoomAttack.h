#ifndef BOOMBOOMATTACK_H
#define BOOMBOOMATTACK_H

#include "PlatoonStrategy.h"
using namespace std;

class BoomBoomAttack : public PlatoonStrategy
{

public:
	virtual void attack(Unit* plankton);

	virtual PlatoonStrategy* toggleStrategy();

	virtual string getPlatoonStrategy();
};

#endif
