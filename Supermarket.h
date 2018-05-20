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
	string chain;
	GPS gps;
	pair<long long, Vertex*> ref; // reference

public:
	Supermarket();
	Supermarket(int id, double latitude, double longitude);
    Supermarket(int id, double latitude, double longitude, string chain);

	void setRef(const Graph &graph);

	int getId() const;
	GPS getGPS() const;
	std::pair<long long, Vertex*> getRef() const;
	string getName() const;

};

ostream& operator<<(ostream &os, const Supermarket &input);

#endif
