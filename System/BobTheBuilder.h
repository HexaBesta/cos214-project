#ifndef BOBTHEBUILDER_H
#define BOBTHEBUILDER_H

class Unit;
class Country;

#include <vector>

using namespace std;

class BobTheBuilder {
	public:

		/**
		 * @brief Creates new vehicles for the platoon. This is a pure virtual function.
		 */
		virtual void createVehicles() = 0;

		/**
		 * @brief Creates new soldiers for the platoon. This is a pure virtual function.
		 */
		virtual void createSoldiers() = 0;

		/**
		 * @brief Creates the ammo for the platoon. This is a pure virtual function.
		 */
		virtual void createAmmo() = 0;

		/**
		 * @brief Creates new vehicles for the platoon. This is a pure virtual function.
		 * @param c represents the country of the platoon
		 */
		virtual void setCountry(Country* c) = 0;

		/**
		 * @brief Creates new vehicles for the platoon. This is a pure virtual function.
		 * @param type represents the type of the Branch, true represents a land branch while false represents an air branch
		 */
		virtual void setBranch(bool type) = 0;

		/**
		 * @brief Creates the platoon. This is a pure virtual function.
		 */
		virtual void createPlatoon() = 0;

		/**
		 * @brief Function to return the platoon. This is a pure virtual function.
		 * @return a platoon of type unit
		 */
		virtual Unit* getPlatoon() = 0;

		/**
		 * @brief Resets the builder. This is a pure virtual function.
		 */
		virtual void clearBuilder() = 0;
};

#endif
