#ifndef BRANCH_H
#define BRANCH_H

#include "../Unit/Unit.h"
using namespace std;

class Branch : public Unit {
	public:
		Unit *unit;
		Branch(Unit *unit);
		virtual void print() = 0;
		virtual void attack(Platoon *other);
		virtual void request();
		virtual void setUnitState(UnitsState *unitState);
		virtual int takeDamage(int damage);
};

#endif
