#ifndef BRANCH_H
#define BRANCH_H

#include "Unit.h"
using namespace std;

class Branch : public Unit
{
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
	 * @brief Forwards change strategy to unit
	 *
	 */
	virtual void changeStrategy();

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
	virtual bool takeDamage(int damage, bool pewpew);

	/**
	 * @brief Get the branch of the unit as a string
	 *
	 * @return string
	 */
	virtual string getBranch();

	/**
	 * @brief Gets state of unit
	 *
	 */
	virtual string getState();

	/**
	 * @brief Get the size of the unit in branch
	 *
	 * @return size of unit
	 */
	virtual int getSize();

	/**
	 * @brief Calls the units getAmmo and returns result
	 *
	 * @return int* ammo - [0] = pewPew, [1] = boomBoom
	 */
	virtual int *getAmmo();

	/**
	 * @brief Splits the unit into equal halves if possible
	 *
	 * @return Unit*
	 */
	virtual Unit *split()=0;

	/**
	 * @brief Sets the country of the wrapped unit
	 * 
	 * @param c 
	 */
	virtual void setCountry(Country* c);

	/**
	 * @brief Get the Country of the wrapped unit
	 * 
	 * @return Country* 
	 */
	virtual Country* getCountry();

	/**
	 * @brief Get the Alliance of the wrapped unit
	 * 
	 * @return Alliances* 
	 */
	virtual string getAlliance();

	/**
	 * @brief Merges two units together
	 *
	 * @param others
	 */
	virtual void join(Unit *others);

	/**
	 * @brief Get the Unit object from branch
	 * 
	 * @return Unit* 
	 */
	virtual Unit * getUnit();

	/**
	 * @brief Set the Texture of the branch's unit (overridden)
	 * 
	 */
	virtual void setTexture();

	/**
	 * @brief Returns the sprite of trhe unit wrapped by the branch. Used for drawing and positioning the platoon on the GUI map
	 * 
	 * @return sf::Sprire* 
	 */
	virtual sf::Sprite* getSprite();
	
	/**
	 * @brief Destroy the Branch object
	 *
	 */
	virtual ~Branch();
	virtual int *getAmmo();

	/**
	 * @brief Returns the average moral of the branch
	 * 
	 * @return int 
	 */
	virtual int getMoral();

	/**
	 * @brief Get the total health of the current branch
	 * 
	 * @return int 
	 */
	virtual int getHealth();

	/**
	 * @brief Destroy the Branch object
	 *
	 */
	virtual ~Branch();
};

#endif