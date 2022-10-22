#include "CivilianState.h"

double CivilianState::attackStrength(double damage) {
    cout<<"You are a civilian, lacking the proper training to deal full damage. You deal: "<<(damage/3)<<" of "<<damage<<endl;
    return (damage/3);
}


UnitsState * CivilianState::changeUnitState() {
    cout<<"(Civilian -> Fit)"<<endl;
    return new FitState();
}


void CivilianState::request() {
    cout<<"CIVILIAN"<<endl;
}

string CivilianState::getState(){
    return "Civilian";
}