#include "ATFactory.h"
Transport *ATFactory::makeTypeTransport()
{
    return new Ammunition(250);
}

TransportFactory *ATFactory::clone()
{
    return new ATFactory();
}
