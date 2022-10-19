#include "MapComponent.h"

void  MapComponent::attach(Map *  map) {
	this->map=map;
}

void  MapComponent::detach(Map *  map) {
	this->map=NULL;
}

void  MapComponent::accept( Visitor* visitor) {
	// TODO - implement MapComponent::accept
	throw "Not yet implemented";
}

