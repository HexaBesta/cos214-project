#ifndef JOINEDSTATE_H
#define JOINEDSTATE_H
#include "CountryState.h"
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
};

#endif
