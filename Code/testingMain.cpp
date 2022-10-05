#include "Map.h"

void testMap(){
 Map* m=new Map("../Maps/map1.txt");
 delete m;
}

int main(){
    testMap();
}

