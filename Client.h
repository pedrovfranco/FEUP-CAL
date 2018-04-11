#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <utility>

#include "GPS.h"
#include "Item.h"
#include "Graph.h"


class Client {

	int id;
	std::string address; // Not used
	GPS gps;
	std::pair<long long, Vertex*> ref; // reference
	std::vector<Item *> basket;

public:

	Client();
	Client(int id, double latitude, double longitude);
	Client(int id, double latitude, double longitude, std::vector<Item *> items);

	void setBasket(std::vector<Item *> items);
	vector<Item *> getBasket(){return basket;}

	void setId(const int &id);
	void setGPS(GPS input);

	void setRef(const Graph &graph);

	int getId() const;
	GPS getGPS() const;
	std::pair<long long, Vertex*> getRef() const;
	void addItem(Item * i);
		void addItems(vector<int> i);
};


ostream& operator<<(ostream &os, const Client &input);

#endif
