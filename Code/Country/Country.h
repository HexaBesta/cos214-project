#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <iostream>
#include "../CountryState/CountryState.h"
using namespace std;

class Country {
	private:
		string name;
		CountryState *countryState;
		double moral;
	public:
		Country(string);
		~Country();
		void request();
		void setCountryState(CountryState* countryState);

		bool updateCountryMoral(double);
		double getCountryMoral();
};

#endif
