#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <iostream>
#include "DeadState.h"
class Platoon;

using namespace std;

class Unit
{

protected:
	UnitsState *unitState;
	int health;
	virtual void print()=0;
	int damage;
	
public:
	virtual void attack(Platoon *other) = 0;

	virtual void requestState();

	virtual void setUnitState(UnitsState *unitState);


	virtual int takeDamage(int damage);
};

#endif
