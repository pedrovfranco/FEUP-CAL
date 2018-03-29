#include "Supermarket.h"


using namespace std;

Supermarket::Supermarket()
{

}

Supermarket::Supermarket(int id, string name, double latitude, double longitude)
{
	this->id = id;
	this->name = name;
	this->gps = GPS(latitude, longitude);

}