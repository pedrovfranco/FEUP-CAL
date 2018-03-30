//
// Created by Beatriz Mendes on 29/03/2018.
//

#ifndef CAL_PROJ_DELIVERYNETWORK_H
#define CAL_PROJ_DELIVERYNETWORK_H

#include "Graph.h"
#include "GPS.h"
#include <string>
#include <unordered_set>
#include "Client.h"
#include "Supermarket.h"

class DeliveryNetwork {
	
	Graph graph;
	std::unordered_set<int, Client> clients;
	std::unordered_set<int, Supermarket> supermarkets;

public:
	
	bool loadGraph(std::string aname, std::string bname, std::string cname);


	Graph getGraph() const;
};


#endif //CAL_PROJ_DELIVERYNETWORK_H
