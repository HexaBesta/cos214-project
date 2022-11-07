#ifndef PTFACTORY_H
#define PTFACTORY_H

#include "TransportFactory.h"
#include "People.h"

using namespace std;

class PTFactory : public TransportFactory
{
    public:
        virtual Transport *makeTypeTransport();
        virtual TransportFactory* clone();
};

#endif
