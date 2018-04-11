#include "Client.h"

using namespace std;

Client::Client()
{}

Client::Client(int id, double latitude, double longitude)
{
	this->id = id;
	this->gps = GPS(latitude, longitude);
}

Client::Client(int id, double latitude, double longitude, std::vector<Item* > items)
{
	this->id = id;
	this->gps = GPS(latitude, longitude);
	this->basket = items;
}

void Client::setBasket(std::vector<Item* > items)
{
	this->basket = items;
}

void Client::setId(const int &id)
{
	this->id = id;
}

void Client::setGPS(GPS input)
{
	this->gps = input;
}

void Client::setRef(const Graph &graph)
{
	this->ref = graph.getClosestGPS(gps);
}

int Client::getId() const
{
	return id;
}

GPS Client::getGPS() const
{
	return gps;
}

pair<long long, Vertex*> Client::getRef() const
{
	return ref;
}

void Client::addItem(Item * i){
	for(const auto& it : basket){
		if(it->getId()==i->getId()){
			it->setAmmout(i->getAmmount());
			return;
		}
	}
	basket.push_back(i);
}

void Client::addItems(vector<int> i){
	for(const auto& it : i){
		addItem(new Item(id,1));
	}
}

	if(ano == c2.getAno())
	{
		if(mes < c2.getMes())
		{
			return false;
		}

		if(mes > c2.getMes())
		{
			return true;
		}

		if(mes == c2.getMes())
		{
			if(diaN < c2.getDia())
			{
				return false;
			}

			if(dia > c2.getDia())
			{
				return true;
			}

			if(dia == c2.getDia())
			{
				return false;
			}
		}
	}
}

ostream& operator<<(ostream &os, const Client &input)
{
	os << input.getId() << ", " << input.getGPS();
	return os;
}
