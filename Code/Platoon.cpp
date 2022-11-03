#include "Platoon.h"

Platoon::Platoon(vector<Unit *> human, vector<Unit *> vehicles, int pewpew, int boomboom)
{
	this->humans = human;
	this->vehicles = vehicles;
	this->pewpew = pewpew;
	this->boomboom = boomboom;
	this->strategy = new PewPewAttack(this);
	this->country = NULL;
}

void Platoon::construct()
{
	// TODO - implement Platoon::construct
	throw "Not yet implemented";
}

string Platoon::toString(int lineLen)
{
	string out="";
	int health = 0;
	int damage = 0;
	int deadUnits = 0;
	for (auto it : this->humans)
	{
		health += it->getHealth();
		damage += it->getDamage();
		if(it->getState().compare("Dead") == 0){
			deadUnits++;
		}
	}
	for (auto it : this->vehicles)
	{
		health += it->getHealth();
		damage += it->getDamage();
		if(it->getState().compare("Dead") == 0){
			deadUnits++;
		}
	}

	this->health = health;
	this->damage = damage;
	string add="";

	if (health <= 0)
	{
		add+= "\n|                        Your platoon is dead";
		while(add.length()<lineLen){
			add+= " ";
		}
		add+= "|";
		out+=add;
		this->setUnitState(new DeadState());
	}
	else
	{	

		add= "|                        Platoon";
		while(add.length()<lineLen){
			add+= " ";
		}
		add+= "|";
		out+=add;

		add= "\n|                        Country: " + country->getName();
		while(add.length()<lineLen){
			add+= " ";
		}
		add+= " |";
		out+=add;

		add=" \n|                           Health: " + to_string(health);
		while(add.length()<lineLen+2){
			add+= " ";
		}
		add+= "|";
		out+=add;

		add= "\n|                           Damage: " + to_string(damage);
		while(add.length()<lineLen+1){
			add+= " ";
		}
		add+= "|";
		out+=add;

		add= "\n|                           Amount of Soldiers: " + to_string(humans.size());
		while(add.length()<lineLen+1){
			add+= " ";
		}
		add+= "|";
		out+=add;

		add= "\n|                           Amount of Vehicles: " + to_string(vehicles.size());
		while(add.length()<lineLen+1){
			add+= " ";
		}
		add+= "|";
		out+=add;

		add= "\n|                           Amount of Dead Units: " + to_string(deadUnits);
		while(add.length()<lineLen+1){
			add+= " ";
		}
		add+= "|";
		out+=add;

		add= "\n|                           Amount of Bullets: " + to_string(pewpew);
		while(add.length()<lineLen+1){
			add+= " ";
		}
		add+= "|";
		out+=add;

		add= "\n|                           Amount of Explosives: " + to_string(boomboom);
		while(add.length()<lineLen+1){
			add+= " ";
		}
		add+= "|";
		out+=add;
	}

	return out;
}

void Platoon::changeStrategy()
{
	if (this->strategy->getPlatoonStrategy().compare("pew") == 0 && boomboom >= 10)
	{
		PlatoonStrategy *newStrategy = this->strategy->toggleStrategy();
		delete this->strategy;
		this->strategy = newStrategy;
	}
	else if (this->strategy->getPlatoonStrategy().compare("boom") == 0 && pewpew >= 200)
	{
		PlatoonStrategy *newStrategy = this->strategy->toggleStrategy();
		delete this->strategy;
		this->strategy = newStrategy;
	}else{
		cout<<"Cannot change strategy, insefficent ammo. Recommend calling for ammo"<<endl;
	}
}

void Platoon::replenish(Transport ** transport){
	if(transport[0] != NULL){
		this->retrieveHealth(transport[0]);
	}

	if(transport[1] != NULL){
		this->retrieveAmmo(transport[1]);
	}

	if(transport[2] != NULL){
		this->retrieveGoods(transport[2]);
	}

}

void Platoon::retrieveAmmo(Transport *ammo)
{
	while (!ammo->isEmpty())
	{
		this->boomboom += ammo->replenish();
		this->pewpew += ammo->replenish(true);
	}
}

void Platoon::retrieveGoods(Transport *good)
{
	while (!good->isEmpty())
	{
		int index = rand()%this->humans.size();
		this->humans.at(index)->setMoral(good->replenish());
	}
}

void Platoon::retrieveHealth(Transport *medic)
{
	while (!medic->isEmpty())
	{
		int index = rand()%this->humans.size();
		this->humans.at(index)->setHealth(medic->replenish());
	}
	this->setAccumlateHealth();
}

void Platoon::setAccumlateMoral()
{
	int moral = 0;

	for (auto it : this->humans)
	{
		moral += it->getMoral();
	}

	this->moral = moral;
}

int Platoon::getMoral()
{
	this->setAccumlateMoral();
	return this->moral;
}

double Platoon::getAverageMoral(){
	return this->getMoral()/(this->humans.size()*1.0);
}

void Platoon::setAccumlateHealth()
{
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

	if(health<0){
		this->health = 0;
	}
}

int Platoon::getHealth()
{
	this->setAccumlateHealth();
	return this->health;
}

string Platoon::getStrategyType(){
	return this->strategy->getPlatoonStrategy();
}

int Platoon::getSize(){
	int size = humans.size() + vehicles.size();
	return size;
}

int Platoon::getDamage(){
	int damage = 0;
	for (auto it : this->humans)
	{
		damage += it->getDamage();
	}
	for (auto it : this->vehicles)
	{
		damage += it->getDamage();
	}
	return damage;
}

int* Platoon::getAmmo(){
	int * ammo  = new int[2];
	ammo[0] = this->pewpew;
	ammo[1] = this->boomboom;
	return ammo;  
}

void Platoon::decreaseAmmo(){
	if(this->strategy==nullptr){
		this->strategy = new PewPewAttack(this);
		this->pewpew--;
	}else if(this->strategy->getPlatoonStrategy().compare("pew")==0){
		this->pewpew--;
	}else if(this->strategy->getPlatoonStrategy().compare("boom")==0){
		this->boomboom--;
	}
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
	if (this->getHealth() > 0)
	{
		if (checkPew)
		{
			this->takeRandom()->takeDamage(damage);
			if(this->getHealth()<=0){
				DeadState* deadState = new DeadState();
				this->setUnitState(deadState);
			}
		}
		else
		{
			int rand1 = rand()%humans.size()+1;
			rand1 += rand()%vehicles.size();
			int boomDamage = damage/rand1;
			for(int x = 0; x<rand1; x++){
				this->takeRandom()->takeDamage(boomDamage);
				if(this->getHealth()<=0){
					DeadState* deadState = new DeadState();
					this->setUnitState(deadState);
					break;
				}
			}
		}
	}

	if (this->getHealth() > 0)
	{
		this->setUnitState(new InjuredState());
		return true;
	}
	else
	{
		this->setUnitState(new DeadState());
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


void Platoon::attack(Unit *other)
{
	this->strategy->attack(other);
}

Platoon::~Platoon()
{
	while (!humans.empty())
	{
		if(humans.back() != NULL)
			delete humans.back();
		humans.pop_back();
	}

	while (!vehicles.empty())
	{
		if(humans.back() != NULL)
			delete vehicles.back();
		vehicles.pop_back();
	}

	delete strategy;
}
