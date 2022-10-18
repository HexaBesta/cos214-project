#include "Area.h"

Area::Area(string name,int index,int colour) {
	this->name = name;
	this->index = index;
	this->colour=colour;
}

int Area::getIndex() {
	return this->index;
}

int Area::getColour() {
	return this->colour;
}

string Area::getName(){
	return this->name;
}

void Area::updatePlatoons(int type, string platoonName)
{
	// TODO - implement Area::updatePlatoons
	throw "Not yet implemented";
}

Iterator *Area::createIterator()
{
	// TODO - implement Area::createIterator
	throw "Not yet implemented";
}

Battle *Area::marchIn(Platoon *platoon)
{
	// TODO - implement Area::marchIn
	throw "Not yet implemented";
}

bool Area::marchOut()
{
	// TODO - implement Area::marchOut
	throw "Not yet implemented";
}

bool Area::requestReinforcements()
{
	// TODO - implement Area::requestReinforcements
	throw "Not yet implemented";
}

void Area::addCell(string coord)
{
	string xStr = "";
	string yStr = "";
	int pos = 0;
	while (coord.at(pos) != ',')
	{
		xStr += coord.at(pos);
		pos++;
	}
	pos++;
	while (pos < coord.length())
	{
		yStr += coord.at(pos);
		pos++;
	}

	this->areasCoordinates.push_back(new Coordinate(stoi(xStr), stoi(yStr)));
}

vector<Coordinate*> Area::getAreaCoordinates(){
	return this->areasCoordinates;
}

Area::~Area(){
	while(!areasCoordinates.empty()) {
        delete areasCoordinates.back();
        areasCoordinates.pop_back();
    }
}

