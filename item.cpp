#include "item.h"


item::item()
{

}

item::item(int id, std::string name, unsigned int amount)
{
	this->id = id;
	this->name = name;
	this->amount = amount;
}