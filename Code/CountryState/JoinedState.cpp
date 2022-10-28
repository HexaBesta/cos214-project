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

Unit * JoinedState::recruitPlatoon(Director * director, Country * country){
    srand(time(NULL));
    bool type = rand()%2;
    return director->construct(type, country);
}