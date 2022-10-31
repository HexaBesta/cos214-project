#ifndef BATTLE_H
#define BATTLE_H

#include "Platoon.h"
#include "Area.h"
#include "Player.h"
#include <string>

using namespace std;

class Battle
{

private:

	/**
	 * @brief Allows the active side to change strategy before attacking
	 * 
	 * @param active the unit whose turn it is 
	 */
	virtual void changeStrategy(Unit * active);

	/**
	 * @brief Attack will call the active side's attack method. 
	 * 
	 * @details Will call the active platoon's attack method on the passive platoon
	 *  		Afterwards will perform a health check on the passive platoon
	 * 
	 * @param active the unit whose turn it is 
	 * @param passive the unit that will take damage
	 */

	virtual void attack(Unit * active, Unit * passive);

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

	/**
	 * @brief Checks whether active side wants to retreat and retreats if requested
	 * 
	 * @return true if side retreats
	 * @return false if side does not retreat
	 */
	bool checkRetreat();

	/**
	 * @brief Set the Attacker To Defender in area if attacker wins
	 * 
	 */
	void setAttackerToDefender();


public:

	/**
	 * @brief Construct a new Battle object
	 * 
	 * @details Constructor will set member functions. 
	 * 			- Turn will be set to true (side1 will take their turn first)
	 * 			- Active will be set to true (attacker attack first)
	 * 
	 * @param air the air Theatre of War 
	 * @param side2 the land Theatre Of War
	 * @param area 
	 */
	Battle(TheatreOfWar * air, TheatreOfWar * land, Area * area, Player * player);

	/**
	 * @brief Get the Air  TheatreOfWar object
	 * 
	 * @return TheatreOfWar* of the air theatre
	 */
	TheatreOfWar * getAir();

	/**
	 * @brief Get the Land TheatreOfWar object
	 * 
	 * @return TheatreOfWar* of the land theatre
	 */
	TheatreOfWar * getLand();

	/**
	 * @brief Get the Turn object
	 * 
	 * @return true 
	 * @return false 
	 */
	bool getTurn(); 

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
	 * 			- Retreat 
	 * 				OR
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

	/**
	 * @brief Will resolve the battle when called at end of turn
	 * 
	 */
	void resolveBattle();


private:
	TheatreOfWar * air;
	TheatreOfWar * land;

	/**
	 * @brief determines which platoon's turn it is 
	 * false = defender
	 * true = attacker
	*/
	bool turn;

	/**
	 * @brief Check that neither platoon's state is Dead
	 * 
	 */
	bool active;
	
	Area *area;

	Player * player;


};


#endif