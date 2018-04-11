#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
using namespace std;

class Item {

	int id;
	string name;
	int amount;

public:

	Item();
	Item(int id, int amount);
	int getId();
	void incAmmount(){amount++;}
	void setAmmout(int amount){this->amount = amount;}
	int getAmmount(){return amount;}

};



#endif
