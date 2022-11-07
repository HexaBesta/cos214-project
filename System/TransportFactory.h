#ifndef TRANSPORTFACTORY_H
#define TRANSPORTFACTORY_H

using namespace std;
#include "Transport.h"

class TransportFactory
{

private:
	Transport *transport;

public:
	virtual Transport *makeTypeTransport() = 0;
	virtual TransportFactory* clone()=0;
	
};

#endif
