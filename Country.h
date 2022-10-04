#ifndef COUNTRY_H
#define COUNTRY_H

namespace Main {
	class Country {

	private:
		string name;
		Main::CountryState* countryState;

	public:
		void request();

		void setCountryState(Main::CountryState countryState);
	};
}

#endif
