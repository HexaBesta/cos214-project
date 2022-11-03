#include "CleanUpVisitor.h"

void CleanUpVisitor::visit(Area* area){
    if(area->getAir()->getAttacker() != NULL && area->getAir()->getAttacker()->getState().compare("Dead")==0){
        cout<<"RIP BOZOS At Area: "<<area->getName()<<" ("<<area->getIndex()<<endl;
        area->getAir()->setAttacker(nullptr);
    }
    if(area->getLand()->getAttacker() != NULL && area->getLand()->getAttacker()->getState().compare("Dead")==0){
        cout<<"RIP BOZOS At Area: "<<area->getName()<<" ("<<area->getIndex()<<endl;
        area->getLand()->setAttacker(nullptr);
    }
    if(area->getAir()->getDefender() != NULL && area->getAir()->getDefender()->getState().compare("Dead")==0){
        cout<<"RIP BOZOS At Area: "<<area->getName()<<" ("<<area->getIndex()<<endl;
        area->getAir()->setDefender(nullptr);
        if(area->getAir()->getAttacker()!=nullptr && area->getAir()->getAttacker()->getState().compare("Dead")!=0 ){
            if(area->getLand()->getDefender()==nullptr && area->getLand()->getDefender()->getState().compare("Dead")==0){
                area->getAir()->setDefender(area->getAir()->getAttacker());
                area->getAir()->setAttacker(nullptr);
                area->setCountry(area->getAir()->getDefender()->getCountry());
            }
        }
    }
    if(area->getLand()->getDefender() != NULL && area->getLand()->getDefender()->getState().compare("Dead")==0){
        cout<<"RIP BOZOS At Area: "<<area->getName()<<" ("<<area->getIndex()<<endl;
        area->getLand()->setDefender(nullptr);
        if(area->getLand()->getAttacker()!=nullptr && area->getLand()->getAttacker()->getState().compare("Dead")!=0 ){
            if(area->getAir()->getDefender()==nullptr && area->getAir()->getDefender()->getState().compare("Dead")==0){
                area->getLand()->setDefender(area->getLand()->getAttacker());
                area->getLand()->setAttacker(nullptr);
                area->setCountry(area->getLand()->getDefender()->getCountry());
            }
        }
    }
}

void CleanUpVisitor::visit(TransportRoute* transportR){
    return;
}