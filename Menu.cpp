#include "Menu.h"

#include <iostream>
#include <fstream>


using namespace std;

string tempstr;

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

		if (!afile.is_open())
		{
			cout << "\nFile doesn't exist!\n";
			continue;
		}

		afile.close();

		cout <<"\n Insert roads filename (leave empty for default: \"input/b.txt\"): ";

		getline(cin, bfilename);
		utilities::trimString(bfilename);
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

		if (network.loadGraph(afilename, bfilename, cfilename) && network.loadSupermarkets(supermarkets) && network.loadClients(clients))
		{
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
				break;
			}

			else if (input == "2")
			{
				ListClients();
				break;
			}

			else if (input == "3")
			{
				ShowPath();
				break;
			}

			else if (input == "0")
			{
				ui_utilities::ClearScreen();
				return;
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

	// string tempstr;

	cout << "Supermarkets:\n\n";

	network.printSupermarkets();

	cout << "\nPress any key to continue!\n";
	getline(cin, tempstr);
}


void Menu::ListClients()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	printBanner();

	// string tempstr;

	cout << "Clients:\n\n";

	network.printClients();

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

	cout << "Supermarkets:\n\n";

	network.printSupermarkets();

	while (true)
	{
		cout << "\nChoose a supermarket id: ";

		getline(cin, tempstr);
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
	

	network.loadViewer(afilename, bfilename, cfilename);

	network.showPath(ids);

	cout << "\nPress any key to continue!\n";
	getline(cin, tempstr);
}
