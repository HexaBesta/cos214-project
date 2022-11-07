#include "GTFactory.h"

Transport *GTFactory::makeTypeTransport()
{
    return new Goods(20);
}

TransportFactory *GTFactory::clone()
{
    return new GTFactory();
}
