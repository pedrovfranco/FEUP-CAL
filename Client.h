#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>

#include "GPS.h"
#include "Item.h"
#include "Graph.h"


class Client {

	int id;
	std::string address;
	GPS gps;
	long long GPSid;
	std::vector<Item> basket;

public:

	Client();
	Client(int id, double latitude, double longitude);

	void setGPSId(const Graph &graph);

	long long getGPSId() const;
};


#endif