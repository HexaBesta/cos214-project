#ifndef MILITARY_H
#define MILITARY_H

#include "Platoon.h"

using namespace std;

class Military {
	private:
		Platoon* platoon;
	public:
		void constructPlatoon();
};

#endif
