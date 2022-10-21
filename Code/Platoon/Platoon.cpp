#include "Platoon.h"

Platoon::Platoon(vector<Unit *> human, vector<Unit *> vehicles, int pewpew, int boomboom)
{
	this->humans = human;
	this->vehicles = vehicles;
	this->pewpew = pewpew;
	this->boomboom = boomboom;
	// this->strategy = new PewPewAttack();
	cout << "Remeber to pewpew in platoon contrsuctor" << endl;
}

void Platoon::construct()
{
	// TODO - implement Platoon::construct
	throw "Not yet implemented";
}

void Platoon::print()
{
	int health = 0;
	int damage = 0;
	int humanCounter = 0;
	int vehiclesCounter = 0;
	for (auto it : this->humans)
	{
		health += it->getHealth();
		damage += it->getDamage();
		humanCounter++;
	}
	for (auto it : this->vehicles)
	{
		health += it->getHealth();
		damage += it->getDamage();
		vehiclesCounter++;
	}

	this->health = health;
	this->damage = damage;

	if (health == 0)
	{
		cout << "Your platoon is dead" << endl;
		this->setUnitState(new DeadState());
	}
	else
	{
		cout << "Platoon\nHealth: " << health << "\nDamage: " << damage << "\nAmount of Soldiers: " << humanCounter << " Amount of Vehicles: " << vehiclesCounter << endl;
	}
}

void Platoon::changeStrategy()
{
	if (this->strategy->getPlatoonStrategy().compare("pew") == true && boomboom >= 10)
	{
		PlatoonStrategy *newStrategy = this->strategy->toggleStrategy();
		delete this->strategy;
		this->strategy = newStrategy;
	}else if(this->strategy->getPlatoonStrategy().compare("boom") == true && pewpew >= 200){
		PlatoonStrategy *newStrategy = this->strategy->toggleStrategy();
		delete this->strategy;
		this->strategy = newStrategy;
	}
}

void Platoon::retrieveAmmo(Ammunition* ammo){
	
}


void Platoon::getAccumlateMoral(){
	int moral = 0;
	
	for (auto it : this->humans)
	{
		moral += it->getMoral();
	}

	this->moral = moral;
}

int Platoon::getMoral(){
	this->getAccumlateMoral();
	return this->moral;
}

void Platoon::getAccumlateHealth(){
	int health = 0;

	for (auto it : this->humans)
	{
		health += it->getHealth();
	}
	
	for (auto it : this->vehicles)
	{
		health += it->getHealth();
	}

	this->health = health;
}

int Platoon::getHealth(){
	this->getAccumlateHealth();
	return this->health;
}

Unit *Platoon::split()
{

	size_t const half_sizeH = this->humans.size() / 2;
	vector<Unit *> human1(this->humans.begin(), this->humans.begin() + half_sizeH);
	vector<Unit *> human2(this->humans.begin() + half_sizeH, this->humans.end());

	size_t const half_sizeV = this->vehicles.size() / 2;
	vector<Unit *> vehicles1(this->vehicles.begin(), this->vehicles.begin() + half_sizeV);
	vector<Unit *> vehicles2(this->vehicles.begin() + half_sizeV, this->vehicles.end());

	int halfpew = pewpew / 2;
	int halfboom = boomboom / 2;

	this->humans = human1;
	this->vehicles = vehicles1;
	this->pewpew = pewpew / 2;
	this->boomboom = boomboom / 2;

	Platoon *split = new Platoon(human2, vehicles2, halfpew, halfboom);
	return split;
}

void Platoon::join(Unit *platoon1)
{

	Platoon *platoon = dynamic_cast<Platoon *>(platoon1);
	this->humans.insert(this->humans.end(), platoon->humans.begin(), platoon->humans.end());
	this->vehicles.insert(this->vehicles.end(), platoon->vehicles.begin(), platoon->vehicles.end());
	this->pewpew = this->pewpew + platoon->pewpew;
	this->boomboom = this->boomboom + platoon->boomboom;
}

// added

bool Platoon::takeDamage(int damage, bool checkPew)
{
	if (this->health > 0)
	{
		if (checkPew)
		{
			int random;
			bool human = true;
			do
			{
				random = std::rand() % (humans.size() + vehicles.size());
				if (random >= humans.size())
				{
					random = random - humans.size();
					human = false;
				}
			} while (!((human && this->humans.at(random)->getHealth() > 0) || (!human && this->vehicles.at(random)->getHealth() > 0)));
		}
		else
		{
			this->health = this->health - damage;
		}
	}

	if (this->getHealth() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Unit *Platoon::takeRandom()
{
	int unit = rand() % 2;
	if (unit == 0)
	{
		int chosen = rand() % humans.size();
		return humans.at(chosen);
	}
	else if (unit == 1)
	{
		int chosen = rand() % vehicles.size();
		return vehicles.at(chosen);
	}
	return NULL;
}

void Platoon::attack(Platoon *other)
{
	this->strategy->attack(other);
}

Platoon::~Platoon()
{
	while (!humans.empty())
	{
		delete humans.back();
		humans.pop_back();
	}

	while (!vehicles.empty())
	{
		delete vehicles.back();
		vehicles.pop_back();
	}

	delete strategy;
	delete bob;
}