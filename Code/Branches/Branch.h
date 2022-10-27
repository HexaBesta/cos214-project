#ifndef BRANCH_H
#define BRANCH_H

#include "../Unit/Unit.h"
using namespace std;

class Branch : public Unit {
	protected:
		Unit *unit;
	public:
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
		virtual string toString() = 0;


		string toString(int);

		/**
		 * @brief Calls the unit's attack method 
		 * 
		 * @param other the platoon which the unit will attack
		 * 
		 */
		virtual void attack(Unit *other);

		/**
		 * @brief Calls the unit's requestState
		 * 
		 */
		virtual void requestState();

		/**
		 * @brief Get the strategy of the unit
		 * 
		 * @return string - return pew or boom
		 */
		virtual string getStrategyType();

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
	 * @brief Calls the units getAmmo and returns result
	 * 
	 * @return int* ammo - [0] = pewPew, [1] = boomBoom
	 */
	virtual int * getAmmo();

	/**
	 * @brief Destroy the Branch object
	 * 
	 */
	virtual ~Branch();
};

#endif
