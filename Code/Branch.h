#ifndef BRANCH_H
#define BRANCH_H

#include "Unit.h"
using namespace std;

class Branch : public Unit
{

public:
	Unit *unit;

	Branch(Unit *unit);
};

#endif
