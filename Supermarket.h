#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <string>
#include <vector>

#include "Client.h"
#include "GPS.h"


class Supermarket {

	int id;
	std::string address;
	GPS gps;
	long long GPSid = -1;
	std::vector<Client> clients; // Container

public:
	Supermarket();
	Supermarket(int id, double latitude, double longitude);

	void setGPSId(const Graph &graph);

	int getId() const;
	GPS getGPS() const;
	long long getGPSId() const;

};

ostream& operator<<(ostream &os, const Supermarket &input);

#endif
