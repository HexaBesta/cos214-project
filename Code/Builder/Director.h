#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "BobTheBuilder.h"
#include "../Country/Country.h"
#include "../Unit/Unit.h"

class Director {
    private:
        BobTheBuilder* builder;
    public:
    	/**
         * @brief Construct a new Platoon the builder
         * @param type represents the type of the Branch, true represents a land branch while false represents an air branch
         * @param c represents the country of the platoon
         */
        Unit* construct(bool type, Country* c);
};

#endif