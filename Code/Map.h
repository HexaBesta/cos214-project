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
	 * @return string (probably a string represnting the transport route, not too sure though)
	 */
	string createTransportRoutes(Area *area1, Area *area2);

	/**
	 * @brief Allows the client to choose an area on the map for further action
	 *
	 * @return returns the Area chosen by the client as a pointer
	 */
	Area *chooseArea();

	/**
	 * @brief
	 *
	 * @param area1
	 * @return string
	 */
	string destroyTransportRoute(Area *area1);

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
