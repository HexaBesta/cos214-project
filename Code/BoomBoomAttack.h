#ifndef BOOMBOOMATTACK_H
#define BOOMBOOMATTACK_H

#include "PlatoonStrategy.h"
using namespace std;

class BoomBoomAttack : public PlatoonStrategy
{

public:
	virtual void attack(Platoon plankton) = 0;
};

#endif
