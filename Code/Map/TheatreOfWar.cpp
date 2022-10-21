#include "TheatreOfWar.h"

TheatreOfWar::TheatreOfWar(string type)
{
    this->type=type;
    this->attacker=NULL;
    this->defender=NULL;
}

TheatreOfWar::~TheatreOfWar()
{
}

Unit *TheatreOfWar::getAttacker()
{
    return this->attacker;
}
Unit *TheatreOfWar::getDefender()
{
    return this->defender;
}

void TheatreOfWar::setAttacker(Unit *attacker){
    if (this->attacker!=NULL)
    {
        this->attacker->join(attacker);
    }else{
        this->attacker=attacker;
    }
    
}
void TheatreOfWar::setDefender(Unit *defender){
    if (this->defender!=NULL)
    {
        this->defender->join(defender);
    }else{
        this->defender=defender;
    }
}

Unit* TheatreOfWar::retreat(bool turn){
    if (turn)
    {
        Unit* curr=defender;
        defender=attacker;
        attacker=NULL;
        return curr;
    }else{
        Unit* curr=attacker;
        attacker=NULL;
        return curr;
    }
    
}

string TheatreOfWar::toString(){
        string out="\tDefender:";
        if(defender!=NULL){
            out+="Yes";
        }else{
            out+="No";
        }
        out+="\tAttacker:";
        if(attacker!=NULL){
            out+="Yes";
        }else{
            out+="No";
        }

        return out;
    }

Unit* TheatreOfWar::MarchOut(bool split){
    if (split)
    {
        return defender->split();
    }else{
        Unit* curr=defender;
        defender=NULL;
        return defender;
    }
    
}