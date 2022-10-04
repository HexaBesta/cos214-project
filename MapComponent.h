#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include "Map.h"
class Visitor;

using namespace std;

class MapComponent
{

private:
	Map *map;

public:
	void attach(Map *map);

	void detach(Map *map);

	void accept(Visitor *visitor);

	void attach(Map *map);

	void detach(Map *map);
};


#endif
