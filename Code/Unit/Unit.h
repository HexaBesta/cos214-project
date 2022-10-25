#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <iostream>
#include "../UnitState/DeadState.h"
#include "../Country/Country.h"
class Platoon;

using namespace std;

class Unit {
	protected:
		UnitsState *unitState;
		int health;
		int moral;
		virtual void print()=0;
		int damage;
		Country* country;
		
	public:
		/**
		 * @brief pure virtual function used to return the attack method of each state
		 * 
		 * @param other is the other platoon we are going to attack
		 */
		virtual void attack(Unit *other) = 0;

		/**
		 * @brief Stubbed method for changing strategy - only applicable to platoons
		 * 
		 */
		virtual void changeStrategy();

		/**
		 * @brief prints the state of the currently set unit state 
		 */
		virtual void requestState();

		/**
		 * @brief Returns state of unit
		 * 
		 */
		virtual string getState();

		/**
		 * @brief Sets the unit state
		 * 
		 * @param unitState is the state you are changing to
		 */
		virtual void setUnitState(UnitsState *unitState = nullptr);

		/**
		 * @brief Returns the current health of the unit
		 */
		virtual int getHealth();

		/**
		 * @brief Returns the current damage of the unit
		 */
		virtual int getDamage();

		/**
		 * @brief Sets the units health to passed in parameter
		 * 
		 * @param health takes in the health that will be set
		 */
		void setHealth(int health);
		/**
	 	* @brief Returns the current moral of the unit
	 	* 
	 	* @return int 
	 	*/
		virtual int getMoral();

		/**
		 * @brief Get the size of the unit
		 * 
		 * @return int size
		 */
		virtual int getSize();

		/**
		 * @brief Set the current moral of the unit
		 * 
		 * @param moral takes in the moral that will be set
		 */
		virtual void setMoral(int moral);
		/**
		 * @brief The unit takes damage
		 *
		 * @param damage is the amount of damage the unit will take
		 */
		virtual bool takeDamage(int damage,bool typeStrat = true);

		/**
		 * @brief Splits the unit into equal halves if possible
		 * 
		 * @return Unit* 
		 */
		virtual Unit* split();

		/**
		 * @brief Merges two units together
		 * 
		 * @param others 
		 */
		virtual void join(Unit* others);

		/**
		 * @brief Get the Branch of the unit
		 * @attention Branch class needs to be able to return some indication of which branch
		 * @return string 
		 */
		virtual string getBranch();

		/**
		 * @brief Get the Alliance that the unit beloings to.
		 * @attention Units  needs to be able to return some indication of which allaince they belong to
		 * @return string 
		 */
		virtual string getAlliance();

		/**
		 * @brief Set the Country of this unit
		 * 
		 * @param country 
		 */
		virtual void setCountry(Country* country);

		/**
		 * @brief Get the Country of this unit
		 * 
		 * @return Country* 
		 */
		virtual Country* getCountry();

		/**
		 * @brief Prints all the details about Unit
		 * 
		 * @details Pure virtual - implemented in subclasses
		 * 
		 */
		virtual void print();

		/**
	 	* @brief Returns random member of platoon to take damage - in other Units, return this
	 	* 
	 	* @return Unit* this
	 	*/
		virtual Unit * takeRandom();

		/**
		 * @brief Destroy the Unit object
		 * 
		 */
		virtual ~Unit();
		
};

#endif
