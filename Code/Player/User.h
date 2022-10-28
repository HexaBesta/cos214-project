#ifndef USER_H
#define USER_H

#include "Player.h"

class User : public Player
{
    public:
        /**
         * @brief Check whether the active player will retreat in this turn
         * 
         * @param turn 
         * @return true 
         * @return false 
         */
        virtual bool playerRetreat(Battle * battle);

        /**
         * @brief Check whether the active player wants to change strategy in this turn
         * 
         * @param active, the unit's whose turn it is 
         * @return true if unit wants to change strategy
         * @return false if unit does not want to change strategy
         */
        virtual bool checkChangeStrategy(Unit * active);

        /**
         * @brief Checks whether active side will request reinforcements in their turn
         * 
         * @return true if reinforcements will be requested
         * @return false otherwise
         */
        virtual bool requestReinforcements(Battle * battle);

        /**
         * @brief Choses a country to take a turn with
         * 
         * @param countries vector of countries of current alliance
         * @return int index of country chosen
         */
        virtual int chooseCountry(vector <Country*> countries);

        /**
         * @brief choose which action player wants to take with country
         * 
         * @return int:
         *  - 0 if attack transport route
         *  - 1 if requestResource
         *  - 2 if march into area
         */
        virtual int chooseActionForCountry();

        /**
         * @brief choose which area to take action in
         * 
         * @param areas list of all areas
         * @return int index of chosen 
         */
        virtual int chooseAreaForAction(vector<Area*> areas);

        /**
         * @brief choose area from adjArea list
         * 
         * @param adjAreas 
         * @return int index of chosen
         */
        virtual int chooseAdjacentArea(vector<Area *> adjAreas);

        /**
         * @brief choose type of resource to request for area passed in
         * 
         * @param area 
         * @return int type of resource
         */
        virtual int chooseResource(Area * area);
};

#endif