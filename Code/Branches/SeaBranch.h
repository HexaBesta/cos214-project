#ifndef SEABRANCH_H
#define SEABRANCH_H

#include "Branch.h"

using namespace std;

class SeaBranch : public Branch
{

public:
	/**
	 * @brief Constructor, initialises unit pointer of branch
	 *
	 * @param unit the unit pointer to call parent class constructor with
	 */
	SeaBranch(Unit *unit);

	/**
	 * @brief Prints the branch name
	 *
	 */
	void print();
};

#endif
