#ifndef PLATOON_H
#define PLATOON_H

#include <vector>
#include <random>
#include "BobTheBuilder.h"
#include "Unit.h"
#include "Weapon.h"
#include "BoomBoomAttack.h"
#include "PewPewAttack.h"
#include "PlatoonStrategy.h"
#include "Ammunition.h"
#include "Goods.h"
#include "People.h"

#include "ImageLibrary.h"

using namespace std;

class Platoon : public Unit
{

private:
	vector<Unit *> humans;
	vector<Unit *> vehicles;
	int pewpew;
	int boomboom;
	int moral;
	PlatoonStrategy *strategy = NULL;
	sf::Sprite* sprite;
	sf::Texture texture;

public:
	
	/**
	 * @brief Construct a new Platoon object with the given parameters
	 *
	 * @param human the vector Units of humans in the platoon
	 * @param vehicles the vector Units of vehicles in the platoon
	 * @param weapons the vector Weapon of weapons in the platoon
	 */
	Platoon(vector<Unit *> human, vector<Unit *> vehicles, int pewpew, int boomboom);

	/**
	 * @brief Construct a new Platoon using BobTheBuilder
	 */
	void construct();

	/**
	 * @brief Get the health of the platoon
	 *
	 * @return int
	 */
	virtual int getHealth();

	/**
	 * @brief Get the size of the platoon by counting the amount of vehicles and humans
	 *
	 * @return int size
	 */
	virtual int getSize();

	/**
	 * @brief Get the current strategy of the platoon
	 * 
	 * @return string - will either return pew or boom
	 */
	virtual string getStrategyType();

	/**
	 * @brief Get the total damage of the platoon by accumulating the damage of humans and vehicles
	 * 
	 * @return int damage
	 */
	virtual int getDamage();

	/**
	 * @brief Get the ammount of ammo for platoon
	 *
	 * @return int[] returns an array where index 0 is the amount of pewpew bullets and index 1 is the amount of boomboom explosives
	 */
	virtual int* getAmmo();

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
	void retrieveGoods(Transport * good);


	/**
	 * @brief This will allow for a platoon to receive ammo from the factory created in the area
	 *
	 * @param good
	 */
	void retrieveAmmo(Transport * ammo);

	/**
	 * @brief This will allow for a platoon to receive medicial help from the factory created in the area
	 * This however will only health a few amount of humans from the vector
	 *
	 * @param good
	 */
	void retrieveHealth(Transport* medic);

	/**
	 * @brief Calls all replenish functions
	 * 
	 * @param transport 
	 */
	virtual void replenish(Transport ** transport);

	/**
	 * @brief Get the moral of the platoon
	 *
	 * @return int
	 */
	virtual int getMoral();

	/**
	 * @brief Get the Average Moral based on the size of the platoon
	 * 
	 * @return double 
	 */
	virtual int getAverageMoral();
	
	/**
	 * @brief Sets the total moral of the current platoon using the human vector
	 *
	 */
	void setAccumlateMoral();

	/**
	 * @brief Change the strategy of the current Platoon
	 */
	virtual void changeStrategy();
	
	/**
	 * @brief Split the current platoon in half
	 *
	 * @return a unit pointer of one of the split platoons
	 */
	virtual Unit *split();
	
	/**
	 * @brief Join a platoon with a unit
	 * @param platoon a pointer of the unit that will be joined with the current platoon
	 */
	virtual void join(Unit *platoon);
	
	/**
	 * @brief function to take damage from another platoon and see what type of damage and how much
	 *
	 * @param damage is the amount of damage inflected to the platoon
	 * @param checkPewPew checks what strategy the platoon that attacked has
	 *
	 * @return boolean indicating if the platoon is alive or dead
	 */
	virtual bool takeDamage(int damage, bool checkPewPew);

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
	virtual Unit *takeRandom();

	/**
	 * @brief return a string representation of the platoon
	 *
	 * @return string
	 */
	virtual string toString(int lineLen);

	/**
	 * @brief Get the Sprite of this platoon
	 *
	 * @return sf::Sprite
	 */
	virtual sf::Sprite* getSprite();

	/**
	 * @brief Set the Sprite Location of the platoon's sprite
	 *
	 * @param x The X coordinate of the sprite (unscaled)
	 * @param y The Y coordinate of the sprite (unscaled)
	 */
	void setSpriteLocation(int x, int y);

	/**
	 * @brief Loads the air image into the texture of this sprite
	 * 
	 */
	virtual void setAirTexture();

	/**
	 * @brief Loads the land image into the texture of this sprite
	 * 
	 */
	virtual void setLandTexture();

	/**
	 * @brief Destroy the Platoon object
	 *
	 */
	virtual ~Platoon();
};

#endif
