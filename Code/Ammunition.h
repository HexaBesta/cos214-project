#ifndef AMMUNITION_H
#define AMMUNITION_H

#include "Transport.h"

using namespace std;

class Ammunition : public Transport
{
    public:

    /**
     * @brief Construct a new Ammunition object
     * 
     * @param supply parameter to call super constructor
     */
    Ammunition(int supply = 150);
     /**
     * @brief Returns an integer value of how much to return
     *
     * @return int amount of ammo
     */
    virtual int replenish(bool doublePew = false);
};

#endif
