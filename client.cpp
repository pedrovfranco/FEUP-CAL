#include "client.h"

using namespace std;

client::client()
{}

client::client(int id, std::string name, unsigned int age, std::string address, double latitude, double longitude)
{
	this->id = id;
	this->name = name;
	this->age = age;
	this->address = address;
	this->gps = GPS(latitude, longitude);
}