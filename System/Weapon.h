#ifndef WEAPON_H
#define WEAPON_H

using namespace std;

class Platoon;

class Weapon {
	private:
		int damage;
	public:
		virtual void clone() = 0;
		virtual void doDamage(Platoon* platoon) = 0;
};

#endif
