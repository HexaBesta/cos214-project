#ifndef MELEEWEAPONFACTORY_H
#define MELEEWEAPONFACTORY_H

namespace WeaponFactory {
	class MeleeWeaponFactory : WeaponFactory::WeaponFactory {


	public:
		virtual void createWeapon() = 0;
	};
}

#endif
