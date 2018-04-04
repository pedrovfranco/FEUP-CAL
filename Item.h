#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {

	int id;
	string name;
	unsigned int amount;

public:

	Item();
	Item(int id, unsigned int amount);
	Item(int id, std::string name, unsigned int amount);

};



#endif