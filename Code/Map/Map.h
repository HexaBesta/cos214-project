#ifndef MAP_H
#define MAP_H

#include "../TransportFactory/TransportFactory.h"
#include "../Country/Country.h"
#include "../Battle/Battle.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Player;
class Area;
class TransportRoute;
class Map
{

public:
	/**
	 * @brief Construct a new Map object given a text file with the areas and setup
	 *
	 * @param setupFile the name of the text files that contains the map layout
	 * @param player the player object to start game with
	 */
	Map(string setupFile, Player * player = NULL);

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
	vector<Area *> listAdjacent(Area *area,bool transportRoute);

	/**
	 * @brief Tests whether the given areas are adjacent to each other
	 * 
	 * @param to 
	 * @param from 
	 * @return true they are adjacent to each other
	 * @return false they are not adjacent to each other
	 */
	bool areAdjacent(Area *to,Area* from);

	/**
	 * @brief Get the Area By its index member variable
	 * 
	 * @param area the area to search for adjacencies
	 * @param transportRoute whether or not transportRoutes must be active to be considered adjacent
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
	 * @brief Given an area, return a factory of the requested type if it is available in any adjacent area of the same allinace, otherwise return null
	 * 
	 * @return Factory* return a factory of the requested type if it is available in any adjacent area of the same allinace, otherwise return null
	 */
	TransportFactory* requestFactoryForArea(Area* area,int type);

	/**
	 * 
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
	 * @brief Adds a country to the map
	 * 
	 * @param country the country to be added
	 */
	void addCountry(Country* country);

	/**
	 * @brief Get the Countries of the alliance (found by colour)
	 * 
	 * @param colour Alliance colour 
	 * @return vector<Country*> vector of countries of the alliance 
	 */
	vector<Country*> getCountriesByColour(int colour);

	/**
	 * @brief Get the Areas By Country object
	 * 
	 * @param country to list areas of
	 * @return vector<Area*> all areas occupied by the passed in country
	 */
	vector<Area*> getAreasByCountry(Country * country);

	/**
	 * @brief Set the Player object
	 * 
	 * @param player 
	 */
	void setPlayer(Player * player);

	/**
	 * @brief Get the Player object
	 * 
	 * @return Player* the current player
	 */
	Player * getPlayer();

	/**
	 * @brief Resolves all battles after each round
	 * 
	 */
	void resolveBattles();

	/**
	 * @brief Destroy the Map object for memory purposes
	 * 
	 */
	~Map();

private:
	vector<Area *> allAreas;
	TransportRoute ***adjacencies;
	string **grid;
	vector<Country*> allCountries;
	int gridXSize;
	int gridYSize;
	Player * player;

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
