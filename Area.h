#ifndef AREA_H
#define AREA_H

namespace Main {
	class Area : Main::MapComponent {

	private:
		Main::Platoon* defender;
		double xco;
		double yco;
		Main::Platoon* attacker;

	public:
		void updatePlatoons(int type, string platoonName);

		Main::Iterator* createIterator();

		Main::Battle* marchIn(Main::Platoon* platoon);

		bool marchOut();

		bool requestReinforcements();
	};
}

#endif
