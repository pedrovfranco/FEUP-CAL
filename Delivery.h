#ifndef DELIVERY_H
#define DELIVERY_H

#include <set>

#include "Supermarket.h"
#include "GPS.h"
#include "Data.h"



class Delivery {

	Supermarket origin;
	set<Client> clients;
	Data data;

};

#endif