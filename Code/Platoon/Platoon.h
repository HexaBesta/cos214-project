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
	/**
	 * @brief Construct a new Platoon object with the given parameters
	 *
	 * @param human the vector Units of humans in the platoon
	 * @param vehicles the vector Units of vehicles in the platoon
	 * @param weapons the vector Weapon of weapons in the platoon
	 */
	Platoon(vector<Unit*> human, vector<Unit*> vehicles, vector<Weapon*> weapons);
	
	/**
	 * @brief Construct a new Platoon using BobTheBuilder
	 */
	void construct();
	
	/**
	 * @brief Change the strategy of the current Platoon
	 */
	void changeStrategy();
	
	/**
	 * @brief Split the current platoon in half
	 * 
	 * @return a unit pointer of one of the split platoons
	 */
	Unit *split();
	
	/**
	 * @brief Join a platoon with a unit
	 * @param platoon a pointer of the unit that will be joined with the current platoon
	 */
	void join(Unit *platoon);
	
	/**
	 * @brief function to take damage from another platoon and see what type of damage and how much
	 * 
	 * @param damage is the amount of damage inflected to the platoon
	 * @param checkPewPew checks what strategy the platoon that attacked has
	 * 
	 * @return boolean indicating if the platoon is alive or dead
	 */
	bool takeDamage(int damage, bool checkPewPew);

	/**
	 * @brief virtual function to attack a certain platoon
	 * 
	 * @param other is a pointer of the platoon that will be attacked 
	 */
	virtual void attack(Platoon *other);
};

#endif
