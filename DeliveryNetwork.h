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


class DeliveryNetwork {
	
	Graph graph;
	GraphViewer *gv = NULL;

	std::map<int, Client*> clients;
	std::map<int, Supermarket*> supermarkets;

public:
	
	bool loadGraph(std::string aname, std::string bname, std::string cname);
	bool loadViewer(std::string aname, std::string bname, std::string cname);
	bool loadClients(std::string filename);
	bool loadSupermarkets(std::string filename);

	void showPath(const long long &startid, const long long &endid);
	void showPath(std::vector<long long> v);
	void printClients() const;
	void printSupermarkets() const;

	Graph getGraph() const;
	GraphViewer* getGV() const;
	std::map<int, Client*> getClients() const;
	std::map<int, Supermarket*> getSupermarkets() const;

	void deleteGV();
};


#endif //CAL_PROJ_DELIVERYNETWORK_H
