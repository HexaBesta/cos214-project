#include "ATFactory.h"
Transport* ATFactory::makeTypeTransport()
{
    return new Ammunition();
}

TransportFactory* ATFactory::clone()
{
    return new ATFactory();
}
