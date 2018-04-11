//
// Created by Beatriz Mendes on 29/03/2018.
//

#ifndef CAL_PROJ_DELIVERYNETWORK_H
#define CAL_PROJ_DELIVERYNETWORK_H

#include "Graph.h"
#include "GPS.h"
#include <string>
#include <vector>
#include <map>
#include "Client.h"
#include "Supermarket.h"
#include "graphviewer.h"
#include <utility>
#include "Delivery.h"

#include <vector>
class DeliveryNetwork {

	Graph graph;
	GraphViewer *gv = NULL;

	std::map<int, Client*> clients;
	std::map<int, Supermarket*> supermarkets;
	std::vector<Delivery *> deliveries;
	std::vector<Item *> items;

public:

	bool loadGraph(std::string aname, std::string bname, std::string cname);
	bool loadViewer(std::string aname, std::string bname, std::string cname);
	bool loadClients(std::string filename);
	bool loadSupermarkets(std::string filename);
	bool loadItems(string filename);

	void showPath(const long long &startid, const long long &endid);
	void showPath(std::vector<long long> v);
	void printClients() const;
	void printSupermarkets() const;

	Client * clientExists(int id);
		Item * itemExists(int id);
	void addDelivery(Delivery * d);
	void placeOrder(int clientID, Data date);
	void printItems();
	void popDelivery();

	Graph getGraph() const;
	GraphViewer* getGV() const;
	std::map<int, Client*> getClients() const;
	std::map<int, Supermarket*> getSupermarkets() const;
	void loadDeliveries();
	void showDeliveries();
	void makeDelivery();



	void deleteGV();
};


#endif //CAL_PROJ_DELIVERYNETWORK_H
