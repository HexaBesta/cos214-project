#ifndef PTFACTORY_H
#define PTFACTORY_H

#include "TransportFactory.h"

using namespace std;

class PTFactory : public TransportFactory
{
    public:
        virtual Transport *makeTypeTransport(){return NULL;};
};

#endif
