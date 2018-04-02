#include <iostream>
#include "DeliveryNetwork.h"
#include "Client.h"

using namespace std;

int main()
{
	cout.precision(10);

	DeliveryNetwork network;
	network.loadGraph("input/a.txt", "input/b.txt", "input/c.txt");


	GPS start(41.174254, -8.603765); //Polo Universitario
	GPS foo = network.getGraph().getClosestGPS(start).second->getInfo();

	GPS end(41.177717, -8.598266); // FEUP
	GPS bar = network.getGraph().getClosestGPS(end).second->getInfo();

	// cout << foo << "\n" << bar << "\n\n";

	// network.getGraph().dijkstraShortestPath(network.getGraph().getClosestGPS(start).first);

	// vector<Vertex*> temp = network.getGraph().getPath(network.getGraph().getClosestGPS(start).first, network.getGraph().getClosestGPS(end).first);

	// for (int i = 0; i < temp.size(); ++i)
	// {
	// 	cout << temp[i]->getInfo() << "\n";
	// }

	network.showPath(network.getGraph().getClosestGPS(start).first, network.getGraph().getClosestGPS(end).first);

	cin.get();

    return 0;
}