#ifndef AIRBRANCH_H
#define AIRBRANCH_H

#include "Branch.h"

using namespace std;

class AirBranch : public Branch
{
public:
	/**
	 * @brief Constructor makes new AirBranch instance and initialises unit pointer of branch
	 *
	 * @param unit the unit pointer to call parent class constructor with
	 */
	AirBranch(Unit *unit);

	/**
	 * @brief Returns the branch name
	 *
	 * @return string that contains the branch name
	 */
	virtual string toString();

	/**
	 * @brief Get the Branch of the unit
	 *
	 * @return returns string containing details about the branch
	 */
	virtual string getBranch();

	/**
	 * @brief Splits the unit into equal halves if possible
	 *
	 * @return Unit*
	 */
	virtual Unit *split();
  
  	/**
	 * @brief Set the Texture of this unit to the air texture
	 * 
	 */
	virtual void setTexture();
};

#endif