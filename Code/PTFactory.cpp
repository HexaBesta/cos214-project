#include "PTFactory.h"

Transport *PTFactory::makeTypeTransport()
{
    return new People(20);
}

TransportFactory *PTFactory::clone()
{
    return new PTFactory();
}
