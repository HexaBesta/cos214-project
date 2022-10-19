#ifndef ALLIANCES_H
#define ALLIANCES_H

#include <string>
using namespace std;

class Alliances {
    private:
        string name;

    public:
        /**
         * @brief Get the Name of the alliance
         * 
         * @return string 
         */
        string getName(){return name;};
};

#endif
