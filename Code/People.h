#ifndef PEOPLE_H
#define PEOPLE_H

#include "Transport.h"

using namespace std;


class People : public Transport
{
    public:
        /**
         * @brief Construct a new People object
         * 
         * @param supply parameter for super constructor
         */
        People(int supply = 50);
        /**
         * @brief Returns an integer value of how much health will be improved
         * 
         * @return int - health improvement
         */
        virtual int replenish(bool doubleRep = false);

};

#endif
