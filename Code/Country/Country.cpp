#include "Country.h"
#include "../Alliances/Alliances.h"
#include "../Map/Map.h"
#include "../Builder/Director.h"

using namespace std;

Country::Country(string name,int colour)
{
	this->name = name;
	this->countryState = new NeutralState();
	cout << "Created country " << this->name << endl;
	this->director = new Director();
	// default state
}

Country::~Country()
{
	if (countryState != NULL)
	{
		delete countryState;
		countryState = NULL;
	}

	for(auto unit: this->military){
		delete unit;
		unit = NULL;
	}

	this->military.clear();

	cout << "Deleted country " << this->name << endl;
}

string Country::requestState()
{
	return this->countryState->requestState();
}

void Country::setCountryState(CountryState *countryState)
{
	if(this->countryState != NULL){
		delete this->countryState;
	}
	this->countryState = countryState;
}

double Country::getCountryMoral()
{
	if(this->updateCountryMoral())
		return this->moraleAverage;
	return 0;
}

bool Country::updateCountryMoral()
{
	if(this->countryState->requestState().compare("Joined")){
		this->moraleAverage = 0;
		for(auto unit: this->military){
			this->moraleAverage += unit->getAverageMoral();
		}

		double ratio = (this->moraleAverage*1.0)/this->military.size();

		if(ratio < 20){
			cout<<"Country: "<<this->name<<" is withdrawing due to low morale."<<endl;
			this->setCountryState(new WithdrawnState());
			this->alliance->withdrawCountry(this);
			return false;
		}
		return true;
	}else{
		return true;
	}
}

Alliances *Country::getAlliances()
{
	return this->alliance;
}

void Country::setAlliance(Alliances * alliance){
	this->alliance = alliance;
	this->setCountryState(new JoinedState());
}

string Country::getName()
{
	return this->name;
}

void Country::recruitPlatoon(Map * map){
	if(this->getCountryMoral()<40){
		cout<<"No new recruits are lining up... "<<this->getName()<<"'s moral is running low, better send those troops some goods"<<endl;
		return;
	}
	Unit * unit = this->countryState->recruitPlatoon(this->director, this);
	if(unit){
		this->military.push_back(unit);
		this->updateCountryMoral();
	}else{
		return;
	}
	
	if(map->addPlatoonToMap(unit)){
		cout<<"Platoon succesfully deployed"<<endl;
	}else{
		cout<<"No Area to place platoon, it seems that all is lost. "<<this->getName()<<" withdraws"<<endl;
		this->setCountryState(new WithdrawnState());
		this->alliance->withdrawCountry(this);
	}
}
