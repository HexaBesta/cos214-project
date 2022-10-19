#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

class Map;
class Visitor;

using namespace std;

class MapComponent
{

private:
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
	 * @brief Mark, please help😄
	 * 
	 * @param visitor 
	 */
	void accept(Visitor *visitor);

};


#endif
