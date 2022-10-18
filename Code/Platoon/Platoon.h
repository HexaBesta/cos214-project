#ifndef PLATOON_H
#define PLATOON_H

#include <vector>
#include <random>

#include "../Builder/BobTheBuilder.h"
#include "../Unit/Unit.h"
#include "../Weapon/Weapon.h"
#include "../PlatoonStrat/BoomBoomAttack.h"
#include "../PlatoonStrat/PewPewAttack.h"

using namespace std;

class Platoon : public Unit {

private:
	BobTheBuilder *bob;
	vector<Unit *> humans;
	vector<Unit *> vehicles;
	vector<Weapon *> weapons;
	PlatoonStrategy * strategy;
	virtual void print();

public:
	Platoon(vector<Unit*> human, vector<Unit*> vehicles, vector<Weapon*> weapons);
	void construct();
	void changeStrategy();
	Platoon *splitPlatoon();
	void joinPlatoon(Platoon *platoon);
	int takeDamage(int damage, bool checkPewPew);
	virtual void attack(Platoon *other);
};

#endif
