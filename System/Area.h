#ifndef AREA_H
#define AREA_H
#include "TheatreOfWar.h"
#include "MapComponent.h"
#include "Platoon.h"
#include "Iterator.h"
#include "Coordinate.h"
#include "TheatreOfWar.h"
#include "TransportFactory.h"
#include "PTFactory.h"
#include "ATFactory.h"
#include "GTFactory.h"
#include "Visitor.h"
#include "Country.h"
#include <string>
#include <SFML/Graphics.hpp>

class Battle;

class Area : public MapComponent
{

private:
	vector<Coordinate *> areasCoordinates;
	string name;
	int index;
	int colour;
	TheatreOfWar* land=NULL;
	TheatreOfWar* air=NULL;
	TransportFactory* allFactories[3];
	Country* country=NULL;
	sf::Sprite* sprite;
	sf::Texture texture;

	/**
	 * @brief Get the cooridnate in the middle of the areas list of coordinates
	 * 
	 * @return Coordinate* 
	 */
	Coordinate* getMiddleCooridnate();
	
	/**
	 * @brief Set the correct factory texture based on the current factories
	 * 
	 */
	void setFactoryTexture();

public:
	/**
	 * @brief Construct a new Area object with the given index
	 *
	 * @name name the name of the country
	 * @param index the index of the area (used in the map's adjacency matrix)
	 * @param colour the colour of the area on the map
	 * @param factories indicates whether or not the area starts with factories
	 * @param troops indicates whether or not the area starts with troops
	 */
	Area(string name, int index, int colour, bool factories, bool troops);

	/**
	 * @brief Gets the index of the area for the adjacency matrix
	 *
	 * @return int
	 */
	int getIndex();

	/**
	 * @brief Get the Colour object
	 *
	 * @return int
	 */
	int getColour();

	/**
	 * @brief Get the areas theatre of war land pointers
	 * 
	 * @return TheatreOfWar* 
	 */
	TheatreOfWar* getLand();

	/**
	 * @brief Get the areas theatre of war air pointers
	 * 
	 * @return TheatreOfWar* 
	 */
	TheatreOfWar* getAir();
	/**
	 * @brief Not a clue right now
	 *
	 * @param type
	 * @param platoonName
	 */

	/**
	 * @brief Get the Name of the area
	 *
	 * @return string
	 */
	string getName();

	void updatePlatoons(int type, string platoonName);

	/**
	 * @brief accept visitor
	 *
	 * @param visitor takes in the pointer visitor that will be accpeted
	 */

	virtual void accept(Visitor *visitor);

	/**
	 * @brief Create a Iterator object that can loop through the area (under review)
	 *
	 * @return Iterator*
	 */
	Iterator *createIterator();

	/**
	 * @brief Called when a platoon marches into this area, determines whether or not a battle takes place and returns a Battle pointer if it does, otherwise returns NULL
	 * @details When a platoon marches into an area a few things could happen depending on the state of the area.
	 *
	 * 1) The area is unoccupied:
	 * 		The platoon claims the area for their country/alliance.
	 * 		A Transport route is set up between this area and the area the platoon came from.
	 * 		No battle occurs so NULL is returned.
	 *
	 *  2) The area is occupied by allies:
	 * 		The platoon joins with the platoon already in the area.
	 * 		No battle occurs so NULL is returned.
	 *
	 * 	3) The area is occupied by enemies:
	 * 		The platoon that "marched in" is set as the attacker whilst the troop that preexisted is the defender.
	 * 		The attacking platoon fights the defending platoon in a battle.
	 * 		A pointer to the battle object is returned for resoltion.
	 *
	 *
	 * @param platoon The platoon marching into this area.
	 * @param from The area that the unit came from
	 *
	 */
	void marchIn(Unit *unit, Area *from);

	/**
	 * @brief Orders the platoon to leave the area and go to another area
	 *
	 * @param whereTo The area to marchTo
	 *
	 * @return true if the destination area is valid
	 * @return false if the destination area is invalid
	 */
	void marchOut(Area *whereTo);

	/**
	 * @brief Used to manually set the country, colour and texture of an area to the appropriate values
	 * @param unit-unit the unit that now occupies the area
	 */
	void updateOwner(Unit* unit);

	/**
	 * @brief This function can be called by the defending platoon during a battle, to get aid from adjecent friendly areas which are connected by active transport routes
	 *
	 * @details If an adjacent area has friendly air platoons, they will join air platoon of side requesting reinforcements
	 *
	 * @param type will be attack or defense (the side requesting reinforcements)
	 * @return true if there were friendly platoons in adjecent areas which are connected by active transport routes
	 * @return false if there were no friendly platoons in adjecent areas which are connected by active transport routes
	 */
	bool requestReinforcements(string type);

	/**
	 * @brief Adds a cell to the area to be printed
	 *
	 * @param coord the coordinate of the a cell to be added in the format "x,y"
	 */
	void addCell(string coord);

	/**
	 * @brief Get the vector of Coordinates that this area takes up on the map grid
	 *
	 * @return vector<Coordinate*>
	 */
	vector<Coordinate *> getAreaCoordinates();

	/**
	 * @brief Checks if a battle would happen if it does return a Battle object to resolve else return null.
	 *
	 * A battle occurs if there is an attacker and a defender in either land, air or both
	 *
	 * @return the battle holding combatants if it occurs
	 */
	Battle *returnBattle();

	/**
	 * @brief Get the a specific type of factory if it exists here.
	 * Used when another area is requeting a factory.
	 *
	 * Types:
	 * 0) Person
	 * 1) Ammo
	 * 2) Goods
	 *
	 * @param type
	 * @return TransportFactory*
	 */
	TransportFactory *getFactory(int type);

	/**
	 * @brief requests a specific type of factory if it exists in an adjacent area.
	 *
	 * @param type the type of factory to request.
	 * @return true if an factory of the specified type exists, false otherwise
	 * @return false
	 */
	bool requestFactory(int type);

	/**
	 * @brief Returns a string representation of the area
	 *
	 * @return string
	 */
	string toString();

	/**
	 * @brief Get the Country that owns the area
	 *
	 * @return Country*
	 */
	Country *getCountry();

	/**
	 * @brief Attempts to retreat from Area
	 *
	 * @details can retreat to any adjacent area that is empty or owned by its own alliance
	 *
	 * @param type will be "attack" or "defense"
	 *
	 */
	bool retreat(string type);

	/**
	 * @brief Called when a platoon marches into this area
	 *  * 1) The area is unoccupied:
	 * 		The platoon claims the area for their country/alliance.
	 *
	 *  2) The area is occupied by allies:
	 * 		The platoon joins with the platoon already in the area.
	 *
	 * @param unit the unit retreating to the area
	 */
	void retreatInto(Unit *unit);

	/**
	 * @brief Sends reinforcements if there is an air unit of the alliance requesting reinforcements
	 *
	 * @param color color of alliance requesting reinforcements
	 * @return Unit*
	 */
	Unit *sendReinforcements(int color);

	/**
	 * @brief Replenish all units 
	 * 
	 */
	void replenish();

	/**
	 * @brief Set the Country object if the country is null
	 *
	 * @param country
	 * @return true if area did not have country set and now does
	 * @return false if area had country set
	 */
	bool setCountry(Country *country);

	/**
	 * @brief Set the Country object to the new defenders if old defenders were defeated in battle
	 * 
	 * @param country 
	 */
	void changeCountry(Country * country);
	
	/**
	 * @brief
	 *
	 */
	void setColour();

	/**
	 * @brief Sets the correct texture for each coordite in the area
	 * 
	 * @param x 
	 * @param y 
	 * @param left 
	 * @param right 
	 * @param top 
	 * @param bottom 
	 */
	void setCoordinateBorders(int x, int y, bool left,bool leftCon, bool right, bool rightCon, bool top, bool topCon, bool bottom,bool bottomCon);

	/**
	 * @brief draws the coordinates of the area on the render window
	 * 
	 * @param r 
	 */
	void draw(sf::RenderWindow* r);

	/**
	 * @brief returns true if the mouse was in the area when it was clicked, false if not
	 * 
	 * @return true 
	 * @return false 
	 */
	bool wasClicked(sf::Vector2f click);

	/**
	 * @brief Cycles the sprite animation every 100 ms
	 * 
	 * @param c a clock timeing the sprite animation
	 */
	void updateLandSpriteAnimation(sf::Clock* c);

	/**
	 * @brief Cycles the sprite animation every 100 ms
	 * 
	 * @param c a clock timeing the sprite animation
	 */
	void updateAirSpriteAnimation(sf::Clock* c);

	/**
	 * @brief Sets the location of the factory sprite to the first tile in the area
	 * 
	 */
	void updateFactorySpriteLocation();

	/**
	 * @brief Destroy the Area object
	 *
	 */
	virtual ~Area();

protected:
	/**
	 * @brief Initialises all factories
	 *
	 */
	void initialiseAllFactories();
};

#endif
