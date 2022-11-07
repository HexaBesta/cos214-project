#include "WithdrawnState.h"

using namespace std;

void WithdrawnState::handleCountry()
{
    cout << "You have withdrawn from this was and no longer exist as a country..." << endl;
}

CountryState *WithdrawnState::changeCountryState()
{
    return new WithdrawnState();
}

string WithdrawnState::requestState()
{
    return "Withdrawn";
}