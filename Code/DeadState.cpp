#include "DeadState.h"

double DeadState::attackStrength(double damage){

    cout<<"You are dead. You cannot deal damage"<<endl;
    return 0;

}


UnitsState * DeadState::changeUnitState(){
    cout<<"You are dead. You cannot change state"<<endl;
    return this;
}


void DeadState::request(){
    cout<<"Dumm dummmm duuuuummmmmmmmmmm. You are DEAD"<<endl;
}

string DeadState::getState(){
    return "Dead";
}