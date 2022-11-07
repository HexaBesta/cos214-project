#ifndef AMMUNITION_H
#define AMMUNITION_H

#include "Transport.h"

using namespace std;

class Ammunition : public Transport
{
    public:

    /**
     * @brief Construct a new Ammunition object with default supply 300
     * 
     * @param supply parameter to call super constructor
     */
    Ammunition(int supply = 300);

     /**
     * @brief Returns an integer containing the amount of ammo that is being returned
     *
     * @return int amount of ammo that Platoon can replenish with
     */
    virtual int replenish(bool doublePew);
};

#endif
