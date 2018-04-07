#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "DeliveryNetwork.h"
#include "ui_utilities.h"
#include "utilities.h"


class Menu {

	DeliveryNetwork network;
	unsigned int width = 100; /*!< The width of the console interface */
	unsigned int height = 30; /*!< The height of the console interface */
	std::string afilename, bfilename, cfilename;
	std::vector<std::string> banner; /*!< The 2-dimentional array of chars of the banner */

public:
	Menu();
	Menu(unsigned int width, unsigned int height);

	void Begin();
	void PreMenu();
	void MainMenu();
	void ListSupermarkets();
	void ListClients();
	void ShowPath();

	bool loadBanner(std::string filename);
	void printBanner(unsigned int width);
	void printBanner();
	void printCentered(std::string input);
};

#endif
