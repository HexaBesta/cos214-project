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
     * @brief Returns an integer value of how much PewPew ammo returned
     *
     * @return int amount of PewPew ammo
     */
    int replenishPewPew();

     /**
     * @brief Returns an integer value of how much BoomBoom ammo returned
     *
     * @return int amount of BoomBoom ammo
     */
    int replenishBoomBoom();
};

#endif
