#ifndef THEATREOFWAR_H
#define THEATREOFWAR_H

#include "Unit.h"

class TheatreOfWar
{
private:
    Unit* defender;
    Unit* attacker;
    string type;
public:
    TheatreOfWar(string type);

    /**
     * @brief Get the Unit pointer that is in the attacker slot
     * 
     * @return Unit* 
     */
    Unit* getAttacker();

    /**
     * @brief Get the Unit pointer that is in the defender slot
     * 
     * @return Unit* 
     */
    Unit* getDefender();

    /**
     * @brief Set the Defender pointer, merging if neccesary 
     * 
     * @param attacker 
     */
    void setAttacker(Unit* attacker);

    /**
     * @brief Set the Defender pointer, merging if neccesary 
     * 
     * @param defender 
     */
    void setDefender(Unit* defender);

    /**
     * @brief Removes the attacker(false) or defender(true) based on the turn
     * 
     * @param turn the turn of the person retreating
     * @return Unit* the Unit that retreated
     */
    Unit* retreat(bool turn);

    /**
     * @brief Return the defender, or part of the defender, to move them to another area.
     * 
     * @param split whether or not unit should be split and only the split part should move
     * @return Unit* the enite defender or a portion of the defender (The portion that is returned from the split function is returned)
     */
    Unit* MarchOut(bool split);

    /**
     * @brief Return the attacker/defender to retreat to other area
     * 
     * @param side can be "attack" or "defense"
     * @return Unit* the entire Unit if exists
     */
    Unit* retreat(string side);

    /**
     * @brief sends reinforcements (currently sends entire platoon, but we should consider splitting??)
     * 
     * @return Unit* the reinforcements
     */
    Unit * sendReinforcements();

    /**
     * @brief Returns a string reprsentation of the units in the TheatreOfWar
     * 
     * @return string 
     */
    string toString(int& lineLen);

    /**
     * @brief Destroy the Theatre Of War object by detroying its attacker and defender
     * 
     */
    ~TheatreOfWar();
};




#endif