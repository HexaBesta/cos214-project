#include "Country.h"

using namespace std;

Country::Country(string name) {
	this->name = name;
	this->moral = 100;
	this->countryState = new NeutralState();
	cout << "Created country " << this->name << endl;

	// default state
}

Country::~Country() {
	delete this->countryState;
	this->countryState = NULL;

	cout << "Deleted country " << this->name << endl;
}

void Country::requestState() {
	cout << "Country State: " << this->countryState->requestState() << endl;
}

void Country::setCountryState(CountryState* countryState) {
	this->countryState = countryState;
}

double Country::getCountryMoral() {
	return this->moral;
}

bool Country::updateCountryMoral(double m) {
	this->moral = m;
	return true;
}
