#ifndef JOINEDSTATE_H
#define JOINEDSTATE_H
#include "CountryState.h"


class Player;

using namespace std;

class JoinedState : public CountryState {
    public:
    	/**
		 * @brief Handles what the Joined Country does
		 */
        void handleCountry();
        /**
		 * @brief Returns a new JoinedState class
		 */
        CountryState* changeCountryState();
        /**
		 * @brief Requests the current state
         * @return A string that represents the Joined Country state
		 */
        string requestState();

        /**
         * @brief Makes a platoon for the country using builder
         * 
         * @return newly made Platoon
         * 
         */
        virtual Unit * recruitPlatoon(Director * director, Country * country, Player * player,vector<sf::Drawable*> ui);
};

#endif
