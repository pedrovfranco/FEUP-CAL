#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>

#include "GPS.h"
#include "item.h"


class client {

	int id;
	std::string name;
	unsigned int age;
	std::string address;
	GPS gps;
	std::vector<item> basket;

public:

	client();
	client(int id, std::string name, unsigned int age, std::string address, double latitude, double longitude);
};


#endif