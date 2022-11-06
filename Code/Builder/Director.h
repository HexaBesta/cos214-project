#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "PlatoonBuilder.h"
#include <stdexcept>

class Country;

class Director {
    private:
        BobTheBuilder* builder;
    public:
        /**
         * @brief Default constructor for the Director
         */
        Director();

        /**
         * @brief Deconstructor for the Director
         */
        ~Director();
        
    	/**
         * @brief Construct a new Platoon the builder
         * @param type represents the type of the Branch, true represents a land branch while false represents an air branch
         * @param c represents the country of the platoon
         */
        Unit* construct(bool type, Country* c);
};

#endif