#include "../Map/Map.h"
#include "../Map/Area.h"
using namespace std;

void testEuropeMap()
{
    Map *m = new Map("../Maps/europe.txt");

    m->printMap();
    cout << (m->getAreaByIndex(6)->toString()) << endl;
    cout << (m->getAreaByIndex(7)->toString()) << endl;
    
    cout <<"Status of factory request: "<< m->getAreaByIndex(7)->requestFactory(1) << endl;
    cout << (m->getAreaByIndex(7)->toString()) << endl;
    
    m->createTransportRoute(m->getAreaByIndex(6),m->getAreaByIndex(7));
    
    cout <<"Status of factory request: "<< m->getAreaByIndex(7)->requestFactory(0) << endl;
    cout << (m->getAreaByIndex(7)->toString()) << endl;

    m->createTransportRoute(m->getAreaByIndex(6),m->getAreaByIndex(8));
    cout <<"Status of factory request: "<< m->getAreaByIndex(8)->requestFactory(1) << endl;
    cout << (m->getAreaByIndex(8)->toString()) << endl;

    cout << (m->getAreaByIndex(4)->toString()) << endl;

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    m->getAreaByIndex(4)->marchOut(m->getAreaByIndex(5));

    cout << (m->getAreaByIndex(4)->toString()) << endl;

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    

    m->printMap();
    cout << (m->getAreaByIndex(5)->toString()) << endl;
    cout <<"Status of factory request: "<< m->getAreaByIndex(5)->requestFactory(2) << endl;
    cout << (m->getAreaByIndex(5)->toString()) << endl;
    m->printMap();

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    cout << (m->getAreaByIndex(8)->toString()) << endl;

    m->getAreaByIndex(5)->marchOut(m->getAreaByIndex(8));

    cout << (m->getAreaByIndex(5)->toString()) << endl;

    cout << (m->getAreaByIndex(8)->toString()) << endl;

    m->printMap();

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(10)->toString()) << endl;

    m->getAreaByIndex(6)->marchOut(m->getAreaByIndex(10));

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(10)->toString()) << endl;

    m->printMap();

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(7)->toString()) << endl;

    m->getAreaByIndex(6)->marchOut(m->getAreaByIndex(7));

    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(7)->toString()) << endl;

    m->printMap();

    //Added test - Inge (Retreat)

    m->getAreaByIndex(7)->retreat("defense");
    cout << (m->getAreaByIndex(6)->toString()) << endl;

    cout << (m->getAreaByIndex(7)->toString()) << endl;
    m->printMap();

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
        m->listAdjacent(m->getAreaByIndex(i), false);
    }

    delete m;
}

int main()
{
    // testMap1();
    cout << endl
         << endl;
    testEuropeMap();
}
