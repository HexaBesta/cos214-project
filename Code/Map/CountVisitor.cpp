#include "CountVisitor.h"

void CountVisitor::visit(Area *area)
{
    if (area->getColour() == 1)
    {
        alliance1Count++;
    }
    else if (area->getColour() == 2)
    {
        alliance2Count++;
    }
};

void CountVisitor::visit(TransportRoute *transport)
{
    if (transport->isAvailable())
    {
        if (transport->getTo()->getColour() == 22)
        {
            alliance1CountTransport++;
        }
        else if (transport->getTo()->getColour() == 160)
        {
            alliance2CountTransport++;
        }
    }
};