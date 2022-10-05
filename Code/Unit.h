#ifndef UNIT_H
#define UNIT_H

#include "DeadState.h"
class Platoon;

using namespace std;

class Unit
{

private:
	UnitsState *unitState;
	int health;

public:
	virtual void attack(Platoon *other) = 0;

	void requestState();

	void setUnitState(UnitsState *unitState = nullptr);

	virtual int takeDamage(int damage);
};

#endif
