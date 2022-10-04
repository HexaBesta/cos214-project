#ifndef TRANSPORTROUTE_H
#define TRANSPORTROUTE_H

#include "Area.h"

using namespace std;

class TransportRoute : public MapComponent
{

private:
	Area *to;
	Area *from;
	bool available;
};

#endif
