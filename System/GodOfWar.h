#ifndef GODOFWAR_H
#define GODOFWAR_H
#include "Alliances.h"
#include "War.h"
#include "Area.h"
#include "CPU.h"
#include "User.h"
#include <SFML/Graphics.hpp>
using namespace std;

class GodOfWar: public War{
	private:
		

		/**
		 * @brief Check whether to toggle between playing modes
		 * 
		 */
		virtual void checkTogglePlayer();

		/**
		 * @brief allows alliance to take a turn
		 * 
		 * @details While there are action points remaining:
		 * 	- Pick a country:
		 * 	- Select action:
		 * 			- Destroy transport route
		 * 			- Choose area:
		 * 				- March into adjacent areas
		 * 				OR
		 * 				- Choose resource to clone factory of
		 * 	When no more action points remaining - resolveAllBattles
		 * 
		 * @param actions number of action points available
		 */
		virtual void takeTurn(int actions,sf::RenderWindow* window, vector<sf::Drawable*> &ui);

		/**
		 * @brief one round consisting of two seperate turns
		 * 
		 */
		virtual void round(sf::RenderWindow* window, vector<sf::Drawable*> &ui);

	public:
		/**
		 * @brief Construct a new God Of War object using setup file
		 * 
		 * @param setupFile name of the textfile used to set up game
		 */
		GodOfWar(string setupFile);


		/**
		 * @brief Calls functions in player to initialise sides with countries with platoons
		 * 
		 */
		virtual void initialiseSides();

		/**
		 * @brief Loop that continues while war is active
		 * 
		 */
		virtual void warLoop();

		/**
		 * @brief Print the Map object
		 * 
		 */
		virtual void printMap();

		/**
		 * @brief Destroy the God Of War object and assigned memory
		 * 
		 */
		virtual ~GodOfWar();

};

#endif
