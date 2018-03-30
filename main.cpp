#include <iostream>
#include "DeliveryNetwork.h"
#include "Client.h"

using namespace std;

int main()
{

	DeliveryNetwork ola;
	ola.loadGraph("input/a.txt", "input/b.txt", "input/c.txt");

	Client client(1, "Jose", 41.174677, -8.600163);

	client.setGPSId(ola.getGraph());

	cout << ola.getGraph().findVertex(client.getGPSId())->getInfo() << "\n";
   

    return 0;
}