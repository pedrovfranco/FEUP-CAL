#include "Client.h"

using namespace std;

Client::Client()
{}

Client::Client(int id, double latitude, double longitude)
{
	this->id = id;
	this->gps = GPS(latitude, longitude);
}

Client::Client(int id, double latitude, double longitude, std::vector<Item> items)
{
	this->id = id;
	this->gps = GPS(latitude, longitude);
	this->basket = items;
}

void Client::setBasket(std::vector<Item> items)
{
	this->basket = items;
}

void Client::setGPSId(const Graph &graph)
{
	this->GPSid = graph.getClosestGPS(gps).first;
}

void Client::setId(const int &id)
{
	this->id = id;
}

void Client::setGPS(GPS input)
{
	gps = input;
}

int Client::getId() const
{
	return id;
}

GPS Client::getGPS() const
{
	return gps;
}

long long Client::getGPSId() const
{
	return GPSid;
}


ostream& operator<<(ostream &os, const Client &input)
{
	os << input.getId() << ", " << input.getGPS();
	return os;
}