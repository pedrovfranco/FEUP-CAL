#ifndef DELIVERY_H
#define DELIVERY_H

#include <set>

#include "Supermarket.h"
#include "GPS.h"
#include "Data.h"



class Delivery {

	Supermarket * origin;
	vector<Client*> orders;
	Data data;

public:

	Delivery(Supermarket * origin,Data data );


Data getData(){return data;}

bool operator < (Delivery & d) const
{
	if(data.getAno() != d.getData().getAno())
		return data.getAno() < d.getData().getAno();

	if(data.getMes() != d.getData().getMes())
		return data.getMes() < d.getData().getMes();

	if(data.getDia() != d.getData().getDia())
			return data.getDia() < d.getData().getDia();


			return true;
		}


	void addOrder(Client * c, Item * i);
	vector<Client*>  getOrders(){return orders;}
	Client * orderExists(int id);
	void addOrder(Client * c, vector<Item *> its);
	Supermarket * getSupermarket(){return origin;}

};

#endif
