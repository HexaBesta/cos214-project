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
	virtual string toString();

	/**
	 * @brief Get the Branch of the unit
	 *
	 * @return string
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