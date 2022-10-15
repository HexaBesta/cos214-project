#ifndef WITHDRAWNSTATE_H
#define WITHDRAWNSTATE_H

#include "CountryState.h"

using namespace std;

class WithdrawnState : public CountryState {
    public:
        void handleCountry();
        CountryState* changeCountryState();
};

#endif