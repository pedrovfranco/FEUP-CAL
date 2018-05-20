#include <iostream>
#include <csignal>

#include "DeliveryNetwork.h"
#include "Client.h"
#include "Menu.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;


void sigint_handler(int signal)
{
	ui_utilities::ClearScreen();
	system("pkill java --signal SIGTERM");

	usleep(1000*500);

	exit(1);
}


int main()
{
	cout.precision(10);

	struct sigaction sigintaction;

	sigintaction.sa_handler = sigint_handler;
	sigemptyset(&sigintaction.sa_mask);
	sigintaction.sa_flags = 0;

	if (sigaction(SIGINT, &sigintaction, NULL) < 0)
	{
		fprintf(stderr,"Unable to install SIGINT handler\n");
		return 1;
	}


	Menu menu;

	menu.Begin();

	// cin.get();

    return 0;
}
