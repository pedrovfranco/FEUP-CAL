#ifndef DELIVERY_H
#define DELIVERY_H

#include <set>

#include "supermarket.h"
#include "GPS.h"

class delivery {

	supermarket origin;
	std::set<client> clients;

};

#endif