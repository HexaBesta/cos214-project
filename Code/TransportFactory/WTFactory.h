#ifndef WTFACTORY_H
#define WTFACTORY_H

#include "TransportFactory.h"

using namespace std;

class WTFactory : public TransportFactory {
    public:
    virtual Transport *makeTypeTransport();
};


#endif
