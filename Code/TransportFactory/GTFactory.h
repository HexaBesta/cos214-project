#ifndef GTFACTORY_H
#define GTFACTORY_H

#include "TransportFactory.h"
using namespace std;

class GTFactory : public TransportFactory
{
    public:
    virtual Transport *makeTypeTransport();
};

#endif
