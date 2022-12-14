#ifndef ALLIANCES_H
#define ALLIANCES_H

#include <string>
#include <vector>
using namespace std;

class Country;

class Alliances {
    private:
        string name;
        int colour;
        vector<Country*> countries;

    public:
        /**
         * @brief Construct a new Alliances object
         * 
         * @param name 
         * @param colour 
         */
        Alliances(string name,int colour);
        /**
         * @brief Get the Name of the alliance
         * 
         * @return string 
         */
        string getName();

        /**
         * @brief Get the Colour of the alliance
         * 
         * @return int 
         */
        int getColour();

        /**
         * @brief Adds a country to the array of countries
         * 
         * @param country 
         */
        void addCountry(Country * country);

        /**
         * @brief Withdraws coountry from alliance by removing country from vector
         * 
         * @param country 
         */
        void withdrawCountry(Country * country);

        /**
         * @brief Accesses each country's moral, change to neureal state if moral too low
         * 
         * @return string describing changes made
         */
        string accessCountryMoral();

        /**
         * @brief Get the Countries object
         * 
         * @return vector<Country*> that holds the countries in this alliance
         */
        vector<Country*> getCountries();
};

#endif
