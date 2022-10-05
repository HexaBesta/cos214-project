#ifndef LANDBRANCH_H
#define LANDBRANCH_H

#include "Branch.h"
#include "Unit.h"

using namespace std;

class LandBranch : public Branch
{

public:
	LandBranch(Unit *unit);
};

#endif
