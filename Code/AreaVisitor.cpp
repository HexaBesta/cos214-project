#include "AreaVisitor.h"

void AreaVisitor::visit(Area* area){
    area->replenish();
    if(area->getColour()!=94){
        cout<<area->getName()<<" replenished troops"<<endl;
    }
};

void AreaVisitor::visit(TransportRoute* transport){
    Area* area1 = transport->getFrom();
    cout<<"Transport route endpoints: "<<area1->getIndex()<<"\nTransport route colour: "<<area1->getColour()<<endl;
};