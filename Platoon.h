#ifndef PLATOON_H
#define PLATOON_H

namespace Main {
	class Platoon : Main::Unit {

	private:
		Main::BobTheBuilder* bob;
		vector<Main::Unit*> humans;
		vector<Main::Unit*> vehicles;
		vector<Main::Weapon*> weapons;

	public:
		void construct();
	};
}

#endif
