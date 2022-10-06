#ifndef BATTLE_H
#define BATTLE_H

#include "Platoon.h"
#include "Area.h"
#include <string>

using namespace std;

class Battle
{

private:

	//Pretty sure we don't need this
	// /**
	//  * @brief Allows the active side to change strategy before attacking
	//  * 
	//  */
	// virtual void changeStrategy();

	// /**
	//  * @brief Attack will call the active side's attack method. 
	//  * 
	//  */

	// virtual void attack();

	/**
	 * @brief active side can request reinforcements from neighbouring area's.
	 * 
	 * @details Active side can request reinforcements after they attack 
	 * 			Will make use of the Observer pattern to function:
	 * 			The Area's (subject) notify will be called so that the Map (observer) can be updated to check availability
	 * 
	 * @return true if there is an adjacent Area with platoons from the same alliance able to send reinforcements
	 * @return false otherwise, including when no reinforcements are requested
	 */

	virtual bool requestReinforcements();


public:

	/**
	 * @brief Construct a new Battle object
	 * 
	 * @details Constructor will set member functions. 
	 * 			- Turn will be set to true (side1 will take their turn first)
	 * 			- ACtive will be set to true
	 * 
	 * @param side1 will be the defensing unit (Platoon that was in area first)
	 * @param side2 the unit who marched into an occupied area
	 * @param area 
	 */
	Battle(Unit * side1, Unit * side2, Area * area);

	/**
	 * @brief Will print a summary of the current state of a battle
	 * 
	 * @details Each platoon's cumulative health and damage will be shown along with the currently active side
	 */
	void getStateSummary();

	/**
	 * @brief Template method to initiate turn taken by active side
	 * 
	 * @details Turn will consist of:
	 * 			- Changing Strategy (optional)
	 * 			- Attacking (required)
	 *			- Requesting reinforcements (optional)
	 */

	void takeTurn();

private:
	Platoon *sideOne;
	Platoon *sideTwo;

	/**
	 * @brief Indicated active side 
	 * true = side 1
	 * false = side 2
	 * Hereafter
	*/
	bool turn;

	/**
	 * @brief Check that neither platoon's state is Dead
	 * 
	 */
	bool active;
	
	Area *area;


};

#endif
