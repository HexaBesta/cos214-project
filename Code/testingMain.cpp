#include "Map.h"

void testMap(){
 Map* m=new Map("../Maps/europe.txt");
 m->createTransportRoute(m->getAreaByIndex(1),m->getAreaByIndex(2));
 m->createTransportRoute(m->getAreaByIndex(14),m->getAreaByIndex(9));
 m->createTransportRoute(m->getAreaByIndex(14),m->getAreaByIndex(12));
 m->createTransportRoute(m->getAreaByIndex(6),m->getAreaByIndex(4));
m->createTransportRoute(m->getAreaByIndex(23),m->getAreaByIndex(25));
 m->printMap();
 for (size_t i = 0; i < 31; i++)
 {
     m->listAdjacent(m->getAreaByIndex(i));
 }
 

 delete m;
}

int main(){
    testMap();
}

