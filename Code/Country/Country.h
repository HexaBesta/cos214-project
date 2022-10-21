#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <iostream>
#include "../CountryState/CountryState.h"
#include "../Alliances/Alliances.h"
#include "../CountryState/NeutralState.h"
using namespace std;

class Country {
	private:
		string name;
		CountryState *countryState;
		double moral;
		Alliances* alliance;
	public:
		/**
		 * @brief Constructs a new country object
		 * @param name is the name of the country
		 */
		Country(string name);

		/**
		 * @brief Country Deconstructor, will delete the countryState?
		 */
		~Country();

		/**
		 * @brief returns the state of the currently set country state. !! Need to implement in country state !!
		 */
		void requestState();

		/**
		 * @brief Sets the country state
		 * @param countryState is the state we are changing to
		 */
		void setCountryState(CountryState* countryState);

		/**
		 * @brief Updates the country moral to the provided moral
		 * @param moral is the moral we are updating to
		 * @return Boolean that represents whether the countrys moral was updates or not
		 */
		bool updateCountryMoral(double moral);

		/**
		 * @brief Returns the country moral
		 * @return Double that represents the moral of the country
		 */
		double getCountryMoral();

		/**
		 * @brief Get the Alliances of this country
		 * 
		 * @return Alliances* 
		 */
		Alliances* getAlliances(){
			return this->alliance;
		}
};

#endif
