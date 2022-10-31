#ifndef HUMAN_H
#define HUMAN_H
#include "Unit.h"
using namespace std;

class Human : public Unit {
	public:
		Human(int health, int moral, int damage, Country* country, bool fitState);
		virtual void attack(Unit* other);
		virtual string toString();
		virtual ~Human();
};

#endif
