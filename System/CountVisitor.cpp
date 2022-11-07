#include "CountVisitor.h"
#include "Area.h"
#include "TransportRoute.h"

void CountVisitor::visit(Area *area)
{
    if (area->getColour() == 22)
    {
        alliance1Count++;
    }
    else if (area->getColour() == 160)
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

string CountVisitor::displayCount()
{
    string display = "Alliance 1:\n";
    display += " Areas: ";
    display += alliance1Count;
    display += " Transports: ";
    display += alliance1CountTransport;
    display += "Alliance 2:\n";
    display += " Areas: ";
    display += alliance2Count;
    display += " Transports: ";
    display += alliance2CountTransport;
    return display;
}

int CountVisitor::warLoopComplete()
{
    if (this->alliance1Count == 0)
    {
        return 160;
    }
    else if (this->alliance2Count == 0)
    {
        return 22;
    }
    else
    {
        return 94;
    }
}