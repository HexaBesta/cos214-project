#ifndef AIRBRANCH_H
#define AIRBRANCH_H

#include "Branch.h"

using namespace std;

class AirBranch : public Branch
{
public:
	/**
	 * @brief Construct a new Air Branch object
	 *
	 * @param unit passed in set to decorator unit
	 */
	AirBranch(Unit *unit);
	void print();
};

#endif
