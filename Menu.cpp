#include "Menu.h"

using namespace std;

Menu:: Menu() {}

Menu:: void MainMenu()
{
	cout << "Welcome to something" << endl;
}

void Menu:: SomeMarkets()
{
	string nameM;

	cout << "this is the list of supermarkets id:" << endl;
	printSupermarkets();
	cout << "Please insert the id of supermarket you want" << endl;
	cin >> nameM;
}

void Menu:: ChooseCli()
{
	string nameC;

	cout << "this is the list of clients id:" << endl;
	printClients();
	cout << "Please insert the id of client you want" << endl;
	cin >> nameC;

}


