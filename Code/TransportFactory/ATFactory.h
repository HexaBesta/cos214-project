#ifndef ATFACTORY_H
#define ATFACTORY_H

#include "TransportFactory.h"
#include "Ammunition.h"

using namespace std;

class ATFactory : public TransportFactory {
    public:
    virtual Transport *makeTypeTransport();
    virtual TransportFactory* clone();
};


#endif
