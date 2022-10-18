#include "../Map/Map.h"
using namespace std;

void testEuropeMap()
{
    Map *m = new Map("../Maps/europe.txt");
    
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (i!=j)
            {
                m->createTransportRoute(m->getAreaByIndex(i), m->getAreaByIndex(j));
            }
            
            
        }
    }

    m->printMap();

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (i!=j)
            {
                m->destroyTransportRoute(m->getAreaByIndex(i), m->getAreaByIndex(j));
            }
            
            
        }
    }

    m->printColourMap();

    for (size_t i = 0; i < 32; i++)
    {
        m->listAdjacent(m->getAreaByIndex(i),false);
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
        m->listAdjacent(m->getAreaByIndex(i),false);
    }

    delete m;
}

int main()
{
    testMap1();
    cout << endl
         << endl;
    testEuropeMap();
}
