#include "ATFactory.h"
Transport *ATFactory::makeTypeTransport()
{
    return new Ammunition(20);
}

TransportFactory *ATFactory::clone()
{
    return new ATFactory();
}
