#include <iostream>
#include "DeliveryNetwork.h"
#include "Client.h"

using namespace std;

int main()
{
	cout.precision(10);

	DeliveryNetwork network;
	network.loadGraph("input/a.txt", "input/b.txt", "input/c.txt");

	network.loadClients("input/clients.txt");
	network.loadSupermarkets("input/supermarkets.txt");

	vector<Vertex*> path;

	GPS start(41.168625, -8.596722); //Casa
	GPS foo = network.getGraph().getClosestGPS(start).second->getInfo();

	GPS end(41.177717, -8.598266); // FEUP
	GPS bar = network.getGraph().getClosestGPS(end).second->getInfo();

	path.push_back(network.getGraph().getClosestGPS(start).second);

	std::unordered_map<int, Supermarket*> supermarkets = network.getSupermarkets();

	for (auto i : supermarkets)
	{
		path.push_back(network.i.second->getGPSId())
	}

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