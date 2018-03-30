#include <iostream>
#include "DeliveryNetwork.h"

using namespace std;

int main()
{

	DeliveryNetwork ola;
	ola.loadGraph("maps/a.txt", "maps/b.txt", "maps/c.txt");
   

    return 0;
}