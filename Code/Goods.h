#ifndef GOODS_H
#define GOODS_H
#include "Transport.h"
using namespace std;

class Goods : public Transport
{
public:
    /**
     * @brief Construct a new Goods object
     * 
     * @param supply parameter for super constructor
     */
    Goods(int supply = 50);
    /**
     * @brief Returns an integer value of how much health will be improved
     *
     * @return int - health improvement
     */
    int replenish(bool doubleRep);
};

#endif
