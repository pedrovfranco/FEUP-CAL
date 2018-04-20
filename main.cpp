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

	// GPS start(41.168315, -8.601543); //Pingo Doce
	// GPS foo = network.getGraph().getClosestGPS(start).second->getInfo();

	// cout << foo << "\n";

	// GPS shop(41.166630, -8.601420); //Pet Shop Port

	// GPS end(41.168538, -8.597500); //Casa do tomas
	// GPS bar = network.getGraph().getClosestGPS(end).second->getInfo();

	// path.push_back(network.getGraph().getClosestGPS(start).first);
	// // path.push_back(network.getGraph().getClosestGPS(shop).first);
	// path.push_back(network.getGraph().getClosestGPS(end).first);

	// network.showPath(path);


	Menu menu;

	menu.Begin();

	// cin.get();

    return 0;
}
