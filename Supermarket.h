#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <string>
#include <vector>
#include <utility>

#include "Client.h"
#include "GPS.h"
#include "Graph.h"


class Supermarket {

	int id;
	std::string address;
	GPS gps;
	std::pair<long long, Vertex*> ref; // reference
	//std::vector<Client> clients; // Container
	std::priority_queue<Client*> clients;

public:
	Supermarket();
	Supermarket(int id, double latitude, double longitude);

	void setRef(const Graph &graph);

	int getId() const;
	GPS getGPS() const;
	std::pair<long long, Vertex*> getRef() const;

};

ostream& operator<<(ostream &os, const Supermarket &input);

#endif
