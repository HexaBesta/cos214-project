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
		 * @brief returns the state of the currently set unit state 
		 */
		virtual void requestState();

		/**
		 * @brief Sets the unit state
		 * 
		 * @param unitState is the state you are changing to
		 */
		virtual void setUnitState(UnitsState *unitState = nullptr);

		/**
		 * @brief Returns the current health of the unit
		 */
		int getHealth();

		/**
		 * @brief Returns the current damage of the unit
		 */
		int getDamage();

		/**
		 * @brief The unit takes damage
		 *
		 * @param damage is the amount of damage the unit will take
		 */
		virtual bool takeDamage(int damage);

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

		
};

#endif
