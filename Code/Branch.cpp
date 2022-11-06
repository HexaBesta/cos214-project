#include "Branch.h"

Branch::Branch(Unit *unit) : Unit()
{
	this->unit = unit;
}

void Branch::attack(Unit *pl)
{
	this->unit->attack(pl);
}

void Branch::requestState()
{
	this->unit->requestState();
}

void Branch::setUnitState(UnitsState *unitS)
{
	this->unit->setUnitState(unitS);
}

void Branch::setCountry(Country* c){
	this->unit->setCountry(c);
}

Country* Branch::getCountry(){
	return this->unit->getCountry();
}

string Branch::getAlliance(){
	return this->unit->getAlliance();
}

string Branch::getState()
{
	if (this->unit != NULL)
	{
		return this->unit->getState();
	}
	return "";
}

bool Branch::takeDamage(int damage, bool pewpew)
{
	return this->unit->takeDamage(damage, pewpew);
}

int Branch::getSize()
{
	return this->unit->getSize();
}

string Branch::getBranch()
{
	return "BRANCH";
}

int *Branch::getAmmo()
{
	return this->unit->getAmmo();
}

string Branch::getStrategyType()
{
	return this->unit->getStrategyType();
}

void Branch::changeStrategy()
{
	this->unit->changeStrategy();
}

int Branch::getMoral()
{
	return this->unit->getMoral();
}

int Branch::getHealth()
{
	return this->unit->getHealth();
}

string Branch::toString(int lineLen)
{
	return this->unit->toString(lineLen);
}

void Branch::join(Unit *others){
	if(this->unit != NULL){
		this->unit->join(others);
	}
}

Unit * Branch::getUnit(){
	return this->unit->getUnit();
}

void Branch::setTexture(){
	cout<<"Not you either"<<endl;
}

 sf::Sprite* Branch::getSprite(){
	return this->unit->getSprite();
}

void Branch::setTextLocation(int x,int y){
	this->unit->setTextLocation(x,y);
}

void Branch::draw(sf::RenderWindow* r){
	this->unit->draw(r);
}

void Branch::replenish(Transport ** transport){
	if(this->unit != NULL){
		this->unit->replenish(transport);
	}
}

Branch::~Branch(){
	delete this->unit;
}