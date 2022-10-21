#ifndef BRANCH_H
#define BRANCH_H

#include "../Unit/Unit.h"
using namespace std;

class Branch : public Unit
{
public:
	Unit *unit;
	/**
	 * @brief Initialises unit pointer of branch
	 *
	 * @param unit the unit pointer to initialise this->unit with
	 */
	Branch(Unit *unit);
	/**
	 * @brief Pure virtual function with specialisations printing specific branch
	 *
	 */
	virtual void print() = 0;
	/**
	 * @brief Calls the unit's attack method 
	 * 
	 * @param other the platoon which the unit will attack
	 * 
	 */
	virtual void attack(Platoon *other);
	/**
	 * @brief Calls the unit's requestState
	 * 
	 */
	virtual void requestState();
	/**
	 * @brief Calls the unit's setUnitState
	 * 
	 * @param unitState a pointer to to the new unitState
	 * 
	 */
	virtual void setUnitState(UnitsState *unitState);
	/**
	 * @brief Calls the unit's takeDamage
	 * 
	 * @param damage the amount of damage the unit should take, passed in as a parameter
	 * 
	 */
	virtual bool takeDamage(int damage);

	/**
	 * @brief Get the branch of the unit as a string
	 * 
	 * @return string 
	 */
	virtual string getBranch();

	/**
	 * @brief Destroy the Branch object
	 * 
	 */
	virtual ~Branch();
};

#endif
