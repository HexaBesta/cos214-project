#ifndef BATTLE_H
#define BATTLE_H

#include "../Platoon/Platoon.h"
#include "../Map/Area.h"
#include <string>

using namespace std;

class Battle
{

private:

	/**
	 * @brief Allows the active side to change strategy before attacking
	 * 
	 * 
	 */
	virtual void changeStrategy();

	/**
	 * @brief Attack will call the active side's attack method. 
	 * 
	 * @details Will call the active platoon's attack method on the passive platoon
	 *  		Afterwards will perform a health check on the passive platoon
	 * 
	 */

	virtual void attack();

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
	 *          - Will initiate battle loop
	 * 
	 * @param side1 will be the defending unit (Platoon that was in area first)
	 * @param side2 the unit who marched into an occupied area
	 * @param area 
	 */
	Battle(TheatreOfWar * air, TheatreOfWar * land, Area * area);

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

	/**
	 * @brief Will continue to alternate turns while the battle is active and print state of battle between turns
	 * 
	 */
	void battleLoop();

private:
	vector<Platoon *> sides;

	/**
	 * @brief determines which platoon's turn it is 
	 * false = side 0
	 * true = side 1
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
