#include "NeutralState.h"
using namespace std;

void NeutralState::handleCountry() {

}

CountryState* NeutralState::changeCountryState() {
    return new NeutralState();
}