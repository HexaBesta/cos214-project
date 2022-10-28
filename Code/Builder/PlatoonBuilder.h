#ifndef PLATOONBUILDER_H
#define PLATOONBUILDER_H

#include "BobTheBuilder.h"
#include "../Unit/Human.h"
#include "../Unit/Vehicle.h"
#include "../Branches/LandBranch.h"
#include "../Branches/AirBranch.h"
#include "../Platoon/Platoon.h"

#include <time.h>

using namespace std;

class PlatoonBuilder : public BobTheBuilder {
    public:
    	/**
		 * @brief Creates new vehicles for the platoon.
		 */
        virtual void createVehicles();

        /**
		 * @brief Creates new soldiers for the platoon.
		 */
        virtual void createSoldiers();

        /**
		 * @brief Creates the ammo for the platoon.
		 */
        virtual void createAmmo();

        /**
		 * @brief Creates new vehicles for the platoon.
		 * @param c represents the country of the platoon
		 */
        virtual void setCountry(Country* c);

        /**
		 * @brief Creates new vehicles for the platoon.
		 * @param type represents the type of the Branch, true represents a land branch while false represents an air branch
		 */
        virtual void setBranch(bool type);

        /**
		 * @brief Creates the platoon.
		 */
        virtual void createPlatoon();

        /**
		 * @brief Function to return the platoon.
		 * @return a platoon of type unit
		 */
        virtual Unit* getPlatoon();

		/**
		 * @brief Resets the builder.
		 */
        virtual void clearBuilder();
    private:
        vector<Unit*> vehicles;
        vector<Unit*> soldiers;
        int ammo[2] = {0,0};
        Country* country;
        Branch* branch;
        Unit* platoon;
};

#endif

// setCountry
// makePeople -> createSoldiers
// makeVehicles -> createVehicles
// makePlatoon -> createPlatoon
// setBranch -> setBranch
// getPlatoon -> getPlatoon
