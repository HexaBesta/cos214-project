#ifndef EXPLOSIVE_H
#define EXPLOSIVE_H
#include "Weapon.h"
using namespace std;

	class Explosive : public Weapon {


	public:
		virtual void clone() = 0;
	};


#endif
