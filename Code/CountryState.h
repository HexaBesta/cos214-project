#ifndef COUNTRYSTATE_H
#define COUNTRYSTATE_H
using namespace std;

class CountryState
{

public:
	virtual void handleCountry() = 0;

	virtual CountryState *changeCountryState() = 0;
};

#endif
