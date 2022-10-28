#ifndef ALLIANCES_H
#define ALLIANCES_H

#include <string>
using namespace std;

class Alliances {
    private:
        string name;
        int colour;

    public:
        /**
         * @brief Construct a new Alliances object
         * 
         * @param name 
         * @param colour 
         */
        Alliances(string name,int colour)
        {
            this->name = name;
            this->colour=colour;
        };
        /**
         * @brief Get the Name of the alliance
         * 
         * @return string 
         */
        string getName(){
            return name;
        };

        /**
         * @brief Get the Colour of the alliance
         * 
         * @return int 
         */
        int getColour(){
            return colour;
        };
};

#endif
