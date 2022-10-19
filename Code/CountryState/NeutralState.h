#ifndef NEUTRALSTATE_H
#define NEUTRALSTATE_H
#include "CountryState.h"
using namespace std;

class NeutralState : public CountryState {
    public:
    	/**
		 * @brief Handles what the Neutral Country does
		 */
        void handleCountry();
        /**
		 * @brief Returns a new NeutralState class
		 */
        CountryState* changeCountryState();
        /**
		 * @brief Requests the current state
         * @return A string that represents the Neutral Country state
		 */
        string requestState();
};

#endif
