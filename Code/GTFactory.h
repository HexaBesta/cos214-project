#ifndef GTFACTORY_H
#define GTFACTORY_H

#include "TransportFactory.h"
#include "Goods.h"
using namespace std;

class GTFactory : public TransportFactory
{
    public:
    virtual Transport *makeTypeTransport();
    virtual TransportFactory* clone();
};

#endif
