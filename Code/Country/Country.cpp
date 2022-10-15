#include "Country.h"

using namespace std;

Country::Country(string name) {
	this->name = name;
	this->moral = 100;
	cout << "Created country " << this->name << endl;
}

void Country::requestState() {
	// this->countryState->request();
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
