#include "Client.h"

using namespace std;

Client::Client()
{}

Client::Client(int id, double latitude, double longitude)
{
	this->id = id;
	this->gps = GPS(latitude, longitude);
}


void Client::setGPSId(const Graph &graph)
{
	this->GPSid = graph.getClosestGPS(gps).first;
}


long long Client::getGPSId() const {
	return GPSid;
}