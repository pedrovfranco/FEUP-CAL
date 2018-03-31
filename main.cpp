#include <iostream>
#include "DeliveryNetwork.h"
#include "Client.h"

using namespace std;

int main()
{
	cout.precision(10);

	DeliveryNetwork network;
	network.loadGraph("input/a.txt", "input/b.txt", "input/c.txt");


	GPS start(41.174384, -8.599601);
	GPS foo = network.getGraph().getClosestGPS(start).second->getInfo();

	GPS end(41.177195999999995, -8.599632);
	GPS bar = network.getGraph().getClosestGPS(end).second->getInfo();

	// cout << foo << "\n" << bar << "\n";

	network.getGraph().dijkstraShortestPath(network.getGraph().getClosestGPS(start).first);

	vector<GPS> temp = network.getGraph().getPath(network.getGraph().getClosestGPS(start).first, network.getGraph().getClosestGPS(end).first);

	for (int i = 0; i < temp.size(); ++i)
	{
		cout << temp[i] << "\n";
	}

	// cin.get();

    return 0;
}