#ifndef MAP_H
#define MAP_H
#include "Area.h"
#include "TransportRoute.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Map
{

public:
	/**
	 * @brief Construct a new Map object given a text file with the areas and setup
	 *
	 * @param setupFile the name of the text files that contains the map layout
	 */
	Map(string setupFile);

	/**
	 * @brief Create a Transport Route between the two given areas of the map
	 *
	 * @note Transport routes should be created automatically when troops take over a new area.
	 * The route should be made between the area they left and the area the took over
	 *
	 *
	 * @param area1 The first end point of the transport route
	 * @param area2 The second end point of the transport route
	 *
	 * @note Since the map is a bidirectional graph the order of area1 and area2 does not matter
	 */
	void createTransportRoute(Area *area1, Area *area2);

	/**
	 * @brief Allows the client to choose an area on the map for further action
	 *
	 * @return returns the Area chosen by the client as a pointer
	 */
	Area *chooseArea();

	/**
	 * @brief Create a Transport Route between the two given areas of the map
	 *
	 * @note Transport routes should be destryoed automatically when troops take over a new area.
	 * The route should be destroyed between the this areas and the area that belongs to enemies
	 *
	 *
	 * @param area1 The first end point of the transport route
	 * @param area2 The second end point of the transport route
	 *
	 * @note Since the map is a bidirectional graph the order of area1 and area2 does not matter
	 */
	void destroyTransportRoute(Area *area1, Area *area2);

	/**
	 * @brief Lists the areas adjacent to the given area
	 *
	 * @note Areas are adjacent when connected by a transport route (this transport route could be active or inactive/destroyed)
	 *
	 * @param area the area being queried for adjacencies
	 * @return returns a vector of area pointers, all areas in the vector are necessarily adjacent to the input area.
	 */
	vector<Area *> listAdjacent(Area *area);

	/**
	 * @brief Get the Area By its index member variable
	 * 
	 * @param index the index of the area as seen on the map
	 * @return returns the area if it is found, returns NULL if not
	 */
	Area* getAreaByIndex(int index);

	/**
	 * @brief returns whether or not there is an available transport route between two areas
	 * 
	 * @param point1 
	 * @param point2 
	 * @return true if there is an available transport route
	 * @return false if there is no transport route or if the transport route is unavialable
	 */
	bool transportRouteisAvailable(Area* point1,Area* point2);

	/**
	 * @brief The update method realting to the observer pattern, will be called when areas or transport routes 'notify' the map of change
	 * (not sure what exactly it does yet)
	 *
	 */
	void update();

	/**
	 * @brief prints out a grid based reprsentation of the map
	 * 
	 */
	void printMap();

	/**
	 * @brief Print the map with areas coloured differntly
	 * 
	 */
	void printColourMap();

	/**
	 * @brief Destroy the Map object for memory purposes
	 * 
	 */
	~Map();

private:
	vector<Area *> allAreas;
	TransportRoute ***adjacencies;
	string **grid;
	int gridXSize;
	int gridYSize;

	/**
	 * @brief Set the All End Points of transport routes in the adjacency matrix
	 *
	 */
	void setAllEndPoints();

	/**
	 * @brief Loops through the allAreas vector and "paints" the grid 2D array based on the coordinates belonging to that area
	 *
	 */
	void setAllGridAreas();

	
};

#endif
