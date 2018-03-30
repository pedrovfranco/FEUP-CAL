//
// Created by Beatriz Mendes on 29/03/2018.
//

#ifndef CAL_PROJ_DELIVERYNETWORK_H
#define CAL_PROJ_DELIVERYNETWORK_H

#include "Graph.h"

#include "GPS.h"
#include <string>

class DeliveryNetwork {
	
	

public:
	Graph graph;
	bool loadGraph(std::string aname, std::string bname, std::string cname);


	Graph getGraph() const;
};


#endif //CAL_PROJ_DELIVERYNETWORK_H
