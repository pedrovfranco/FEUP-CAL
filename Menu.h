#ifndef MENU_H
#define MENU_H

#include "DeliveryNetwork.h"

class Menu{

	DeliveryNetwork network;
	unsigned int width = 100; /*!< The width of the console interface */
	unsigned int height = 30; /*!< The height of the console interface */

public:
	Menu();
	Menu(unsigned int width, unsigned int height);

	void Begin();
	void PreMenu();
	void MainMenu();
	void SomeMarkets();
	void ChooseCli();
};

#endif
