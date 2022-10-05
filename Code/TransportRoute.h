#ifndef TRANSPORTROUTE_H
#define TRANSPORTROUTE_H

#include "Area.h"

using namespace std;

class TransportRoute : public MapComponent
{

	public:
		/**
		 * @brief Construct a new Transport Route object setting available to false
		 * 
		 * @note When initialised, transport routes are unavailable.
		 * 
		 */
		TransportRoute();

		/**
		 * @brief Sets the end points of the transport route
		 * 
		 * @param endPoint1 The first end point of the transport route
		 * @param endPoint2 The first end point of the transport route
		 * 
		 */
		void setEndPoints(Area* endPoint1,Area* endPoint2);

		/**
		 * @brief sets available to false, indicating that the transport route is not operational
		 * 
		 */
		void destroy();

		/**
		 * @brief sets available to true, indicating that the transport route is operational
		 * 
		 */
		void create();

private:
	Area *to;
	Area *from;
	bool available;
};

#endif
