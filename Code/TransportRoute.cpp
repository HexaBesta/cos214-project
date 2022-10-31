#include "TransportRoute.h"

TransportRoute::TransportRoute():MapComponent():MapComponent(){
    this->available=false;
}

bool TransportRoute::isAvailable(){
    return this->available;
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

Area* TransportRoute::getFrom(){
    return this->from;
}

Area* TransportRoute::getTo(){
    return this->to;
}

void TransportRoute::accept(Visitor* visitor){
	visitor->visit(this);
}

TransportRoute::~TransportRoute(){

}