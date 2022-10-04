#ifndef UNIT_H
#define UNIT_H

namespace Main {
	class Unit {

	private:
		Main::UnitsState unitState;
		int health;

	public:
		virtual void attack(Main::Platoon* other) = 0;

		void request();

		void setUnitState(Main::UnitsState unitState);

		int takeDamage(int damage);
	};
}

#endif
