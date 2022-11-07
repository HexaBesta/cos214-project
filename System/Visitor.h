#ifndef VISITOR_H
#define VISITOR_H
#include <string>
#include <iostream>
class Area;
class TransportRoute;

using namespace std;

class Visitor {

public:
	virtual void visit(Area *area) = 0;
	virtual void visit(TransportRoute *transportRoute) = 0;
};

#endif
