#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <string>
#include <vector>

#include "Client.h"
#include "GPS.h"


class Supermarket {

	int id;
	string name;
	GPS gps;
	vector<Client> clients; // Container

	Supermarket();
	Supermarket(int id, std::string name, double latitude, double longitude);

};


#endif