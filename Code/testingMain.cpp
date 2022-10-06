#include "Map.h"
using namespace std;

void testEuropeMap()
{
    Map *m = new Map("../Maps/europe.txt");
    m->createTransportRoute(m->getAreaByIndex(1), m->getAreaByIndex(2));
    m->createTransportRoute(m->getAreaByIndex(14), m->getAreaByIndex(9));
    m->createTransportRoute(m->getAreaByIndex(14), m->getAreaByIndex(12));
    m->createTransportRoute(m->getAreaByIndex(6), m->getAreaByIndex(4));
    m->createTransportRoute(m->getAreaByIndex(23), m->getAreaByIndex(25));
    m->printMap();

    m->destroyTransportRoute(m->getAreaByIndex(1), m->getAreaByIndex(2));
    m->destroyTransportRoute(m->getAreaByIndex(14), m->getAreaByIndex(9));
    m->destroyTransportRoute(m->getAreaByIndex(14), m->getAreaByIndex(12));
    m->destroyTransportRoute(m->getAreaByIndex(6), m->getAreaByIndex(4));
    m->destroyTransportRoute(m->getAreaByIndex(23), m->getAreaByIndex(25));

    m->printMap();

    for (size_t i = 0; i < 31; i++)
    {
        m->listAdjacent(m->getAreaByIndex(i));
    }

    delete m;
}

void testMap1()
{
    Map *m = new Map("../Maps/map1.txt");
     m->createTransportRoute(m->getAreaByIndex(1), m->getAreaByIndex(2));
     m->createTransportRoute(m->getAreaByIndex(0), m->getAreaByIndex(2));
     m->createTransportRoute(m->getAreaByIndex(1), m->getAreaByIndex(3));
     m->createTransportRoute(m->getAreaByIndex(5), m->getAreaByIndex(3));
    m->printMap();

    for (size_t i = 0; i < 6; i++)
    {
        m->listAdjacent(m->getAreaByIndex(i));
    }

    delete m;
}

int main()
{
    testMap1();
    cout<<endl<<endl;
    testEuropeMap();
}
