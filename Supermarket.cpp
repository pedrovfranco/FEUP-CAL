#include "Supermarket.h"


using namespace std;

Supermarket::Supermarket()
{

}

Supermarket::Supermarket(int id, double latitude, double longitude)
{
	this->id = id;
	this->gps = GPS(latitude, longitude);
}


void Supermarket::setGPSId(const Graph &graph)
{
	this->GPSid = graph.getClosestGPS(gps).first;
}

int Supermarket::getId() const
{
	return id;
}

GPS Supermarket::getGPS() const
{
	return gps;
}

long long Supermarket::getGPSId() const
{
	return GPSid;
}

ostream& operator<<(ostream &os, const Supermarket &input)
{
	os << input.getId() << ", " << input.getGPS();
	return os;
}