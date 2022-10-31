#ifndef MILITARY_H
#define MILITARY_H

#include "Platoon.h"

using namespace std;

class Military {
	private:
		Platoon* platoon=NULL;
	public:
		void constructPlatoon();
};

#endif
