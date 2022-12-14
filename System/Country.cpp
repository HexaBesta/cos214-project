#include "Country.h"
#include "Alliances.h"
#include "Map.h"
#include "Director.h"

using namespace std;

Country::Country(string name, int colour, Player *player)
{
	this->name = name;
	this->countryState = new NeutralState();
	cout << "Created country " << this->name << endl;
	this->director = new Director();
	this->alliance = new Alliances(name,colour);
	//this->alliance=NULL;
	this->military.push_back(NULL);
	this->military.clear();
	this->moraleAverage = 100;
	this->civilianPopulation = rand() % (100) + 150;
	this->player = player;
	this->economy = rand() % (200) + 2400;
	// default state
}

Country::~Country()
{
	cout << "Deleted country " << this->name << endl;
	if (countryState != NULL)
	{
		delete countryState;
	}

	while (!military.empty())
	{
		if (military.back() != NULL)
			delete military.back();
		military.pop_back();
	}

	
}

string Country::requestState()
{
	return this->countryState->requestState();
}

void Country::setCountryState(CountryState *countryState)
{
	if (this->countryState != NULL)
	{
		delete this->countryState;
	}
	this->countryState = countryState;
}

double Country::getCountryMoral()
{
	if (this->updateCountryMoral())
		return this->moraleAverage;
	return 0;
}

bool Country::updateCountryMoral()
{
	if (this->countryState->requestState().compare("Joined"))
	{
		this->moraleAverage = 0;
		for (auto unit : this->military)
		{
			this->moraleAverage += unit->getAverageMoral();
		}

		double ratio = (this->moraleAverage * 1.0) / this->military.size();

		if (ratio < 20)
		{
			cout << "Country: " << this->name << " is withdrawing due to low morale." << endl;
			this->setCountryState(new WithdrawnState());
			this->alliance->withdrawCountry(this);
			return false;
		}
		return true;
	}
	else
	{
		return true;
	}
}

Alliances *Country::getAlliances()
{
	return this->alliance;
}

void Country::setAlliance(Alliances *alliance)
{
	this->alliance = alliance;
	this->setCountryState(new JoinedState());
}

string Country::getName()
{
	return this->name + " $"+to_string(economy)+"  Pop:"+to_string(civilianPopulation);
}

void Country::recruitPlatoon(Map * map,sf::RenderWindow* window,vector<sf::Drawable*> ui){
	/*
	Check country moral
	*/
	if (this->getCountryMoral() < 30)
	{
		cout << "No new recruits are lining up... " << this->getName() << "'s moral is running low, better send those troops some goods" << endl;
		return;
	}
	Unit * unit = this->countryState->recruitPlatoon(this->director, this, player,ui);

	if (unit)
	{
		this->decreasePopulation(unit->getSize());
		unit->setCountry(this);
		this->military.push_back(unit);
		this->updateCountryMoral();
		cout << "Adding new platoon to " << this->name << " military" << endl;
	}
	else
	{
		cout << "No unit created" << endl;
		return;
	}
	
	if(map->addPlatoonToMap(unit,window,ui)){
		cout<<"Platoon succesfully deployed"<<endl;
	}else{
		cout<<"No Area to place platoon, it seems that all is lost. "<<this->getName()<<" withdraws"<<endl;
		this->setCountryState(new WithdrawnState());
		this->alliance->withdrawCountry(this);
	}
}

void Country::removeDeadPlatoons()
{
	int x = 0;
	for (Unit *platoon : this->military)
	{
		if (platoon->getState() == "Dead")
		{
			delete platoon;
			this->military.erase(this->military.begin() + x);
		}
		x++;
	}
}

void Country::setPlayer(Player *player)
{
	this->player = player;
}

Player *Country::getPlayer()
{
	return this->player;
}

int Country::getPopulation()
{
	return this->civilianPopulation;
}

void Country::decreasePopulation(int toDec)
{
	this->civilianPopulation -= toDec;
}

void Country::babiesGrowUpNow()
{
	double increase = this->civilianPopulation * 0.02;
	int inc = (int)(increase + 1);
	this->civilianPopulation = this->civilianPopulation + inc;
}

int Country::getEconomy()
{
	return this->economy;
}

void Country::spendMoney(int dec)
{
	this->economy -= dec;
}

void Country::increaseEconomy(double increase)
{
	this->economy = (int)(this->economy * (increase + 1));
}