#include "TheatreOfWar.h"
#include "Transport.h"

TheatreOfWar::TheatreOfWar(string type)
{
    this->type = type;
    this->attacker = NULL;
    this->defender = NULL;
}

Unit *TheatreOfWar::getAttacker()
{
    return this->attacker;
}
Unit *TheatreOfWar::getDefender()
{
    return this->defender;
}

void TheatreOfWar::setAttacker(Unit *attacker)
{
    if(attacker==nullptr){
        this->attacker = nullptr;
        return;
    }
    if (this->attacker != NULL)
    {
        this->attacker->join(attacker);
    }
    else
    {
        this->attacker = attacker;
    }
}
void TheatreOfWar::setDefender(Unit *defender)
{
    if (this->defender != NULL && this->defender->getState().compare("Dead")!=0)
    {
        this->defender->join(defender);
    }
    else
    {
        this->defender = defender;
    }
}

Unit *TheatreOfWar::retreat(bool turn)
{
    if (turn)
    {
        Unit *curr = defender;
        defender = attacker;
        attacker = NULL;
        return curr;
    }
    else
    {
        Unit *curr = attacker;
        attacker = NULL;
        return curr;
    }
}

string TheatreOfWar::toString(int &lineLen)
{
    string out = "";
    string add = "|                   Defender:";
    while (add.length() < lineLen)
    {
        add += " ";
    }
    add += "|\n";
    out += add;

    if (defender != NULL)
    {
        add = "" + defender->toString(lineLen);
        out+=add+"\n";
    }
    else
    {
        add = "|                        None";
        while (add.length() < lineLen)
        {
            add += " ";
        }
        add += "|\n";
        out += add;
    }

    //Skip Line
	add= "|";
	for (int i = 0; i < lineLen - 1; i++)
		add += " ";
	add += "|\n";
    out+= add;

    add = "|                   Attacker:";
    while (add.length() < lineLen)
    {
        add += " ";
    }
    add += "|\n";
    out += add;

    if (attacker != NULL)
    {
        add =  attacker->toString(lineLen);
       
        out += add+"\n";
    }
    else
    {
        add = "|                        None";
        while (add.length() < lineLen)
        {
            add += " ";
        }
        add += "|\n";
        out += add;
    }

    return out;
}

Unit *TheatreOfWar::MarchOut(bool split)
{
    if (split)
    {
        return defender->split();
    }
    else
    {
        Unit *curr = defender;
        defender = NULL;
        return curr;
    }
}

Unit *TheatreOfWar::retreat(string side)
{
    if (side.compare("defense") == 0)
    {
        Unit *curr = defender;
        defender = NULL;
        if (attacker != NULL)
        {
            defender = attacker;
        }
        return curr;
    }
    else if (side.compare("attack") == 0)
    {
        Unit *curr = attacker;
        attacker = NULL;
        return curr;
    }
    else
    {
        return NULL;
    }
}

Unit *TheatreOfWar::sendReinforcements()
{
    if (this->defender != NULL)
    {
        Unit *curr = defender;
        defender = NULL;
        return curr;
    }
    return NULL;
}

void TheatreOfWar::replenish(Transport** good){
    if(this->defender!= NULL){
        this->defender->replenish(good);
    }
}

TheatreOfWar::~TheatreOfWar()
{
    cout<<"Deleting TheatreOfWar"<<endl;
}