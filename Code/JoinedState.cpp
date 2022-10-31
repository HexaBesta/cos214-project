#include "JoinedState.h"
#include "Director.h"
#include "Player.h"
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
    bool type = country->getPlayer()->platoonType()%2;
	cout<<"Recruiting platoons from "<<this->requestState()<<" state"<<endl;
    return director->construct(type, country);
}