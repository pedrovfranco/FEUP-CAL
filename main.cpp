#include <iostream>
#include "DeliveryNetwork.h"
#include "Client.h"

using namespace std;

int main()
{
	cout.precision(10);

	DeliveryNetwork network;
	network.loadGraph("input/a.txt", "input/b.txt", "input/c.txt");


	GPS start(41.178729, -8.599751);
	GPS foo = network.getGraph().getClosestGPS(start).second->getInfo();

	GPS end(41.177195999999995, -8.599632);
	GPS bar = network.getGraph().getClosestGPS(end).second->getInfo();

	cout << foo << "\n" << bar << "\n";


	cout << network.getGraph().dijkstra(network.getGraph().getClosestGPS(start).first, network.getGraph().getClosestGPS(end).first) << "\n";

	// cin.get();

    return 0;
}