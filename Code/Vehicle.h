#ifndef VEHICLE_H
#define VEHICLE_H

#include "Unit.h"

using namespace std;

class Vehicle : public Unit {
    public:
		Vehicle(int health, int moral, int damage, Country* country, bool fitState);
		virtual void attack(Unit* other);
		virtual string toString();
		virtual ~Vehicle();
};

#endif
