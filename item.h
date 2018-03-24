#ifndef ITEM_H
#define ITEM_H

#include <string>


class item {

	int id;
	std::string name;
	unsigned int amount;

public:

	item();
	item(int id, std::string name, unsigned int amount);

};



#endif