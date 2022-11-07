
#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <iostream>
#include "CivilianState.h"
#include "Country.h"
#include <SFML/Graphics.hpp>
class Platoon;

class Transport;

using namespace std;

class Unit
{
protected:
	UnitsState *unitState;
	int health;
	int moral;
	// virtual void print()=0;
	int damage;
	Country *country;

public:
	/**
	 * @brief Construct a new Unit object
	 *
	 */
	Unit();
	/***
	 * @brief Constructor for Unit
	 *
	 * @param health the health of the unit
	 * @param moral the moral of the unit
	 * @param country sets the country in which the unit is associated to
	 * @param fitState will check if the unit needs to be in the fitState or civilianState
	 */
	Unit(int health, int moral, int damage, Country *country, bool fitState);

	/**
	 * @brief pure virtual function used to return the attack method of each state
	 *
	 * @param other is the other platoon we are going to attack
	 */
	virtual void attack(Unit *other) = 0;

	/**
	 * @brief Stubbed method for changing strategy - only applicable to platoons
	 *
	 */
	virtual void changeStrategy();

	/**
	 * @brief prints the state of the currently set unit state
	 */
	virtual void requestState();

	/**
	 * @brief Stubbed method - will be used for platoon
	 *
	 * @return string
	 */
	virtual string getStrategyType();

	/**
	 * @brief Returns state of unit
	 *
	 */
	virtual string getState();

	/**
	 * @brief Sets the unit state
	 *
	 * @param unitState is the state you are changing to
	 */
	virtual void setUnitState(UnitsState *unitState = nullptr);

	/**
	 * @brief Returns the current health of the unit
	 */
	virtual int getHealth();

	/**
	 * @brief Stubbed function used in Platoon
	 *
	 * @return double
	 */
	virtual int getAverageMoral();

	/**
	 * @brief Returns the current damage of the unit
	 */
	virtual int getDamage();

	/**
	 * @brief Sets the units health to passed in parameter
	 *
	 * @param health takes in the health that will be set
	 */
	virtual void setHealth(int health);
	/**
	 * @brief Returns the current moral of the unit
	 *
	 * @return int
	 */
	virtual int getMoral();

	/**
	 * @brief Get the size of the unit
	 *
	 * @return int size
	 */
	virtual int getSize();

	/**
	 * @brief Set the current moral of the unit
	 *
	 * @param moral takes in the moral that will be set
	 */
	virtual void setMoral(int moral);
	/**
	 * @brief The unit takes damage
	 *
	 * @param damage is the amount of damage the unit will take
	 */
	virtual bool takeDamage(int damage, bool typeStrat = true);

	/**
	 * @brief Splits the unit into equal halves if possible
	 *
	 * @return Unit*
	 */
	virtual Unit *split();

	/**
	 * @brief Merges two units together
	 *
	 * @param others
	 */
	virtual void join(Unit *others);

	/**
	 * @brief Get the Branch of the unit
	 * @attention Branch class needs to be able to return some indication of which branch
	 * @return string
	 */
	virtual string getBranch();

	/**
	 * @brief Returns the current Units pointer
	 *
	 * @return Unit*
	 */
	virtual Unit *getUnit();

	/**
	 * @brief Get the Alliance that the unit beloings to.
	 * @attention Units  needs to be able to return some indication of which allaince they belong to
	 * @return string
	 */
	virtual string getAlliance();

	/**
	 * @brief Set the Country of this unit
	 *
	 * @param country
	 */
	virtual void setCountry(Country *country);

	/**
	 * @brief Get the Country of this unit
	 *
	 * @return Country*
	 */
	virtual Country *getCountry();

	/**
	 * @brief Prints all the details about Unit
	 *
	 * @details Pure virtual - implemented in subclasses
	 *
	 */
	virtual string toString(int lineLen = 0);

	/**
	 * @brief Returns random member of platoon to take damage - in other Units, return this
	 *
	 * @return Unit* this
	 */
	virtual Unit *takeRandom();

	/**
	 * @brief Get the Ammo as an array - stubbed in unit
	 *
	 * @return int*
	 */
	virtual int *getAmmo();

	/**
	 * @brief Stupped function used in platoon to replenish units
	 *
	 * @param transport
	 */
	virtual void replenish(Transport **transport);

	/**
	 * @brief Get the Sprite of this unit
	 *
	 * @return sf::Sprite
	 */
	virtual sf::Sprite *getSprite();

	/**
	 * @brief Set the Sprite Location of the unit's sprite
	 *
	 * @param x The X coordinate of the sprite (unscaled)
	 * @param y The Y coordinate of the sprite (unscaled)
	 */
	void setSpriteLocation(int x, int y){};

	/**
	 * @brief Set the location of the text that displays the platoon's size
	 *
	 * @param x
	 * @param y
	 */
	virtual void setTextLocation(int x, int y);

	/**
	 * @brief Draws the unit on the window using the sfml library
	 *
	 * @param window
	 */
	virtual void draw(sf::RenderWindow *window);

	virtual void setTexture();

	virtual void setAirTexture();

	virtual void setLandTexture();

	/**
	 * @brief Destroy the Unit object
	 *
	 */
	virtual ~Unit();
};

#endif