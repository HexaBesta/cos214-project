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
         * @param name sets the name of the alliance
         * @param colour sets the colour (green - 22 or red - 160) attribute of the alliance
         */
        Alliances(string name,int colour);

        /**
         * @brief Get the Name of the alliance
         * 
         * @return string containing name of the alliance
         */
        string getName();

        /**
         * @brief Get the Colour of the alliance - (green - 22 or red - 160) 
         * 
         * @return int the colour of the alliance 
         */
        int getColour();

        /**
         * @brief Adds a country to the alliance by pushing the passed in parameter into the vector of countries
         * 
         * @param country 
         */
        void addCountry(Country * country);

        /**
         * @brief Withdraws coountry from alliance by removing country  of passed in parameter from vector
         * 
         * @param country to withdraw from the alliance
         */
        void withdrawCountry(Country * country);

        /**
         * @brief Accesses each country's moral, change to neutral state if moral too low
         * 
         * @return string describing changes made to the country
         */
        string accessCountryMoral();

        /**
         * @brief Retrieves the vector of countries from the alliance
         * 
         * @return vector<Country*> that holds the countries in this alliance
         */
        vector<Country*> getCountries();
};

#endif
