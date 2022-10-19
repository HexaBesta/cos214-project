#include "Platoon.h"

Platoon::Platoon(vector<Unit *> human, vector<Unit *> vehicles, int pewpew, int boomboom)
{
	this->humans = human;
	this->vehicles = vehicles;
	this->pewpew = pewpew;
	this->boomboom = boomboom;
	//this->strategy = new PewPewAttack();
	cout<<"Remeber to pewpew in platoon contrsuctor"<<endl;
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
	if(this->strategy.)
	PlatoonStrategy * newStrategy = this->strategy->toggleStrategy();
	delete this->strategy;
	this->strategy = newStrategy;
}

Unit* Platoon::split()
{
	
	size_t const half_sizeH = this->humans.size() / 2;
	vector<Unit *> human1(this->humans.begin(), this->humans.begin() + half_sizeH);
	vector<Unit *> human2(this->humans.begin() + half_sizeH, this->humans.end());

	size_t const half_sizeV = this->vehicles.size() / 2;
	vector<Unit *> vehicles1(this->vehicles.begin(), this->vehicles.begin() + half_sizeV);
	vector<Unit *> vehicles2(this->vehicles.begin() + half_sizeV, this->vehicles.end());

	int halfpew = pewpew/2;
	int halfboom = boomboom/2;

	this->humans = human1;
	this->vehicles = vehicles1;
	this->pewpew = pewpew/2;
	this->boomboom = boomboom/2;

	Platoon *split = new Platoon(human2, vehicles2, halfpew, halfboom);
	return split;
}

void Platoon::join(Unit *platoon1)
{

	Platoon* platoon = dynamic_cast<Platoon*>(platoon1);
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
			do{
				random = std::rand()%(humans.size() + vehicles.size());
				if(random>=humans.size()){
					random = random - humans.size();
					human = false;			
				}
			}while(!((human && this->humans.at(random)->getHealth()>0) || (!human && this->vehicles.at(random)->getHealth()>0)));
		}else{
			this->health = this->health - damage;
		}
	}

	if(this->getHealth()>0){
		return true;
	}else{
		return false;
	}

	return -1;
}

void Platoon:: attack(Platoon *other){
	this->strategy->attack(other);
}