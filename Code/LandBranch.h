#ifndef LANDBRANCH_H
#define LANDBRANCH_H

#include "Branch.h"
#include "Unit.h"

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
	virtual string toString();

	/**
	 * @brief Get the Branch of the unit
	 * 
	 * @return string 
	 */
	virtual string getBranch();

	/**
		 * @brief Set the Texture of this unit to the land texture
		 * 
		 */
		virtual void setTexture();

	/**
	 * @brief Destroy the Land Branch object
	 * 
	 */
	virtual ~LandBranch();
};

#endif
