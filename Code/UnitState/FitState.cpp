#include "FitState.h"

double FitState::attackStrength(double damage){

    cout<<"You are fit and healthy. You deal full damage: "<<damage<<endl;
    return damage;

}


UnitsState * FitState::changeUnitState(){
    cout<<"(Fit -> Injured)"<<endl;
    return new InjuredState();
}


void FitState::request(){
    DeployedState::request();
    cout<<"FIT"<<endl;
}