#ifndef PLATOON_H
#define PLATOON_H

#include <vector>
#include "BobTheBuilder.h"
#include "Unit.h"
#include "Weapon.h"
#include "PlatoonStrategy.h"


using namespace std;

class Platoon : public Unit
{

private:
	BobTheBuilder *bob;
	vector<Unit *> humans;
	vector<Unit *> vehicles;
	vector<Weapon *> weapons;
	PlatoonStrategy * strategy;

public:
	void construct();

	void changeStrategy();

	Platoon *splitPlatoon();

	void joinPlatoon(Platoon *platoon);

	//added

	int takeDamage(int damage);

	virtual void attack(Platoon *other);
};

#endif
