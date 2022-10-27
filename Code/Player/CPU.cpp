#include "CPU.h"

bool CPU::playerRetreat(Battle* battle){
    battle->getStateSummary();
    if(battle->turn){
        if(battle->air->getAttacker()->getHealth()<=500){
            return true;
        }else if(battle->land->getAttacker()->getHealth()<=500){
            return true;
        }else{
            return false;
        }
    }else{
        if(battle->air->getDefender()->getHealth()<=500){
            return true;
        }else if(battle->land->getDefender()->getHealth()<=500){
            return true;
        }else{
            return false;
        }
    }
}

bool CPU::checkChangeStrategy(Unit* active){
    
}