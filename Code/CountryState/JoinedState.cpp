#include "JoinedState.h"
using namespace std;

void JoinedState::handleCountry() {
    cout << "You have joined the war!" << endl;
}

CountryState* JoinedState::changeCountryState() {
    return new JoinedState();
}

string JoinedState::requestState() {
    return "Joined";
}