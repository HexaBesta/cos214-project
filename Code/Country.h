#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <iostream>
#include <vector>
#include "NeutralState.h"
#include "JoinedState.h"
#include "WithdrawnState.h"
#include <SFML/Graphics.hpp>
using namespace std;

class Alliances;
class Map;
class Player;

class Country {
	private:
		string name;
		CountryState *countryState;
		double moraleAverage;
		Alliances* alliance;
		vector<Unit*> military;
		Director * director;
		Player* player;
		int civilianPopulation;
		int economy;

	public:
		/**
		 * @brief Constructs a new country object
		 * @param name is the name of the country
		 */
		Country(string name,int colour, Player* player);

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

		/**
		 * @brief Set the Alliance object of 
		 * 
		 * @param alliance 
		 */
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
		void recruitPlatoon(Map * map,sf::RenderWindow* window,vector<sf::Drawable*> ui);

		/**
		 * @brief Removes dead units from military
		 * 
		 * @param unit 
		 */
		void removeDeadPlatoons();

		/**
		 * @brief Sets the player of the country to the passed in player
		 * 
		 * @param player passed in from map
		 */
		void setPlayer(Player* player);

		/**
		 * @brief Get the current player from the country
		 * 
		 * @return Player* 
		 */
		Player* getPlayer();

		/**
		 * @brief Get the Civilian population of the country
		 * 
		 * @return int 
		 */
		int getPopulation();

		/**
		 * @brief Decrease the civilianPopulation of the country
		 * 
		 * @param toDec 
		 */
		void decreasePopulation(int toDec);

		
		/**
		 * @brief Increases population by 10%
		 * 
		 */
		void babiesGrowUpNow();

		/**
		 * @brief Returns the total economy of the Coountry
		 * 
		 * @return int 
		 */
		int getEconomy();

		/**
		 * @brief Decreases the economy based on the amount spent
		 * 
		 */
		void spendMoney(int amount);

		/**
		 * @brief increase the economy by passed in percentage
		 * 
		 * @param growth percentage to grow by
		 */
		void increaseEconomy(double growth);

		/**
		 * @brief Country Deconstructor, will delete the countryState and military vector
		 */
		~Country();

};

#endif
