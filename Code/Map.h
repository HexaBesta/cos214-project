#ifndef MAP_H
#define MAP_H
#include "Area.h"
#include <vector>
using namespace std;

class Map
{

public:
	string createTransportRoutes(Area *area1, Area *area2);

	Area *chooseArea();

	string destroyTransportRoute(Area *area1);

	vector<Area *> listAdjacent(Area *area);

	void update();
};

#endif
