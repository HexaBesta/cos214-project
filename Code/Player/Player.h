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

};

#endif