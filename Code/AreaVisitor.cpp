#include "AreaVisitor.h"

void AreaVisitor::visit(Area* area){
    cout<<"Area index: "<<area->getIndex()<<"\nArea Colour: "<<area->getColour()<<endl;
};

void AreaVisitor::visit(TransportRoute* transport){
    Area* area1 = transport->getFrom();
    cout<<"Transport route endpoints: "<<area1->getIndex()<<"\nTransport route colour: "<<area1->getColour()<<endl;
};