#ifndef WEAPON_H
#define WEAPON_H

namespace Main {
	class Weapon {

	private:
		int damage;

	public:
		virtual void clone() = 0;

		virtual void doDamage(Main::Platoon* platoon) = 0;
	};
}

#endif
