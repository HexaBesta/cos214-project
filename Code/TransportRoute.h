#ifndef TRANSPORTROUTE_H
#define TRANSPORTROUTE_H
#include "Area.h"
#include "Visitor.h"
#include "MapComponent.h"
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
		 * @brief returns whether or not the transport route is available
		 * 
		 * @return true if the transport route is available
		 * @return false if the transport route is not available
		 */
		bool isAvailable();

		/**
		 * @brief accept visitor 
		 * 
		 * @param visitor takes in the pointer visitor that will be accpeted
		 */

		virtual void accept(Visitor* visitor);
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

		/**
		 * @brief Get the From object
		 * 
		 * @return Area* 
		 */
		Area* getFrom();

		/**
		 * @brief Get the To object
		 * 
		 * @return Area* 
		 */
		Area* getTo();

		/**
		 * @brief Destroy the Transport Route object
		 * 
		 */
		virtual ~TransportRoute();

private:
	Area *to;
	Area *from;
	bool available;
};

#endif
