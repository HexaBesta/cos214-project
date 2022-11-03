#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Battle;
class Unit;
class Country;
class Area;
class Alliances;
class Map;

using namespace std;

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
        virtual int chooseCountry(vector<Country*> countries, Map* map)=0;

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
         * @brief choose two areas to destroy transport routes between
         * 
         * @param adjAreas of immediatly adjacent area
         * @return int array with index 0 containing the first array index and index 1 the second array index of chosen
         */
        virtual int* chooseAreasToDestroyTransportRoutes(vector<Area *> adjAreas, vector<vector<Area*>> otherAdj, Area * current = nullptr) = 0;

        /**
         * @brief choose type of resource to request for area passed in
         * 
         * @param area 
         * @return int type of resource
         */
        virtual int chooseResource(Area * area) = 0;

        /**
         * @brief Check whether to change from CPU->User or User->CPU
         * 
         * @return true if change should occur
         * @return false otherwise
         */
        virtual bool changePlayer() = 0;

        /**
         * @brief Change between player types
         * 
         * @return Player* new player object
         */
        virtual Player * togglePlayer() = 0;

        /**
         * @brief Template method to populate map
         * 
         * @param side1 
         * @param side2 
         */
        virtual void initialise(Alliances * side1, Alliances * side2, Map* map);

        /**
         * @brief Template method to get all input needed to populate Alliance
         * 
         */
        virtual void initialiseSide(Alliances * alliance, Map * map);

        /**
         * @brief Allow users to inspect areas
         * 
         * @param map 
         */
        virtual void inspect(Map * map);

        /**
         * @brief Asks Player whether it should create Air or Land Platoon
         * 
        */
       virtual int platoonType()=0;

        /**
         * @brief Destroy the Player object
         * 
         */
        virtual ~Player(){};

    

    protected:

        /**
         * @brief Creates new Countries and add to map country vector
         * 
         */
        virtual void createCountries(Map * map) =0;

        /**
         * @brief Allows user to choose the number of countries to join the alliance
         * 
         * @return int 
         */
        virtual int numberOfCountriesInAlliance(Map * map)=0;

        /**
         * @brief Choose a country to form part of alliance
         * 
         * @return Country *  to chosen country
         */
        virtual Country* chooseCountryToJoinAlliance(Map * map) = 0;

        /**
         * @brief Adds a platoon to passed in country
         * 
         * @param country the country to which platoon should be added
         * 
         */
        virtual void addPlatoons(Country * country, Map* map)=0;

        /**
         * @brief Adds selected factories to selected areas
         * 
         */
        virtual void initialiseFactories(Map * map, Alliances * alliance)=0;


};

#endif