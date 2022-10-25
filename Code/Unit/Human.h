#ifndef HUMAN_H
#define HUMAN_H
#include "Unit.h"
using namespace std;

class Human : public Unit
{
	virtual void attack(Unit* other);
    virtual void print();
	virtual ~Human();
};

#endif
