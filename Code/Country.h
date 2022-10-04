#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include "CountryState.h"
using namespace std;

class Country
{

private:
	string name;
	CountryState *countryState;

	public:
		void request();

		void setCountryState(CountryState* countryState);
	};


#endif
