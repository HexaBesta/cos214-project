#ifndef COUNTRYSTATE_H
#define COUNTRYSTATE_H

namespace Main {
	class CountryState {


	public:
		virtual void handleCountry() = 0;

		virtual Main::CountryState* changeCountryState() = 0;
	};
}

#endif
