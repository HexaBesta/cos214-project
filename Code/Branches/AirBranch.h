#ifndef AIRBRANCH_H
#define AIRBRANCH_H

#include "Branch.h"

using namespace std;

class AirBranch : public Branch
{	
public:
	/**
	 * @brief Constructor, initialises unit pointer of branch
	 *
	 * @param unit the unit pointer to call parent class constructor with
	 */
	AirBranch(Unit *unit);

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
