#include "Menu.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

#include "StringSearch.h"
#include <iomanip>

using namespace std;

string tempstr;
vector <long long> ids;

Menu::Menu() {}

Menu::Menu(unsigned int width, unsigned int height) : width(width), height(height)
{}


	void Menu::printCentered(string input)
	{
		cout << string((width - input.size())/2, ' ') << input << '\n';
	}

	void Menu::printBanner() {

		for (int i = 0; i < banner.size(); ++i)
		{
			cout << string((this->width - banner[i].size())/2, ' ') << banner[i] << '\n';
		}

		cout << '\n';
	}

	void Menu::printBanner(unsigned int width) {

		for (int i = 0; i < banner.size(); ++i)
		{
			cout << string((width - banner[i].size())/2, ' ') << banner[i] << '\n';
		}

		cout << '\n';
	}

	bool Menu::loadBanner(string filename) {

		ifstream file(filename);

		if (!file.is_open())
		return false;

		// string tempstr;

		while(getline(file, tempstr, '\n'))
		{
			banner.push_back(tempstr);
		}

		return true;
	}

	void Menu::Begin()
	{
		PreMenu();
	}


	void Menu::PreMenu()
	{
		ui_utilities::SetWindow(width, height);
		ui_utilities::ClearScreen();
		string a, b, c, clients, supermarkets;
		string foobar;

		while (true)
		{
			cout <<"\n Insert nodes filename (leave empty for default: \"input/a.txt\"): ";

			getline(cin, afilename);
			utilities::trimString(afilename);
			if (afilename == "")
			afilename = "input/a.txt";

			ifstream afile(afilename);
			network.setAFileName(afilename);

			if (!afile.is_open())
			{
				cout << "\nFile doesn't exist!\n";
				continue;
			}

			afile.close();

			cout <<"\n Insert roads filename (leave empty for default: \"input/b.txt\"): ";

			getline(cin, bfilename);
			utilities::trimString(bfilename);
			network.setBFileName(bfilename);
			if (bfilename == "")
			bfilename = "input/b.txt";

			ifstream bfile(bfilename);

			if (!bfile.is_open())
			{
				cout << "\nFile doesn't exist!\n";
				continue;
			}

			bfile.close();

			cout <<"\n Insert edges filename (leave empty for default: \"input/c.txt\"): ";

			getline(cin, cfilename);
			utilities::trimString(cfilename);
			network.setCFileName(cfilename);
			if (cfilename == "")
			cfilename = "input/c.txt";

			ifstream cfile(cfilename);

			if (!cfile.is_open())
			{
				cout << "\nFile doesn't exist!\n";
				continue;
			}

			cfile.close();

			cout <<"\n Insert supermarkets filename (leave empty for default: \"input/supermarkets.txt\"): ";

			getline(cin, supermarkets);
			utilities::trimString(supermarkets);
			if (supermarkets == "")
			supermarkets = "input/supermarkets.txt";

			ifstream supermarketsfile(supermarkets);

			if (!supermarketsfile.is_open())
			{
				cout << "\nFile doesn't exist!\n";
				continue;
			}
			supermarketsfile.close();

			cout <<"\n Insert items filename (leave empty for default: \"input/supermarkets.txt\"): ";

			getline(cin, itemfilename);
			utilities::trimString(itemfilename);
			if (itemfilename == "")
			itemfilename = "input/items.txt";

			ifstream itemfile(itemfilename);

			if (!itemfile.is_open())
			{
				cout << "\nFile doesn't exist!\n";
				continue;
			}

			itemfile.close();

			cout <<"\n Insert clients filename (leave empty for default: \"input/clients.txt\"): ";

			getline(cin, clients);
			utilities::trimString(clients);
			if (clients == "")
			clients = "input/clients.txt";

			ifstream clientsfile(supermarkets);

			if (!clientsfile.is_open())
			{
				cout << "\nFile doesn't exist!\n";
				continue;
			}

			clientsfile.close();

			if (network.loadGraph(afilename, bfilename, cfilename) && network.loadSupermarkets(supermarkets) && network.loadClients(clients)
			&& network.loadItems(itemfilename))
			{network.loadDeliveries();
				break;
			}
			else
			{
				cout << "Couldn't load files!\n";
				return;
			}


		}

		while (1)
		{
			cout <<"\n Insert banner filename (leave empty for default: \"bannerfile\"): ";

			getline(cin, foobar);
			utilities::trimString(foobar);
			if (foobar == "")
			foobar = "bannerfile";

			if (loadBanner(foobar))
			break;
			else
			cout << "File doesn't exist!";
		}

		cout << "\n\n   All files have been loaded with success. Press enter to continue...";
		getline(cin, foobar);

		MainMenu();
	}


	void Menu::MainMenu()
	{
		while (true)
		{
			ui_utilities::SetWindow(width, height);
			ui_utilities::ClearScreen();
			printBanner();

			cout << "Enter a number to choose the sub-menu that you want to go !\n\n";
			cout << "1- List supermarkets \n";
			cout << "2- List clients \n";
			cout << "3- Show path between places \n";
			cout << "4- Place Order \n";
			cout << "5- Show deliveries in queue \n";
			cout << "6- Make delivery \n";
			cout << "7- Show graph points \n";
			cout << "8- Search road by name\n";
			cout << "9- Search supermarket by crossroad\n";
			cout << "0- Quit \n\n";


			string input;

			while (true)
			{
				cout << "Select an option: ";

				getline(cin, input);
				utilities::trimString(input);
				cout << "\n";

				if (input == "1")
				{
					ListSupermarkets();
					pressAnyKey();
					break;
				}

				else if (input == "2")
				{
					ListClients();
					pressAnyKey();
					break;
				}

				else if (input == "3")
				{
					ShowPath();
					break;
				}

				else if (input == "4")
				{
					placeOrder();
					pressAnyKey();
					break;
				}

				else if (input == "5")
				{
					ui_utilities::SetWindow(width, height);
					ui_utilities::ClearScreen();
					printBanner();
					network.showDeliveries();
					pressAnyKey();
					break;
				}


				else if (input == "6")
				{
					loadViewer("input/a.txt","input/b.txt", "input/c.txt",	network.makeDelivery());
					pressAnyKey();

					break;
				}

				else if (input == "7")
				{
					loadGraph();

					break;
				}

				else if (input == "8")
				{
					showRoad();

					break;
				}

				else if (input == "9")
				{
					searchCrossRoads();

					break;
				}

				else if (input == "0")
				{
					raise(SIGINT);
				}

				else
				cout << "Invalid input!\n";

			}
		}
	}


	void Menu::ListSupermarkets()
	{
		ui_utilities::SetWindow(width, height);
		ui_utilities::ClearScreen();
		printBanner();

		cout << "Supermarkets:\n\n";

		network.printSupermarkets();

	}


	void Menu::ListClients()
	{
		ui_utilities::SetWindow(width, height);
		ui_utilities::ClearScreen();
		printBanner();

			utilities::trimString(tempstr);

			utilities::trimString(tempstr);


		cout << "Clients:\n\n";

		network.printClients();

	}

	void Menu :: pressAnyKey(){
		cout << "\nPress any key to continue!\n";
		getline(cin, tempstr);
	}


	void Menu::ShowPath()
	{
		ui_utilities::SetWindow(width, height);
		ui_utilities::ClearScreen();
		printBanner();

		vector<long long> ids;
		Supermarket* supermarket = NULL;
		Client* client = NULL;
		int start_s;

		cout << "Supermarkets:\n\n";

		network.printSupermarkets();

		while (true)
		{
			cout << "\nChoose a supermarket id: ";

			getline(cin, tempstr);
			start_s=clock();
			//auto start = std::chrono::high_resolution_clock::now();
			utilities::trimString(tempstr);

			if (utilities::isNumeric(tempstr) && tempstr != "")
			{
				supermarket = network.getSupermarkets()[stoi(tempstr)];
			}
			else
			{
				cout << "Id must be a number!\n";
				continue;
			}

			if (supermarket != NULL)
			{
				ids.push_back(supermarket->getRef().first);
				break;
			}
			else
			{
				cout << "Supermarket not found!\n";
			}
		}

		map<int, Client*> clients = network.getClients();

		tempstr = ".";

		cout << "\n\n";

		while (clients.size() != 0)
		{
			for (auto i : clients)
				cout << *(i.second) << "\n";

			cout << "\nChoose a client (Press Enter to finish): ";

			getline(cin, tempstr);
			utilities::trimString(tempstr);

			if (tempstr == "")
			{
				if (ids.size() == 1)
				{
					cout << "Must have at least one client!\n\n";
					continue;
				}
				else
				{
					break;
				}
			}

			if (utilities::isNumeric(tempstr))
			{
				if (clients.find(stoi(tempstr))!= clients.end())
					client = clients.find(stoi(tempstr))->second;
				else
					client = NULL;
			}
			else
			{
				cout << "Id must be a number!\n";
				continue;
			}

			if (client != NULL)
			{
				ids.push_back(client->getRef().first);
				clients.erase(stoi(tempstr));
				cout << "Client added!\n\n";
			}
			else
			{
				cout << "Client not found!\n\n";
			}
		}

		network.loadViewer("input/a.txt", "input/b.txt", "input/c.txt");

		int stop_s=clock();
		cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

		network.showPath(ids);

		cout << "\nPress any key to continue!\n";
		getline(cin, tempstr);

		network.getGV()->closeWindow();
	}



void Menu::loadViewer(string a, string b, string c, 	vector<long long> ids){
	if(ids.size()== 0){
		return;
	}
	network.loadViewer(a, b, c);
	// int start_s=clock();
	network.showPath(ids);
	// the code you wish to time goes here
// int stop_s=clock();
// cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

	cout << "\nPress any key to continue!\n";
	getline(cin, tempstr);

	network.getGV()->closeWindow();
}




void Menu::loadGraph(){

	network.loadViewer("input/a.txt", "input/b.txt", "input/c.txt");
	network.showGraph(network.getSupermarketsIDs(),network.getClientsIDs());


	cout << "\nPress any key to continue!\n";
	getline(cin, tempstr);

	network.getGV()->closeWindow();
}


void Menu::placeOrder(){
	int day = 1;
		int d, m, y;

	string clientID;
	string itemID;

	ListClients();
	while(true){
		cout << "\nEnter the client's id: ";
		getline(cin, clientID);
		utilities::trimString(clientID);

		if (clientID == "")
		{
			cout << "Invalid Input! \n";
			continue;
		}

		if (utilities::isNumeric(clientID))
		{
			if(network.clientExists(stoi(clientID))) break;
			else {
				cout << "Client not found! \n";
				continue;
			}
		}

	}

	ListItems();

	vector<int> ids;

	while (itemID!="\n")
	{

		cout << "\nChoose an Item (Press Enter to finish): ";

		getline(cin, itemID);
		utilities::trimString(itemID);

		if (itemID == "")
		{
			if (ids.size() == 0)
			{
				cout << "Must have at least one item!\n\n";
				continue;
			}
			else
			{
				break;
			}
		}

		if (utilities::isNumeric(itemID))
		{
			if (network.itemExists(stoi(itemID)))
			ids.push_back(stoi(itemID));
			else{
				cout << "Item doesn't exist!\n\n";
				continue;
			}
		}
		else
		{
			cout << "Id must be a number!\n";
			continue;
		}

	}

	cout << "\nEnter date (ex.: 1 2 2019): ";


	cin >> d >> m >> y;
	network.clientExists(stoi(clientID))->addItems(ids);
	network.placeOrder(stoi(clientID), Data(d, m, y));
}


void Menu::ListItems(){
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	printBanner();

	cout << "Items' ids:\n\n";

	network.printItems();
}


void Menu::showRoad()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	printBanner();

	vector<string> names;

	cout << "Enter a road name: ";

	getline(cin, tempstr);

    auto temp = network.getGraph().searchByRoadName(tempstr);

	//if(temp.size()!=1)cout << "A perfect match wasn't found! Here are the closest matches:\n";
	

	int j = 0;
	for (auto i : temp)
	{
		cout << j+1 << " - "<< network.getGraph().findEdge(i.first).getRoadName() << " | " << fixed << setprecision(3) << (1-i.second) * 100 << "%\n";
		names.push_back(network.getGraph().findEdge(i.first).getRoadName());

		if (j ==5)
			break;

		j++;
	}

	tempstr = "-1";
	cout <<"\nWhich road do you which to search?:\n";
	while(stoi(tempstr) < 1 || stoi(tempstr) > j+1)
	{
		cout << "Insert a valid option:\n";
		getline(cin, tempstr);
		utilities::trimString(tempstr);
	}

	tempstr = names[stoi(tempstr)-1];
	names.resize(0);

	network.loadViewer("input/a.txt", "input/b.txt", "input/c.txt");
	network.markRoadFound(tempstr);

    network.showGraph(network.getSupermarketsIDs(),network.getClientsIDs());

    pressAnyKey();

    network.getGV()->closeWindow();

}

void Menu::searchCrossRoads()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	printBanner();

	string road1, road2, tempstr1, tempstr2;
	Supermarket* chosen;
	set<pair<long long, double>, classcomp> temp1, temp2;
	vector<string> names;

	cout << "\nDo you want exact search? (Y/N) ";

	getline(cin, tempstr);
	utilities::trimString(tempstr);

	if (tempstr == "Y" || tempstr == "y")
	{
		cout << "Enter the first road's name: ";
		getline(cin, road1);
		utilities::trimString(road1);

		cout << "\nEnter the second road's name: ";
		getline(cin, road2);
		utilities::trimString(road2);
	}
	else
	{
		cout << "Enter the first road's name: ";
		getline(cin, road1);
		utilities::trimString(road1);

		temp1 = network.getGraph().searchByRoadName(road1);

		int j = 0;
		for (auto i : temp1)
		{
			cout << j+1 << " - "<< network.getGraph().findEdge(i.first).getRoadName() << " | " << fixed << setprecision(3) << (1-i.second) * 100 << "%\n";

			names.push_back(network.getGraph().findEdge(i.first).getRoadName());

			if (j ==5)
				break;

			j++;
		}

		road1 = "-1";
		cout <<"\nWhich road do you which to search?:\n";
		while(stoi(road1) < 1 || stoi(road1) > j+1)
		{
			cout << "Insert a valid option:\n";
			getline(cin, road1);
			utilities::trimString(road1);
		}

		road1 = names[stoi(road1)-1];
		names.resize(0);


		cout << "\nEnter the second road's name: ";
		getline(cin, road2);
		utilities::trimString(road2);

		temp1 = network.getGraph().searchByRoadName(road2);

		j = 0;
		for (auto i : temp1)
		{
			cout << j+1 << " - "<< network.getGraph().findEdge(i.first).getRoadName() << " | " << fixed << setprecision(3) << (1-i.second) * 100 << "%\n";

			names.push_back(network.getGraph().findEdge(i.first).getRoadName());

			if (j ==5)
				break;

			j++;
		}

		road2 = "-1";
		cout <<"\nWhich road do you which to search?:\n";
		while(stoi(road2) < 1 || stoi(road2) > j+1)
		{
			cout << "Insert a valid option:\n";
			getline(cin, road2);
			utilities::trimString(road2);
		}

		road2 = names[stoi(road2)-1];
		names.resize(0);

	}

    temp1 = network.getGraph().searchByRoadName(road1);
	road1 = network.getGraph().findEdge((*temp1.begin()).first).getRoadName();
    temp1 = network.getGraph().searchByRoadName(road2);
    road2 = network.getGraph().findEdge((*temp1.begin()).first).getRoadName();
	chosen = network.findCrossroad(road1, road2);

	if (chosen == NULL)
	{
		cout << "Supermarket not found!\n";
		pressAnyKey();
	}
	else
	{
	    cout << "There is a  " << chosen->getName() << " in that crossway.\n";
		network.loadViewer("input/a.txt", "input/b.txt", "input/c.txt");
		network.markRoadFound(road1);
		network.markRoadFound(road2);
	    network.showGraph(network.getSupermarketsIDs(), network.getClientsIDs());
    	
    	pressAnyKey();

	    network.getGV()->closeWindow();
	}

	
}
