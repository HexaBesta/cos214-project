#ifndef AREA_H
#define AREA_H
#include "MapComponent.h"
#include "Platoon.h"
#include "Iterator.h"
#include "Battle.h"

class Area : public MapComponent
{

private:
	Platoon *defender;
	double xco;
	double yco;
	Platoon *attacker;

public:
	void updatePlatoons(int type, string platoonName);

	Iterator *createIterator();

	Battle *marchIn(Platoon *platoon);

	bool marchOut();

	bool requestReinforcements();
};

#endif
