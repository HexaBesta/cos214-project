
#include "Area.h"
Area::Area(string name, int index, int colour,bool factories)
{
	this->name = name;
	this->index = index;
	this->colour = colour;
	this->land=new TheatreOfWar("Land");
	this->air=new TheatreOfWar("Air");
	if (factories)
	{
		allFactories[0]=new PTFactory();
		allFactories[1]=new ATFactory();
		allFactories[2]=new GTFactory();
	}else{
		allFactories[0]=NULL;
		allFactories[1]=NULL;
		allFactories[2]=NULL;
	}
	
}

int Area::getIndex()
{
	return this->index;
}

int Area::getColour()
{
	return this->colour;
}

string Area::getName()
{
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

void Area::marchIn(Unit *unit)
{
	if (unit->getBranch() == "LAND BRANCH")
	{
		if (land->getDefender() == NULL)
		{
			if (air->getDefender() == NULL)
			{
				land->setDefender(unit);
			}
			else if (air->getDefender()->getAlliance() == unit->getAlliance())
			{
				land->setDefender(unit);
			}
			else if (air->getDefender()->getAlliance() != unit->getAlliance())
			{
				land->setAttacker(unit);
			}
		}
		else if (land->getDefender()->getAlliance() == unit->getAlliance())
		{
			land->setDefender(unit);
		}
		else if (land->getDefender()->getAlliance() != unit->getAlliance())
		{
			land->setAttacker(unit);
		}
	}
	else if (unit->getBranch() == "AIR BRANCH")
	{
		if (air->getDefender() == NULL)
		{
			if (land->getDefender() == NULL)
			{
				air->setDefender(unit);
			}
			else if (land->getDefender()->getAlliance() == unit->getAlliance())
			{
				air->setDefender(unit);
			}
			else if (land->getDefender()->getAlliance() != unit->getAlliance())
			{
				air->setAttacker(unit);
			}
		}
		else if (air->getDefender()->getAlliance() == unit->getAlliance())
		{
			air->setDefender(unit);
		}
		else if (air->getDefender()->getAlliance() != unit->getAlliance())
		{
			air->setAttacker(unit);
		}
	}
	
	
	
}

void Area::marchOut(Area* whereTo)
{
	if (land->getDefender()!=NULL)
	{
		whereTo->marchIn(land->MarchOut(false));
	}
	if (air->getDefender()!=NULL)
	{
		whereTo->marchIn(air->MarchOut(false));
	}	
	
}

bool Area::requestReinforcements()
{
	// TODO - implement Area::requestReinforcements
	throw "Not yet implemented";
}

bool Area::requestResources(int type){
	return false;
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

vector<Coordinate *> Area::getAreaCoordinates()
{
	return this->areasCoordinates;
}

Battle* Area::returnBattle(){

bool isBattle=false;

	if (land->getDefender()!=NULL && land->getAttacker()!=NULL)
	{
		isBattle = true;
	}

	if (air->getDefender()!=NULL && air->getAttacker()!=NULL)
	{
		isBattle = true;
	}

	if (land->getDefender()!=NULL && air->getAttacker()!=NULL)
	{
		isBattle = true;
	}

	if (air->getDefender()!=NULL && land->getAttacker()!=NULL)
	{
		isBattle = true;
	}
	
	if (isBattle)
	{
		//return new Battle(air,land,this);
	}
	return NULL;

}

TransportFactory* Area::getFactory(int type){

	if(allFactories[type]==NULL){
		return NULL;
	}else{
		return allFactories[type]->clone();
	}
}

bool Area::requestFactory(int type){
	TransportFactory* foundFactory =map->requestFactoryForArea(this,type);
	if(foundFactory==NULL){
		return false;
	}else{
		allFactories[type]=foundFactory;
		return true;
	}
}

string Area::toString(){
		string out= "Name: " + name +"\tID: " + to_string(index) +"\tColour: " + to_string(colour);
		out+="\n \tFactories: Person["+to_string(allFactories[0]!=NULL)+"]\t Ammo["+to_string(allFactories[1]!=NULL)+"]\t Goods["+to_string(allFactories[2]!=NULL)+"]";
		out+="\n\tLand:\n\t"+land->toString();
		out+="\n\tAir:\n\t"+air->toString();
		return out;
	}

Area::~Area()
{
	while (!areasCoordinates.empty())
	{
		delete areasCoordinates.back();
		areasCoordinates.pop_back();
	}

	for(int i=0; i<3; i++){
		if(allFactories[i]!=NULL){
			delete allFactories[i];
            allFactories[i]=NULL;
		}
	}

	delete air;
	delete land;

}
