#include "Area.h"
#include "Human.h"
#include "LandBranch.h"
#include "AirBranch.h"
Area::Area(string name, int index, int colour, bool factories, bool troops) : MapComponent()
{
	this->name = name;
	this->index = index;
	this->colour = colour;
	this->land = new TheatreOfWar("Land");
	this->air = new TheatreOfWar("Air");
	if (factories)
	{
		this->initialiseAllFactories();
	}
	else
	{
		allFactories[0] = NULL;
		allFactories[1] = NULL;
		allFactories[2] = NULL;
	}
	if (colour != 94)
	{
		country = new Country(name, colour, NULL);
	}
	else
	{
		country = NULL;
	}

	if (troops)
	{
		vector<Unit *> humans = {};
		humans.push_back(new Human(10, 100, 5, country, true));

		vector<Unit *> vehicles = {};
		Unit *platoon = new AirBranch(new Platoon(humans, vehicles, 2, 2));
		platoon->setCountry(country);
		platoon->setTexture();
		air->setDefender(platoon);
		vector<Unit *> humans2 = {};
		humans2.push_back(new Human(10, 100, 5, country, true));

		vector<Unit *> vehicles2 = {};
		Unit *platoon2 = new LandBranch(new Platoon(humans2, vehicles2, 2, 2));
		platoon2->setCountry(country);
		platoon2->setTexture();
		land->setDefender(platoon2);
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

void Area::updateOwner(Unit *unit)
{
	country = unit->getCountry();
	colour = country->getAlliances()->getColour();
	map->setAreaBorders();
	if (land->getDefender() != NULL)
	{
		land->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()));
	}
	if (air->getDefender() != NULL)
	{
		air->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()) - 32);
	}
}

void Area::marchIn(Unit *unit, Area *from)
{
	if (unit->getBranch() == "LAND BRANCH")
	{
		if (land->getDefender() == NULL)
		{
			if (air->getDefender() == NULL)
			{
				land->setDefender(unit);
				land->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()));
				country = unit->getCountry();
				colour = country->getAlliances()->getColour();

				if (from != NULL)
				{
					map->createTransportRoute(this, from);
				}
				map->setAreaBorders();
			}
			else if (air->getDefender()->getAlliance() == unit->getAlliance())
			{
				land->setDefender(unit);
				land->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()));
				country = unit->getCountry();
				colour = country->getAlliances()->getColour();
				if (from != NULL)
				{
					map->createTransportRoute(this, from);
				}
				map->setAreaBorders();
			}
			else if (air->getDefender()->getAlliance() != unit->getAlliance())
			{
				land->setAttacker(unit);
			}
		}
		else if (land->getDefender()->getAlliance() == unit->getAlliance())
		{
			land->setDefender(unit);
			land->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()));
			country = unit->getCountry();
			colour = country->getAlliances()->getColour();
			if (from != NULL)
			{
				map->createTransportRoute(this, from);
			}
			map->setAreaBorders();
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
				air->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()) - 32);
				country = unit->getCountry();
				colour = country->getAlliances()->getColour();
			}
			else if (land->getDefender()->getAlliance() == unit->getAlliance())
			{
				air->setDefender(unit);
				air->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()) - 32);
			}
			else if (land->getDefender()->getAlliance() != unit->getAlliance())
			{
				air->setAttacker(unit);
			}
		}
		else if (air->getDefender()->getAlliance() == unit->getAlliance())
		{
			air->setDefender(unit);
			air->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()) - 32);
		}
		else if (air->getDefender()->getAlliance() != unit->getAlliance())
		{
			air->setAttacker(unit);
		}
	}
}

void Area::marchOut(Area *whereTo)
{
	if (!map->areAdjacent(whereTo, this))
	{
		cout << "Cannot march to area that is not adjacent" << endl;
		return;
	}

	if (land->getDefender() != NULL)
	{
		whereTo->marchIn(land->MarchOut(false), this);
		
	}
	if (air->getDefender() != NULL)
	{
		
		whereTo->marchIn(air->MarchOut(false), this);
		
	}
}

bool Area::requestReinforcements(string type)
{
	vector<Area *> adjacent = this->map->listAdjacent(this, true);

	int allianceColor = 0;

	if (type.compare("attack") == 0)
	{
		if (this->land->getAttacker() != NULL)
		{
			allianceColor = this->land->getAttacker()->getCountry()->getAlliances()->getColour();
		}
		else if (this->air->getAttacker() != NULL)
		{
			allianceColor = this->air->getAttacker()->getCountry()->getAlliances()->getColour();
		}
		else
		{
			throw "No active attack side found to send reinforcements to";
		}
	}
	else if (type.compare("defense") == 0)
	{
		if (this->land->getDefender() != NULL)
		{
			allianceColor = this->land->getDefender()->getCountry()->getAlliances()->getColour();
		}
		else if (this->air->getDefender() != NULL)
		{
			allianceColor = this->air->getDefender()->getCountry()->getAlliances()->getColour();
		}
		else
		{
			throw "No active defense side found to send reinforcements to";
		}
	}
	else
	{
		throw "Invalid paramater passed to requestReinforcements";
	}

	if (allianceColor == 0)
	{
		return false;
	}

	for (Area *area : adjacent)
	{
		Unit *unit = area->sendReinforcements(allianceColor);
		if (unit != NULL)
		{
			if (type.compare("attack") == 0)
			{
				this->air->setAttacker(unit);
			}
			else
			{
				this->air->setDefender(unit);
			}
			return true;
		}
	}

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

	this->areasCoordinates.push_back(new Coordinate(stoi(xStr), stoi(yStr), colour, this, map->getGridXSize(), map->getGridYSize()));
}

vector<Coordinate *> Area::getAreaCoordinates()
{
	return this->areasCoordinates;
}

Battle *Area::returnBattle()
{

	bool isBattle = false;

	if (land->getDefender() != NULL && land->getAttacker() != NULL)
	{
		isBattle = true;
	}

	if (air->getDefender() != NULL && air->getAttacker() != NULL)
	{
		isBattle = true;
	}

	if (land->getDefender() != NULL && air->getAttacker() != NULL)
	{
		isBattle = true;
	}

	if (air->getDefender() != NULL && land->getAttacker() != NULL)
	{
		isBattle = true;
	}

	if (isBattle)
	{
		return new Battle(air, land, this, this->map->getPlayer());
	}
	return NULL;
}

TransportFactory *Area::getFactory(int type)
{

	if (allFactories[type] == NULL)
	{
		return NULL;
	}
	else
	{
		return allFactories[type]->clone();
	}
}

bool Area::requestFactory(int type)
{
	TransportFactory *foundFactory = map->requestFactoryForArea(this, type);
	if (foundFactory == NULL)
	{
		return false;
	}
	else
	{
		allFactories[type] = foundFactory;
		return true;
	}
}

string Area::toString()
{
	string out = "";
	string next = "";
	int lineChars = 70;

	for (int i = 0; i < lineChars + 1; i++)
		out += "-";
	out += "\n";

	string owner = "None";
	if (country != NULL)
	{
		owner = country->getName();
	}
	next = "           Name:" + name + "  ID:" + to_string(index) + "  Colour:" + to_string(colour) + "  Owner:" + owner;
	while (next.length() < lineChars - 1)
	{
		next += " ";
	}

	out += "|\033[48;5;" + to_string((this->colour)) + "m" + next + "\033[0m" + "|\n";

	// BreakL Line
	out += "|";
	for (int i = 0; i < lineChars - 1; i++)
		out += "-";
	out += "|\n";

	next = "|     Factories:    Person[" + to_string(allFactories[0] != NULL) + "]      Ammo[" + to_string(allFactories[1] != NULL) + "]      Goods[" + to_string(allFactories[2] != NULL) + "]";
	while (next.length() < lineChars)
	{
		next += " ";
	}
	next += "|\n";
	out += next;
	// BreakL Line
	out += "|";
	for (int i = 0; i < lineChars - 1; i++)
		out += "-";
	out += "|\n";

	next = "|     Air:     ";
	while (next.length() < lineChars)
	{
		next += " ";
	}
	next += "|\n";
	out += next;

	next = air->toString(lineChars);
	out += next;

	// BreakL Line
	out += "|";
	for (int i = 0; i < lineChars - 1; i++)
		out += "-";
	out += "|\n";

	next = "|     Land:     ";
	while (next.length() < lineChars)
	{
		next += " ";
	}
	next += "|\n";
	out += next;

	next = land->toString(lineChars);
	out += next;

	for (int i = 0; i < lineChars + 1; i++)
		out += "-";
	out += "\n";

	return out;
}

Country *Area::getCountry()
{
	return this->country;
}

bool Area::retreat(string side)
{

	vector<Area *> adjacent = this->map->listAdjacent(this, true);

	int allianceColour = 0;
	Unit *landUnit = NULL;
	Unit *airUnit = NULL;

	// Get alliance colour
	if (side.compare("defense") == 0)
	{

		landUnit = this->land->getDefender();
		airUnit = this->air->getDefender();

		if (landUnit)
		{
			allianceColour = landUnit->getCountry()->getAlliances()->getColour();
		}
		else if (airUnit)
		{
			allianceColour = airUnit->getCountry()->getAlliances()->getColour();
		}
		else
		{
			cout << "No defending units to retreat" << endl;
			throw "No defending units to retreat";
		}
	}
	else if (side.compare("attack") == 0)
	{
		landUnit = this->land->getAttacker();
		airUnit = this->air->getAttacker();

		if (landUnit)
		{
			allianceColour = landUnit->getCountry()->getAlliances()->getColour();
		}
		else if (airUnit)
		{
			allianceColour = airUnit->getCountry()->getAlliances()->getColour();
		}
		else
		{

			throw "No attacking units to retreat";
		}
	}

	if (allianceColour == 0)
	{
		throw "Invalid parameter passed to retreat";
	}

	// Check if there is an adjacent area that can accept retreating troops
	for (Area *area : adjacent)
	{
		if (area->getColour() == allianceColour || area->getColour() == 94)
		{
			if (side.compare("defense") == 0)
			{
				if (this->land->getAttacker() != NULL)
				{
					Country *country = this->land->getAttacker()->getCountry();
					this->colour = country->getAlliances()->getColour();
					this->country = country;
				}
				else if (this->air->getAttacker() != NULL)
				{
					Country *country = this->air->getAttacker()->getCountry();
					this->colour = country->getAlliances()->getColour();
					this->country = country;
				}
				else
				{
					this->colour = 94;
					this->country = NULL;
				}
			}

			if (landUnit != NULL)
			{
				area->marchIn(land->retreat(side), this);
			}
			if (airUnit != NULL)
			{
				area->marchIn(air->retreat(side), this);
			}

			return true;
		}
	}

	cout << "No adjacent areas suitable to retreat to" << endl;

	return false;
}

void Area::retreatInto(Unit *unit)
{
	if (unit->getBranch() == "LAND BRANCH")
	{
		land->setDefender(unit);
		country = unit->getCountry();
		colour = country->getAlliances()->getColour();
	}
	else if (unit->getBranch() == "AIR BRANCH")
	{
		air->setDefender(unit);
	}
}

Unit *Area::sendReinforcements(int color)
{
	if (this->air->getDefender() != NULL)
	{
		if (this->air->getAttacker() == NULL && this->land->getAttacker() == NULL)
		{
			if (this->air->getDefender()->getCountry()->getAlliances()->getColour() == color)
			{
				return this->air->sendReinforcements();
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

void Area::accept(Visitor *visitor)
{
	visitor->visit(this);
}

void Area::setCoordinateBorders(int x, int y, bool left, bool leftCon, bool right, bool rightCon, bool top, bool topCon, bool bottom, bool bottomCon)
{
	for (int i = 0; i < areasCoordinates.size(); i++)
	{
		if (areasCoordinates.at(i)->x == x && areasCoordinates.at(i)->y == y)
		{

			string borders = "";
			if (left)
			{
				borders += "Left";
			}
			if (leftCon)
			{
				borders += "C";
			}

			if (right)
			{
				borders += "Right";
			}
			if (rightCon)
			{
				borders += "C";
			}
			if (top)
			{
				borders += "Top";
			}
			if (topCon)
			{
				borders += "C";
			}
			if (bottom)
			{
				borders += "Bottom";
			}
			if (bottomCon)
			{
				borders += "C";
			}
			areasCoordinates.at(i)->setTextureBorders(borders, colour, false);
			return;
		}
	}
}

void Area::draw(sf::RenderWindow *r)
{

	for (size_t i = 0; i < areasCoordinates.size(); i++)
	{
		r->draw((areasCoordinates.at(i)->sprite));
	}
	if (land->getDefender() != NULL)
	{
		// land->getDefender()->setTexture();
		// land->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()));
		r->draw(*(land->getDefender()->getSprite()));
	}
	if (air->getDefender() != NULL)
	{
		// air->getDefender()->setTexture();
		air->getDefender()->getSprite()->setPosition(getMiddleCooridnate()->x * (640 / map->getGridXSize()), getMiddleCooridnate()->y * (640 / map->getGridYSize()) - 32);
		r->draw(*(air->getDefender()->getSprite()));
	}
}

void Area::updateLandSpriteAnimation(sf::Clock *c)
{
	if (land->getDefender() == NULL)
	{
		return;
	}

	land->getDefender()->setTexture();

	// if (c->getElapsedTime().asMilliseconds() >= 90)
	// {
	// 	sf::IntRect re = land->getDefender()->getSprite()->getTextureRect();
	// 	if (re.left == 78)
	// 	{
	// 		re.left = 0;
	// 	}
	// 	else
	// 	{
	// 		re.left += 26;
	// 	}
	// 	land->getDefender()->getSprite()->setTextureRect(re);
	// }
}

void Area::updateAirSpriteAnimation(sf::Clock *c)
{
	if (air->getDefender() == NULL)
	{
		return;
	}

	air->getDefender()->setTexture();

	// if (c->getElapsedTime().asMilliseconds() >= 90)
	// {
	// 	sf::IntRect re = air->getDefender()->getSprite()->getTextureRect();
	// 	if (re.left == 512)
	// 	{
	// 		re.left = 0;
	// 	}
	// 	else
	// 	{
	// 		re.left += 256;
	// 	}
	// 	air->getDefender()->getSprite()->setTextureRect(re);
	// }
}

bool Area::wasClicked(sf::Vector2f click)
{

	for (size_t i = 0; i < areasCoordinates.size(); i++)
	{
		if (areasCoordinates.at(i)->sprite.getGlobalBounds().contains(click))
		{
			return true;
		}
	}
	return false;
}

Coordinate *Area::getMiddleCooridnate()
{
	return areasCoordinates.at((areasCoordinates.size() / 2));
}

bool Area::setCountry(Country *country)
{
	if (this->country == NULL)
	{
		this->country = country;
		this->initialiseAllFactories();
		return true;
	}
	else
	{
		return false;
	}
}

void Area::setColour()
{
	if (this->country != NULL)
	{
		this->colour = this->country->getAlliances()->getColour();
	}
}

void Area::initialiseAllFactories()
{
	allFactories[0] = new PTFactory();
	allFactories[1] = new ATFactory();
	allFactories[2] = new GTFactory();
}

void Area::replenish()
{
	Transport *resources[3];

	if (allFactories[0] == NULL)
	{
		resources[0] == NULL;
	}
	else
	{
		resources[0] == allFactories[0]->makeTypeTransport();
	}

	if (allFactories[1] == NULL)
	{
		resources[1] == NULL;
	}
	else
	{
		resources[1] == allFactories[1]->makeTypeTransport();
	}

	if (allFactories[2] == NULL)
	{
		resources[2] == NULL;
	}
	else
	{
		resources[2] == allFactories[2]->makeTypeTransport();
	}

	this->air->replenish(resources);
	this->land->replenish(resources);
}

Area::~Area()
{
	cout << "Deleting Tranport Route" << endl;
	while (!areasCoordinates.empty())
	{
		delete areasCoordinates.back();
		areasCoordinates.pop_back();
	}

	for (int i = 0; i < 3; i++)
	{
		if (allFactories[i] != NULL)
		{
			delete allFactories[i];
			allFactories[i] = NULL;
		}
	}
	if (air != NULL)
	{
		delete air;
	}

	if (land != NULL)
	{
		delete land;
	}
}
