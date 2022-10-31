#ifndef WITHDRAWNSTATE_H
#define WITHDRAWNSTATE_H
#include "CountryState.h"
using namespace std;

class WithdrawnState : public CountryState {
    public:
    	/**
		 * @brief Handles what the Withdrawn Country does
		 */
        void handleCountry();
        /**
		 * @brief Returns a new WithdrawnState class
		 */
        CountryState* changeCountryState();
        /**
		 * @brief Requests the current state
         * @return A string that represents the Withdrawn Country state
		 */
        string requestState();
};

#endif