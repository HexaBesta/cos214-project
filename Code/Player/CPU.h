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

};

#endif