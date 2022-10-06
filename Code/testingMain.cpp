#include "Map.h"

void testMap(){
 Map* m=new Map("../Maps/europe.txt");
 m->printMap();
 delete m;
}

int main(){
    testMap();
}

