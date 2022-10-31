#include "Battle.h"
#include "Area.h"

Battle::Battle(TheatreOfWar *air, TheatreOfWar *land, Area *area, Player *player)
{

	this->air = air;
	this->land = land;
	this->area = area;
	this->player = player;
	this->battleActive = true;
	this->turn = true;
}

void Battle::battleLoop()
{
	while (this->battleActive)
	{
		if(this->checkRetreat()){
			this->battleActive = false;
			break;
		}
		this->takeTurn();
		this->turn = (this->turn + 1) % 2;
		this->getStateSummary();
	}
}

bool Battle::checkRetreat()
{
	if (this->turn)
	{
		if (this->player->playerRetreat(this))
		{
			return this->area->retreat("attack");
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (this->player->playerRetreat(this))
		{
			return this->area->retreat("defense");
		}
		else
		{
			return false;
		}
	}
}

void Battle::setAttackerToDefender(){
	Unit * oldAttacker = this->air->getAttacker();
	Unit * oldDefender = this->air->getDefender();
	if(oldAttacker != NULL){
		if(oldDefender){
			this->area->retreat("defense");
		}
		this->air->setDefender(oldAttacker);
		this->air->setAttacker(NULL);
	}
	oldAttacker = this->land->getAttacker();
	oldDefender = this->land->getDefender();
	if(oldAttacker != NULL){
		if(oldDefender){
			this->area->retreat("defense");
		}
		this->land->setDefender(oldAttacker);
		this->land->setAttacker(NULL);
	}

}

TheatreOfWar * Battle::getAir(){
	return this->air;
}

TheatreOfWar * Battle::getLand(){
	return this->land;
}

bool Battle::getTurn(){
	return this->turn;
}

void Battle::getStateSummary()
{
	cout << "-------------------------------------------" << endl;
	cout << "\tPrinting Summary of State of Battle:" << endl;
	cout << endl;
	cout << "Turn: ";
	if (!this->turn)
	{
		cout << "Defender" << endl;
	}
	else
	{
		cout << "Attacker" << endl;
	}
	cout << "Area: " << endl;
	cout<<this->area->toString();
	// cout << "Defender:" << endl;
	// if(this->air->getDefender()){
	// 	cout<<this->air->getDefender()->toString()<<endl;
	// }
	// if(this->land->getDefender()){
	// 	cout<<this->land->getDefender()->toString()<<endl;
	// }

	// cout << "Attacker:" << endl;

	// if(this->air->getAttacker()){
	// 	cout<<this->air->getAttacker()->toString()<<endl;
	// }
	// if(this->land->getAttacker()){
	// 	cout<<this->land->getAttacker()->toString()<<endl;
	// }

	// cout << endl;
	cout << "-------------------------------------------" << endl;
}

void Battle::takeTurn()
{

	Unit * active = NULL;
	Unit * passive = NULL;

	/*
	Get current active (initiate attack) and passive (take damage)
	*/
	if(this->turn){
		//Attacker in air
		if(this->air->getAttacker()  && (!this->air->getAttacker()->getState().compare("Dead") == 0 )){
			
			active = this->air->getAttacker();

			//Defender in air
			if(this->air->getDefender() && (!this->air->getDefender()->getState().compare("Dead")  == 0 )){
				passive = this->air->getDefender();
			}
			//Defender on land
			else if(this->land->getDefender()  && (!this->land->getDefender()->getState().compare("Dead")  == 0 )){
				passive = this->land->getDefender();
			}
			//No defender
			else{
				this->battleActive = false;
				this->setAttackerToDefender();
			}

		}
		//attacker on land
		else if(this->land->getAttacker()  && (!this->land->getAttacker()->getState().compare("Dead")  == 0 )){
			active = this->land->getAttacker();
			//Defender on land
			if(this->land->getDefender() && (!this->land->getDefender()->getState().compare("Dead")  == 0 )){
				passive = this->land->getDefender();
			}
			//No defender
			else if (!(this->air->getDefender()  && (!this->air->getDefender()->getState().compare("Dead")  == 0 ))){
				this->battleActive = false;
			}
			//If there is only an air defender - request reinforcements
			else{
				
				if(!this->area->requestReinforcements("attack")){
					this->area->retreat("attack");
				}	
				cout<<"------------------------------------------"<<endl<<endl;
				
			}
		}
		//No attacker left
		else{
			this->battleActive = false;
		}
	}
	//Defender active
	else{
		//Defender in air
		if(this->air->getDefender()  && (!this->air->getDefender()->getState().compare("Dead")  == 0 )){
			
			active = this->air->getDefender();

			//Attacker in air
			if(this->air->getAttacker()  && (!this->air->getAttacker()->getState().compare("Dead")  == 0 )){
				passive = this->air->getAttacker();
			}
			//Attacker on land
			else if(this->land->getAttacker()  && (!this->land->getAttacker()->getState().compare("Dead")  == 0 )){
				passive = this->land->getAttacker();
			}
			//No attacker
			else{
				this->battleActive = false;
			}

		}
		//defender on land
		else if(this->land->getDefender()  && (!this->land->getDefender()->getState().compare("Dead")  == 0 )){
			active = this->land->getDefender();
			//Attacker on land
			if(this->land->getAttacker() && (!this->land->getAttacker()->getState().compare("Dead")  == 0 )){
				passive = this->land->getAttacker();
			}
			//No Attacker
			else if (!(this->air->getAttacker()  && (!this->air->getAttacker()->getState().compare("Dead")  == 0 ))){
				this->battleActive = false;
			}
			//If there is only an air attacker - request reinforcements
			else{
				
				if(!this->area->requestReinforcements("defense")){
					if(this->area->retreat("defense")){
						cout<<this->land->getDefender()->getCountry()->getName()<<" retreating"<<endl;
					}else{
						cout<<this->land->getDefender()->getCountry()->getName()<<" has nowhere to go... They screwed"<<endl;
					}
				}
				
			}
		}
		//No defender left
		else{
			this->battleActive = false;
			this->setAttackerToDefender();
		}
	}

	//If one side no longer has troops/active side only had land against air
	if(this->battleActive == false ||  passive == NULL){
		return;
	}

	/*
	Change strategy: Ask user input to check if strategy change necessary
	*/
	std::cout<<"------------------------------------------"<<endl;
	this->changeStrategy(active);
	std::cout<<"------------------------------------------"<<endl<<endl;

	/*
	Attack!
	*/
	this->attack(active, passive);

	/*
	Print active platoon after attack
	*/

	std::cout<< active->toString()<<endl;

	/*
	Request reinforcements after printing state of platoon if battle active.
	*/

	if (battleActive)
	{
		if (this->requestReinforcements())
		{
			std::cout << "Reinforcements have arrived" << endl;
		}
		else
		{
			std::cout << "There will be no reinforcements coming" << endl;
		}
	}

	std::cout<<"------------------------------------------"<<endl;
	std::cout << "END OF TURN" <<endl
		 << "################################################" << endl<<endl;
}

bool Battle::requestReinforcements()
{
	std::cout<<"------------------------------------------"<<endl;
	if(this->player->requestReinforcements(this)){
		
			if(this->turn){
				return this->area->requestReinforcements("attack");
					
			}
			else{
				return this->area->requestReinforcements("defense");
			}
		
	}else{
		return false;
	}
}

void Battle::changeStrategy(Unit * active)
{

	if (this->player->checkChangeStrategy(active))
	{
		//cout<<"Add in call to unit change strategy Battle 299"<<endl;
		active->changeStrategy();
	}
}

void Battle::attack(Unit * active, Unit * passive)
{
	active->attack(passive);

	//std::cout<<passive->getState()<<endl;
	if(passive->getState().compare("Dead")==0){
		passive = NULL;
		this->battleActive = false;
	}
	
}