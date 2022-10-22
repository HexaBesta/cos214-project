#include "../Battle/Battle.h"
#include "User.h"

bool User::playerRetreat(Battle * battle){
    battle->getStateSummary();

    int resp;
	cout << "Retreat" << endl
		 << "1. Yes \n2. Not necessary" << endl;
	cin >> resp;

    // clear buffer
	cin.ignore(30, '\n');

    if(resp == 1){
        return true;
    }
    else{
        return false;
    }
}

bool User::checkChangeStrategy(Unit * active){
    //active->print();
    int resp;
    cout << "Change Strategy" << endl
		 << "1. Yes \n2. Not necessary" << endl;
	cin >> resp;

    cin.ignore(30, '\n');

    if(resp == 1){
        return true;
    }
    else{
        return false;
    }
}

bool User::requestReinforcements(Battle * battle){

    battle->getStateSummary();
    int resp;
	cout << "Request Reinforcements" << endl
		 << "1. Yes \n2. Not necessary" << endl;
	cin >> resp;

    // clear buffer
	cin.ignore(30, '\n');

    if(resp == 1){
        return true;
    }
    else{
        return false;
    }
}