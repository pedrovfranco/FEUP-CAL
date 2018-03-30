//
// Created by Beatriz Mendes on 29/03/2018.
//

#ifndef CAL_PROJ_DELIVERYNETWORK_H
#define CAL_PROJ_DELIVERYNETWORK_H

#include "Graph.h"

#include "GPS.h"
#include <string>

class DeliveryNetwork {
	Graph graph;


public:
	bool loadGraph(std::string aname, std::string bname, std::string cname);

};


#endif //CAL_PROJ_DELIVERYNETWORK_H
