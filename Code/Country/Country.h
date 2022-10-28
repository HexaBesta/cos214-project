#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <iostream>
#include <vector>
#include "../CountryState/NeutralState.h"
#include "../CountryState/JoinedState.h"
#include "../CountryState/WithdrawnState.h"
using namespace std;

class Alliances;
class Map;

class Country {
	private:
		string name;
		CountryState *countryState;
		double moraleAverage;
		Alliances* alliance;
		vector<Unit*> military;
		Director * director;

	public:
		/**
		 * @brief Constructs a new country object
		 * @param name is the name of the country
		 */
		Country(string name,int colour);

		/**
		 * @brief Country Deconstructor, will delete the countryState?
		 */
		~Country();

		/**
		 * @brief returns the state of the currently set country state. !! Need to implement in country state !!
		 */
		string requestState();

		/**
		 * @brief Sets the country state
		 * @param countryState is the state we are changing to
		 */
		void setCountryState(CountryState* countryState);

		/**
		 * @brief Updates the country moral by recalculating aggregate of units' moral if country is joined
		 * @return Boolean that represents whether the countries moral is above the accepted percentage
		 */
		bool updateCountryMoral();

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
		Alliances* getAlliances();

		void setAlliance(Alliances * alliance);

		/**
		 * @brief Get the Name of this country
		 * 
		 * @return string 
		 */
		string getName();

		/**
		 * @brief makes a new platoon and adds to existing platoon vector
		 * 
		 * @param map so that platoon can be placed on map
		 */
		void recruitPlatoon(Map * map);

};

#endif
