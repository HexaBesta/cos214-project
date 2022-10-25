#ifndef BOBTHEBUILDER_H
#define BOBTHEBUILDER_H

#include "../Unit/Unit.h"

using namespace std;

class BobTheBuilder {
	public:
		BobTheBuilder();
		virtual Unit* buildPart() = 0;
		virtual Unit* getResult() = 0;
};

#endif
