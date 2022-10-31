#ifndef TRANSPORT_H
#define TRANSPORT_H


// C++ program to generate random numbers
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

class Transport
{
protected:
	/**
	 * @brief Supply is the amount of products left
	 *
	 */
	int supply;

	/**
	 * @brief Get the Amount of ammo/morale/health to return
	 * 
	 * @return int amount
	 */
	int getAmount();

public:
	/**
	 * @brief Construct a new Transport object
	 *
	 * @param supply initialises the transport supply
	 */
	Transport(int supply);
	/**
	 * @brief checks whether there is still supplies left
	 *
	 * @return true if supply is 0
	 * @return false otherwise
	 */
	virtual bool isEmpty();
};

#endif
