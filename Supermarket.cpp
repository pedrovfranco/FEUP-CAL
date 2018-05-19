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

Supermarket::Supermarket(int id, double latitude, double longitude, string chain)
{
	this->id = id;
	this->gps = GPS(latitude, longitude);
	this->chain = chain;
}


void Supermarket::setRef(const Graph &graph)
{
	this->ref = graph.getClosestGPS(gps);
}


int Supermarket::getId() const
{
	return id;
}

GPS Supermarket::getGPS() const
{
	return gps;
}

pair<long long, Vertex*> Supermarket::getRef() const
{
	return ref;
}

ostream& operator<<(ostream &os, const Supermarket &input)
{
	os << input.getId() << ", " << input.getGPS();
	return os;
}