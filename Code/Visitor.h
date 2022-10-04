#ifndef VISITOR_H
#define VISITOR_H

#include "Area.h"
#include "TransportRoute.h"

using namespace std;

class Visitor
{

public:
	virtual void visitArea(Area *area) = 0;

	virtual void visitTransportRoute(TransportRoute *transportRoute) = 0;
};

#endif
