#ifndef PLAYER_H
#define PLAYER_H

class Battle;
class Unit;

class Player 
{
    public:
        /**
         * @brief Check whether the active player will retreat in this turn
         * 
         * @param turn 
         * @return true 
         * @return false 
         */
        virtual bool playerRetreat(Battle * battle) = 0;

        /**
         * @brief Check whether the active player wants to change strategy in this turn
         * 
         * @param active, the unit's whose turn it is 
         * @return true if unit wants to change strategy
         * @return false if unit does not want to change strategy
         */
        virtual bool checkChangeStrategy(Unit * active) = 0;

        /**
         * @brief Checks whether active side will request reinforcements in their turn
         * 
         * @return true if reinforcements will be requested
         * @return false otherwise
         */
        virtual bool requestReinforcements(Battle * battle) = 0;

        /**
         * @brief Choses a country to take a turn with
         * 
         * @param countries vector of countries of current alliance
         * @return int index of country chosen
         */
        virtual int chooseCountry(vector <Country*> countries)=0;

        /**
         * @brief choose which action player wants to take with country
         * 
         * @return int:
         *  - 0 if attack transport route
         *  - 1 if requestResource
         *  - 2 if march into area
         */
        virtual int chooseActionForCountry()=0;

        /**
         * @brief choose which area to take action in
         * 
         * @param areas list of all areas
         * @return int index of chosen 
         */
        virtual int chooseAreaForAction(vector<Area*> areas)=0;

        /**
         * @brief choose area from adjArea list
         * 
         * @param adjAreas 
         * @return int index of chosen
         */
        virtual int chooseAdjacentArea(vector<Area *> adjAreas) = 0;

        /**
         * @brief choose type of resource to request for area passed in
         * 
         * @param area 
         * @return int type of resource
         */
        virtual int chooseResource(Area * area) = 0;

};

#endif