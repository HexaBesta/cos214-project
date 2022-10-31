#include "GTFactory.h"


Transport* GTFactory::makeTypeTransport()
{
    return new Goods();
}

TransportFactory* GTFactory::clone()
{
    return new GTFactory();
}
