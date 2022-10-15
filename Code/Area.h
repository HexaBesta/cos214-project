#ifndef AREA_H
#define AREA_H
#include "MapComponent.h"
#include "Platoon.h"
#include "Iterator.h"
#include "Coordinate.h"
#include <string>
class Battle;

class Area : public MapComponent
{
	

private:
	Platoon *defender;
	vector<Coordinate*> areasCoordinates;
	Platoon *attacker;
	string name;
	int index;
	int colour;

public:
	/**
	 * @brief Construct a new Area object with the given index
	 *
	 * @param index the index of the area (used in the map's adjacency matrix)
	 */
	Area(string name,int index,int colour);

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
	 * @brief Not a clue right now
	 *
	 * @param type
	 * @param platoonName
	 */
	void updatePlatoons(int type, string platoonName);

	/**
	 * @brief Create a Iterator object that can loop through the area (under review)
	 *
	 * @return Iterator*
	 */
	Iterator *createIterator();

	/**
	 * @brief Called when a platoon marches into this area, determines whether or not a battle takes place and returns a Battle pointer if it does, otherwise returns NULL
	 * @details When a platoon marches into an area a few things could happen depending on the state of the area.
	 * 	1) The area is unoccupied:
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
	 * @return returns a Battle pointer if a battle occurs when the platoon enters the area, returns NULL if not.
	 */
	Battle *marchIn(Platoon *platoon);

	/**
	 * @brief Orders the platoon to leave the area and go to another area
	 *
	 * @return true if the destination area is valid
	 * @return false if the destination area is invalid
	 */
	bool marchOut();

	/**
	 * @brief This function can be called by the defending platoon during a battle, to get aid from adjecent friendly areas which are connected by active transport routes
	 *
	 * @return true if there were friendly platoons in adjecent areas which are connected by active transport routes
	 * @return false if there were no friendly platoons in adjecent areas which are connected by active transport routes
	 */
	bool requestReinforcements();

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
	vector<Coordinate*> getAreaCoordinates();

	/**
	 * @brief Destroy the Area object
	 * 
	 */
	~Area();

};

#endif