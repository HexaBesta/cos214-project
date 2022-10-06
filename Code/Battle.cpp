#include "Battle.h"

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
Battle::Battle(Unit *side1, Unit *side2, Area *area)
{
	this->sideOne = (Platoon *)side1;
	this->sideTwo = (Platoon *)side2;

	this->area = area;

	this->active = true;
	this->turn = true;
}

/**
 * @brief Will print a summary of the current state of a battle
 *
 * @details Each platoon's cumulative health and damage will be shown along with the currently active side
 */
void Battle::getStateSummary()
{
	cout << "-------------------------------------------" << endl;
	cout << "\tPrinting Summary of State of Battle:" << endl;
	cout << endl;
	cout << "Area: " << endl;
	cout << "Insert call to area details here once defined" << endl
		 << endl;
	cout << "Turn: ";
	if (this->turn)
	{
		cout << "Side 1" << endl;
	}
	else
	{
		cout << "Side 2" << endl;
	}
	cout << "SIDE 1: add print" << endl;

	// this->sideOne->print();

	cout << "SIDE 2: add print" << endl;

	// this->sideTwo->print();

	cout << endl;
	cout << "-------------------------------------------" << endl;
}

/**
 * @brief Template method to initiate turn taken by active side
 *
 * @details Turn will consist of:
 * 			- Changing Strategy (optional)
 * 			- Attacking (required)
 *			- Requesting reinforcements (optional)
 */
void Battle::takeTurn()
{
	/*
	Check which platoon take turn (active)
	*/

	Platoon *activePlatoon;
	Platoon *passivePlatoon;
	if (this->turn)
	{
		activePlatoon = sideOne;
		passivePlatoon = sideTwo;
	}
	else
	{
		activePlatoon = sideTwo;
		passivePlatoon = sideOne;
	}

	/*
	Change strategy: Ask user input to check if strategy change necessary
	*/
	int resp;
	cout << "Do you want to change strategy?" << endl
		 << "1. Yes\n2. No" << endl;
	cin >> resp;

	// clear buffer
	cin.ignore(30, '\n');

	if (resp == 1)
	{
		activePlatoon->changeStrategy();
	}

	/*
	Attack!
	*/
	activePlatoon->attack(passivePlatoon);

	cout << "!!!!!!!!!!!!!Remember to add health check" << endl;

	// if(passivePlatoon->getHealth()<=0){
	// 	cout<<activePlatoon->getName()<<" has annihilated "<<passivePlatoon->getName()<<endl;
	// 	this->active = false;
	// }

	/*
	Request reinforcements after printing state of platoon.
	*/
	// activePlatoon.print();
	cout << "!!!!!!!!!!!!!Remember to print platoon in Battle takeTurn" << endl;

	if (this->requestReinforcements())
	{
		cout << "Reinforcements that were requested are in route" << endl;
	}
	else
	{
		cout << "There will be no reinforcements coming" << endl;
	}

	cout << "END OF TURN"
		 << "################################################" << endl;
	this->turn = (this->turn + 1) % 2;
}



/**
 * @brief active side can request reinforcements from neighbouring area's.
 *
 * @details Active side can request reinforcements after they attack
 * 			Will make use of the Observer pattern to function:
 * 			The Area's (subject) notify will be called so that the Map (observer) can be updated to check availability
 *
 * @return true if there is an adjacent Area with platoons from the same alliance able to send reinforcements
 * @return false otherwise
 */

bool Battle::requestReinforcements()
{
	int resp;
	cout << "Request Reinforcements" << endl
		 << "1. Troops\n2. Weapons\n3. Goods \n4. Not necessary" << endl;
	cin >> resp;

	// clear buffer
	cin.ignore(30, '\n');

	if (resp == 0 || resp == 1 || resp == 2)
	{
		return this->area->requestReinforcements(resp);
	}
	else
	{
		return false;
	}
}
