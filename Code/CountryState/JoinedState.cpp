#include "JoinedState.h"
using namespace std;

void JoinedState::handleCountry() {

}

CountryState* JoinedState::changeCountryState() {
    return new JoinedState();
}

string JoinedState::requestState() {
    return "Joined";
}