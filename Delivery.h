#ifndef DELIVERY_H
#define DELIVERY_H

#include <set>

#include "Supermarket.h"
#include "GPS.h"
#include "Data.h"



class Delivery {

	supermarket origin;
	set<client> clients;
	Data data;

};

#endif