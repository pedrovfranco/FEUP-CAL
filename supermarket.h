#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <string>
#include <vector>

#include "client.h"
#include "GPS.h"


class supermarket {

	int id;
	std::string name;
	GPS gps;
	std::vector<client> clients; // Container 

	supermarket();
	supermarket(int id, std::string name, double latitude, double longitude);

};


#endif