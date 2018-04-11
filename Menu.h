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
	std::string afilename, bfilename, cfilename, itemfilename;
	std::vector<std::string> banner; /*!< The 2-dimentional array of chars of the banner */
	bool graphvieweropen = false;

public:
	Menu();
	Menu(unsigned int width, unsigned int height);

	void Begin();
	void PreMenu();
	void MainMenu();
	void ListSupermarkets();
	void ListClients();
	void ShowPath();
	void placeOrder();
	void ListItems();
	void loadViewer(string a, string b, string c, 	vector<long long> ids);

	void pressAnyKey();

	bool loadBanner(std::string filename);
	void printBanner(unsigned int width);
	void printBanner();
	void printCentered(std::string input);
	void showDeliveries();
};

#endif
