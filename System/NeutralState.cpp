#include "NeutralState.h"
using namespace std;

void NeutralState::handleCountry()
{
    cout << "You are neutral in this war." << endl;
}

CountryState *NeutralState::changeCountryState()
{
    return new NeutralState();
}

string NeutralState::requestState()
{
    return "Neutral";
}