#ifndef LANDBRANCH_H
#define LANDBRANCH_H

#include "Branch.h"
#include "../Unit/Unit.h"

using namespace std;

class LandBranch : public Branch
{

public:

	/**
	 * @brief Constructor, initialises unit pointer of branch
	 *
	 * @param unit the unit pointer to call parent class constructor with
	 */
	LandBranch(Unit *unit);

	/**
	 * @brief Prints the branch name
	 *
	 */
	void print();

	/**
	 * @brief Get the Branch of the unit
	 * 
	 * @return string 
	 */
	string getBranch();
};

#endif
