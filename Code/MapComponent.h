#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include "Map.h"
class Visitor;

using namespace std;

class MapComponent
{

protected:
	Map *map;

public:

	/**
	 * @brief attaches/sets the map as an observer to this MapComponent
	 * 
	 * @param map the map object that will observe this MapComponent
	 */
	void attach(Map *map);

	/**
	 * @brief detaches/unsets the map as an observer to this MapComponent
	 * 
	 * @param map the map object that will be detached from this MapComponent
	 */
	void detach(Map *map);

	/**
	 * @brief The virtual function to accept the visitor
	 * 
	 * @param visitor to accept the visitor that wants to see the areas and transport routes
	 */
	virtual void accept(Visitor *visitor)=0;

	/**
	 * @brief Destroy the Map Component object
	 * 
	 */
	virtual ~MapComponent();

};


#endif
