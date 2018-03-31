#include <iostream>
#include "DeliveryNetwork.h"
#include "Client.h"

using namespace std;

int main()
{

	DeliveryNetwork network;
	network.loadGraph("input/a.txt", "input/b.txt", "input/c.txt");


	GPS start(41.178729, -8.599751);

	GPS end(41.177195999999995, -8.599632);


	cout << network.getGraph().dijkstra(network.getGraph().getClosestGPS(start).first, network.getGraph().getClosestGPS(end).first) << "\n";

    return 0;
}