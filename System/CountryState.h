#ifndef COUNTRYSTATE_H
#define COUNTRYSTATE_H
#include <string>
#include <iostream>

using namespace std;

class Director;
class Unit;
class Country;
class Player;

class CountryState {
	public:
		/**
		 * @brief A pure virtual function that handles was the country does
		 */
		virtual void handleCountry() = 0;
		/**
		 * @brief A pure virtual function that changes the country state
		 * @return The required CountryState class
		 */
		virtual CountryState *changeCountryState() = 0;
		/**
		 * @brief A pure virtual function that returns the current country state
		 * @return A string that represents the current country state
		 */
		virtual string requestState() = 0;

		/**
		 * @brief Stubbed method to construct platoon, implemented only in join
		 * 
		 * @param director 
		 * @return Unit* 
		 */
		virtual Unit * recruitPlatoon(Director * director, Country * country, Player * player);

		/**
		 * @brief Destroy the Country State object
		 * 
		 */
		virtual ~CountryState(){};
};

#endif
