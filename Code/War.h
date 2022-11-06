#ifndef WAR_H
#define WAR_H
#include "Alliances.h"
#include "Area.h"
#include "CPU.h"
#include "User.h"
#include <SFML/Graphics.hpp>
using namespace std;

class War{
	protected:
		Alliances *groupOne;
		Alliances *groupTwo;
		Player * player;
		Map * map;
		bool  turn;
		bool real;

		/**
		 * @brief Check whether to toggle between playing modes
		 * 
		 */
		virtual void checkTogglePlayer()=0;

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
		virtual void takeTurn(int actions,sf::RenderWindow* window, vector<sf::Drawable*> &ui)=0;

		/**
		 * @brief one round consisting of two seperate turns
		 * 
		 */
		virtual void round(sf::RenderWindow* window, vector<sf::Drawable*> &ui)=0;

	public:
		/**
		 * @brief Construct a new God Of War object using setup file
		 * 
		 * @param setupFile name of the textfile used to set up game
		 */
		//War(string setupFile);


		/**
		 * @brief Calls functions in player to initialise sides with countries with platoons
		 * 
		 */
		virtual void initialiseSides()=0;

		/**
		 * @brief Loop that continues while war is active
		 * 
		 */
		virtual void warLoop()=0;

		/**
		 * @brief Print the Map object
		 * 
		 */
		virtual void printMap()=0;

		/**
		 * @brief Destroy the  War object and assigned memory
		 * 
		 */
		virtual ~War(){
            cout<<"Destroying war"<<endl;
        }

};

#endif
