#ifndef MAP_H
#define MAP_H

namespace Main {
	class Map {


	public:
		string createTransportRoutes(Main::Area* area1, Main::Area* area2);

		Main::Area* chooseArea();

		string destroyTransportRoute(Main::Area* area1);

		vector<Main::Area*> listAdjacent(Main::Area* area);

		void update();
	};
}

#endif
