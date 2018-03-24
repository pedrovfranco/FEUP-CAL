#include "supermarket.h"


using namespace std;

supermarket::supermarket()
{

}

supermarket::supermarket(int id, string name, double latitude, double longitude)
{
	this->id = id;
	this->name = name;
	this->gps = GPS(latitude, longitude);

}