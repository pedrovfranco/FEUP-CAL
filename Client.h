#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>

#include "GPS.h"
#include "Item.h"
#include "Graph.h"


class Client {

	int id;
	std::string address; // Not used
	GPS gps;
	std::pair<long long, Vertex*> ref; // reference
	std::vector<Item> basket;

public:

	Client();
	Client(int id, double latitude, double longitude);
	Client(int id, double latitude, double longitude, std::vector<Item> items);

	void setBasket(std::vector<Item> items);

	
	void setId(const int &id);
	void setRef(GPS input);
	void setRef(const Graph &graph);

	int getId() const;
	GPS getGPS() const;
	long long getGPSId() const;

};


ostream& operator<<(ostream &os, const Client &input);

#endif