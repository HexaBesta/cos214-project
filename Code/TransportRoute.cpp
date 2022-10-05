#include "TransportRoute.h"

TransportRoute::TransportRoute(){
    this->available=false;
}

void TransportRoute::setEndPoints(Area* endPoint1,Area* endPoint2){
    this->from=endPoint1;
    this->to=endPoint2;
}

void TransportRoute::destroy(){
    this->available=false;
}

void TransportRoute::create(){
    this->available=true;
}