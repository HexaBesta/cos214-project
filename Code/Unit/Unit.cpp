#include "Unit.h"

Unit::Unit() {
	
}

Unit::Unit(int health, int moral, int damage, Country* country, bool fitState){
	this->health = health;
	this->moral = moral;
	this->damage = damage;
	this->country = country;
	if(fitState){
		this->unitState = new FitState();
	}else{
		this->unitState = new CivilianState();
	}
}

void Unit::requestState() {
	if(this->unitState != NULL)
		this->unitState->request();
}

string Unit::getState(){
	if(this->unitState != NULL){
		return this->unitState->getState();
	}
	return "";
}

void Unit::setUnitState(UnitsState * unitState) {
	if(unitState == nullptr){
		this->unitState = this->unitState->changeUnitState();
	}else{
		delete this->unitState;
		this->unitState = unitState;
	}
	
}

void Unit::changeStrategy(){
	cout<<"This unit type cannot change strategy"<<endl;
}

int Unit::getDamage(){
	return this->damage;
}

int Unit::getHealth(){
	return this->health;
}

int Unit::getSize(){
	return 1;
}

void Unit::setHealth(int healthhhh){
	this->health = healthhhh;
}

void Unit::setMoral(int moral){
	this->moral = moral;
}

int Unit::getMoral(){
	return this->moral;
}


bool Unit::takeDamage(int damage, bool checkStrat) {
	this->health = this->health - damage;
	if(this->health <= 0 ){
		this->setUnitState(new DeadState());
		return true;
	}
	return false;
}

 Unit*  Unit::split(){return NULL;}


void  Unit::join(Unit* others){}

string Unit::getBranch(){
	return "NotAClue";
}

string Unit::getAlliance(){
	return country->getAlliances()->getName();
}

void Unit::setCountry(Country* country){
	this->country = country;
}

Country* Unit::getCountry(){
    return this->country;
}

string Unit::toString(int lineLen){
	
	return "Add unit print statement";
}

Unit* Unit::takeRandom(){
	return this;
}

int * Unit::getAmmo(){
	return NULL;
}

Unit::~Unit(){
	
	delete this->unitState;
    //delete this->country;
}


