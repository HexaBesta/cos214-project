#include "Area.h"
#include "../Battle/Battle.h"

Area::Area(string name, int index, int colour,bool factories)
{
	this->name = name;
	this->index = index;
	this->colour = colour;

	if (factories)
	{
		allFactories[0]=new PTFactory();
		allFactories[1]=new WTFactory();
		allFactories[2]=new GTFactory();
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

Battle *Area::marchIn(Unit *unit)
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
	
	if (checkIfBattleHappens())
	{
		return new Battle(air,land,this);
	}
	return NULL;
	
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

bool Area::checkIfBattleHappens(){

	if (land->getDefender()!=NULL && land->getAttacker()!=NULL)
	{
		return true;
	}

	if (air->getDefender()!=NULL && air->getAttacker()!=NULL)
	{
		return true;
	}

	if (land->getDefender()!=NULL && air->getAttacker()!=NULL)
	{
		return true;
	}

	if (air->getDefender()!=NULL && land->getAttacker()!=NULL)
	{
		return true;
	}
	
	return false;

}


Area::~Area()
{
	while (!areasCoordinates.empty())
	{
		delete areasCoordinates.back();
		areasCoordinates.pop_back();
	}

	delete allFactories[0];
	delete allFactories[1];
	delete allFactories[2];


}
