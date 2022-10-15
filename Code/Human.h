#ifndef HUMAN_H
#define HUMAN_H
#include "Unit.h"
using namespace std;

class Human : public Unit
{
	void attack(Platoon* other);
    
};

#endif
