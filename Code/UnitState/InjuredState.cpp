#include "InjuredState.h"

double InjuredState::attackStrength(double damage){

    cout<<"You are injured, you only deal half damage: "<<(damage/2)<<endl;
    return (damage/2);

}


UnitsState * InjuredState::changeUnitState(){
    cout<<"(Injured -> Dead)"<<endl;
    return new DeadState();
}


void InjuredState::request(){
    DeployedState::request();
    cout<<"INJURED"<<endl;
}