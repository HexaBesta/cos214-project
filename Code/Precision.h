#ifndef PRECISION_H
#define PRECISION_H

#include "Weapon.h"

using namespace std;

class Precision : public Weapon
{

public:
	virtual void clone() = 0;
};

#endif
