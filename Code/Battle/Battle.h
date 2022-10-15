#ifndef BATTLE_H
#define BATTLE_H

#include "../Platoon/Platoon.h"
#include "../Map/Area.h"
#include <string>

using namespace std;

class Battle {

private:
	Platoon *sideOne;
	Platoon *sideTwo;
	/**
	 * true = side 1
	 * false = side 2
	 */
	bool turn;
	bool active;
	Area *area;

public:
	virtual void changeStrategy() = 0;
	virtual void attack() = 0;
	virtual bool requestReinforcements() = 0;
	string stateSummary();
	void takeTurn();
};

#endif
