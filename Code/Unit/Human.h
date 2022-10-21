#ifndef HUMAN_H
#define HUMAN_H
#include "Unit.h"
#include "../Platoon/Platoon.h"
using namespace std;

class Human : public Unit
{
	virtual void attack(Platoon* other);
    virtual void print();
	virtual ~Human();
};

#endif
