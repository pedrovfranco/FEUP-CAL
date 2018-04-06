#include "Menu.h"

#include <iostream>
#include <iostream>


using namespace std;

Menu::Menu() {}

Menu::Menu(unsigned int width, unsigned int height) : width(width), height(height)
{}


void Menu::Begin()
{
	PreMenu();
}


void Menu::PreMenu()
{

}


void Menu::MainMenu()
{
	cout << "Welcome to something" << endl;
}

void Menu::SomeMarkets()
{
	string nameM;

	cout << "this is the list of supermarkets id:" << endl;
	network.printSupermarkets();
	cout << "Please insert the id of supermarket you want" << endl;
	cin >> nameM;
}

void Menu::ChooseCli()
{
	string nameC;

	cout << "this is the list of clients id:" << endl;
	network.printClients();
	cout << "Please insert the id of client you want" << endl;
	cin >> nameC;

}


