#include "PTFactory.h"

Transport* PTFactory::makeTypeTransport()
{
    return new People();
}

TransportFactory* PTFactory::clone()
{
    return new PTFactory();
}
