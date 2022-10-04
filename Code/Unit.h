#ifndef UNIT_H
#define UNIT_H

#include "UnitsState.h"
class Platoon;

using namespace std;

class Unit
{

private:
	UnitsState *unitState;
	int health;

public:
	virtual void attack(Platoon *other) = 0;

	void request();

	void setUnitState(UnitsState *unitState);

	int takeDamage(int damage);
};

#endif
