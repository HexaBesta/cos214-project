#include "Battle.h"

Battle::Battle(Unit *side1, Unit *side2, Area *area)
{
	this->sides.push_back((Platoon *)side1);
	this->sides.push_back((Platoon *)side2);

	this->area = area;

	this->active = true;
	this->turn = false;
}

void Battle::getStateSummary()
{
	cout << "-------------------------------------------" << endl;
	cout << "\tPrinting Summary of State of Battle:" << endl;
	cout << endl;
	cout << "Area: " << endl;
	cout << "Insert call to area details here once defined" << endl
		 << endl;
	cout << "Turn: ";
	if (!this->turn)
	{
		cout << "Side 1" << endl;
	}
	else
	{
		cout << "Side 2" << endl;
	}
	cout << "SIDE 1: add print" << endl;

	// this->sides.at(0)->print();

	cout << "SIDE 2: add print" << endl;

	// this->sides.at(1)->print();

	cout << endl;
	cout << "-------------------------------------------" << endl;
}

void Battle::takeTurn()
{

	/*
	Change strategy: Ask user input to check if strategy change necessary
	*/
	this->changeStrategy();

	/*
	Attack!
	*/
	this->attack();

	/*
	Print active platoon after attack
	*/

	// activePlatoon.print();
	cout << "!!!!!!!!!!!!!Remember to print platoon in Battle takeTurn" << endl;

	/*
	Request reinforcements after printing state of platoon if battle active.
	*/

	if (active)
	{
		if (this->requestReinforcements())
		{
			cout << "Reinforcements that were requested are in route" << endl;
		}
		else
		{
			cout << "There will be no reinforcements coming" << endl;
		}
	}

	cout << "END OF TURN"
		 << "################################################" << endl;
	this->turn = (this->turn + 1) % 2;
}

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
		//Should be able to request specific reinforcements
		return this->area->requestReinforcements();
	}
	else
	{
		return false;
	}
}

void Battle::changeStrategy()
{
	int resp;
	cout << "Do you want to change strategy?" << endl
		 << "1. Yes\n2. No" << endl;
	cin >> resp;

	// clear buffer
	cin.ignore(30, '\n');

	if (resp == 1)
	{
		this->sides.at(turn)->changeStrategy();
	}
}

void attack(Platoon *activePlatoon, Platoon *passivePlatoon)
{
	activePlatoon->attack(passivePlatoon);

	cout << "!!!!!!!!!!!!!Remember to add health check" << endl;

	// if(this->sides.at(!turn)->getHealth()<=0){
	// 	cout<<this->sides.at(turn)->getName()<<" has annihilated "<<this->sides.at(!turn)->getName()<<endl;
	// 	this->active = false;
	// }
}