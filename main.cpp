#include <iostream>

#include "DeliveryNetwork.h"
#include "Client.h"
#include "Menu.h"


using namespace std;

int main()
{
	cout.precision(10);

	// DeliveryNetwork network;
	// network.loadGraph("input/a.txt", "input/b.txt", "input/c.txt");
	// network.loadViewer("input/a.txt", "input/b.txt", "input/c.txt");

	// network.loadClients("input/clients.txt");
	// network.loadSupermarkets("input/supermarkets.txt");

	// vector<long long> path;

	// GPS start(41.169034, -8.596604); //Minha casa
	// GPS foo = network.getGraph().getClosestGPS(start).second->getInfo();

	// GPS shop(41.166630, -8.601420); //Pet Shop Port

	// GPS end(41.168538, -8.597500); //Casa do tomas
	// GPS bar = network.getGraph().getClosestGPS(end).second->getInfo();

	// path.push_back(network.getGraph().getClosestGPS(start).first);
	// // path.push_back(network.getGraph().getClosestGPS(shop).first);
	// path.push_back(network.getGraph().getClosestGPS(end).first);

	// network.showPath(network.getGraph().getClosestGPS(start).first, network.getGraph().getClosestGPS(end).first);


	Menu menu;

	menu.Begin();

	cin.get();

    return 0;
}