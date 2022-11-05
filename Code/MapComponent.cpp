#include "MapComponent.h"

void MapComponent::attach(Map *map)
{
	this->map = map;
}

void MapComponent::detach(Map *map)
{
	this->map = NULL;
}

MapComponent::~MapComponent()
{
}
