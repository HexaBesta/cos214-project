#include "CountryState.h"
#include "Director.h"

class Player;

Unit * CountryState::recruitPlatoon(Director * director, Country * country, Player * player){
    cout<<"Countries that are not at war cannot make active platoons"<<endl;
    return NULL;
}