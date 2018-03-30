#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>

#include "GPS.h"
#include "Item.h"


class Client {

	int id;
	std::string name;
	unsigned int age;
	std::string address;
	GPS* gps;
	std::vector<Item> basket;

public:

	Client();
	Client(int id, std::string name, unsigned int age, std::string address, double latitude, double longitude);
};


#endif