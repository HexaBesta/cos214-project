#ifndef AREA_H
#define AREA_H

namespace Main {
	class Area : Main::MapNode {

	public:
		vector<Main::Platoon*> platoons;

		void updatePlatoons(int type, string platoonName);

		Main::Iterator* createIterator();
	};
}

#endif
