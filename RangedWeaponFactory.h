#ifndef RANGEDWEAPONFACTORY_H
#define RANGEDWEAPONFACTORY_H

namespace WeaponFactory {
	class RangedWeaponFactory : WeaponFactory::WeaponFactory {


	public:
		virtual void createWeapon() = 0;
	};
}

#endif
