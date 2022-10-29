#include "CountryState.h"
#include "../Builder/Director.h"

Unit * CountryState::recruitPlatoon(Director * director, Country * country){
    cout<<"Countries that are not at war cannot make active platoons"<<endl;
    return NULL;
}