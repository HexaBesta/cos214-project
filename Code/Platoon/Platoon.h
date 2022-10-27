#ifndef PLATOON_H
#define PLATOON_H

#include <vector>
#include <random>

#include "../Builder/BobTheBuilder.h"
#include "../Unit/Unit.h"
#include "../Weapon/Weapon.h"
#include "../PlatoonStrat/BoomBoomAttack.h"
#include "../PlatoonStrat/PewPewAttack.h"
#include "../PlatoonStrat/PlatoonStrategy.h"
#include "../TransportFactory/Ammunition.h"
#include "../TransportFactory/Goods.h"
#include "../TransportFactory/People.h"

using namespace std;

class Platoon : public Unit {

private:
	BobTheBuilder *bob;
	vector<Unit *> humans;
	vector<Unit *> vehicles;
	int pewpew;
	int boomboom;
	int moral;
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
	Platoon(vector<Unit*> human, vector<Unit*> vehicles, int pewpew, int boomboom);
	
	/**
	 * @brief Construct a new Platoon using BobTheBuilder
	 */
	void construct();
	
	/**
	 * @brief Get the health of the platoon
	 * 
	 * @return int
	 */
	int getHealth();

	/**
	 * @brief Get the size of the platoon by counting the amount of vehicles and humans
	 * 
	 * @return int size
	 */
	int getSize();

	/**
	 * @brief Get the total damage of the platoon by accumulating the damage of humans and vehicles
	 * 
	 * @return int damage
	 */
	int getDamage();

	/**
	 * @brief Get the ammount of ammo for platoon
	 * 
	 * @return int[] returns an array where index 0 is the amount of pewpew bullets and index 1 is the amount of boomboom explosives
	 */
	int* getAmmo();

	/**
	 * @brief decreases the ammo of the platoon
	 * 
	 * @param pewpew checks if pewpew strat so that it can decrease the bullets by the amount shot. If boomboom only decreases by 1
	 */
	void decreaseAmmo();
	/**
	 * @brief Sets the total health of the current platoon using the human and vehicle vector
	 * 
	 */
	void setAccumlateHealth();

	/**
	 * @brief This will allow for a platoon to receive goods from the factory created in the area
	 * This however will only health a few amount of humans from the vector
	 * 
	 * @param good 
	 */
	void retrieveGoods(Goods* good);

	/**
	 * @brief This will allow for a platoon to receive ammo from the factory created in the area
	 * 
	 * @param good 
	 */
	void retrieveAmmo(Ammunition* ammo);

	/**
	 * @brief This will allow for a platoon to receive medicial help from the factory created in the area
	 * This however will only health a few amount of humans from the vector
	 * 
	 * @param good 
	 */
	void retrieveMedic(People* medic);

	/**
	 * @brief Get the moral of the platoon
	 * 
	 * @return int
	 */
	int getMoral();
	
	/**
	 * @brief Sets the total moral of the current platoon using the human vector
	 * 
	 */
	void setAccumlateMoral();

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
	virtual void attack(Unit *other);

	/**
	 * @brief function will take a random soldier or vehicle from the humans and vehicles vectors
	 * 
	 * @return Unit* will be returned to controll the randomly selected human or vehicle
	 */
	Unit* takeRandom();

	/**
	 * @brief Destroy the Platoon object
	 * 
	 */
	virtual ~Platoon();
};

#endif
