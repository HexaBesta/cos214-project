#ifndef NEUTRALSTATE_H
#define NEUTRALSTATE_H

#include "CountryState.h"

using namespace std;

class NeutralState : public CountryState {
    public:
        void handleCountry();
        CountryState* changeCountryState();
};

#endif
