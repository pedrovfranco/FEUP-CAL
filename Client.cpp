#include "Client.h"

using namespace std;

Client::Client()
{}

Client::Client(int id, std::string name, unsigned int age, std::string address, double latitude, double longitude)
{
	this->id = id;
	this->name = name;
	this->age = age;
	this->address = address;
}