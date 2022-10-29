#ifndef CPU_H
#define CPU_H

#include "Player.h"

class CPU : public Player
{
public:
    /**
     * @brief Check whether the active player will retreat in this turn
     *
     * @param turn
     * @return true
     * @return false
     */
    virtual bool playerRetreat(Battle *battle);

    /**
     * @brief Check whether the active player wants to change strategy in this turn
     *
     * @param active, the unit's whose turn it is
     * @return true if unit wants to change strategy
     * @return false if unit does not want to change strategy
     */
    virtual bool checkChangeStrategy(Unit *active);

    /**
     * @brief Checks whether active side will request reinforcements in their turn
     *
     * @return true if reinforcements will be requested
     * @return false otherwise
     */
    virtual bool requestReinforcements(Battle *battle);

protected:
    /**
     * @brief Creates new Countries and add to map country vector
     *
     */
    virtual void createCountries(Map *map) = 0;

    /**
     * @brief Allows user to choose the number of countries to join the alliance
     *
     * @return int
     */
    virtual int numberOfCountriesInAlliance(Map *map) = 0;

    /**
     * @brief Choose a country to form part of alliance
     *
     * @return Country *  to chosen country
     */
    virtual Country *chooseCountryToJoinAlliance(Map *map) = 0;

    /**
     * @brief Adds a platoon to passed in country
     *
     * @param country the country to which platoon should be added
     *
     */
    virtual void addPlatoons(Country *country) = 0;

    /**
     * @brief Adds selected factories to selected areas
     *
     */
    virtual void initialiseFactories(Map *map, Alliances *alliance) = 0;
};

#endif