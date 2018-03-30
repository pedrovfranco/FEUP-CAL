#include "Supermarket.h"


using namespace std;

Supermarket::Supermarket()
{

}

Supermarket::Supermarket(int id, string name, double latitude, double longitude)
{
	this->id = id;
	this->name = name;
	// this->gps = GPS(latitude, longitude);

}


void Supermarket::setGPSId(const Graph &graph)
{
	this->GPSid = graph.getClosestGPS(gps).first;
}

long long Supermarket::getGPSId() const
{
	return GPSid;
}