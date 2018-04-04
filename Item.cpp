#include "Item.h"


Item::Item()
{}

Item::Item(int id, unsigned int amount)
{
	this->id = id;
	this->amount = amount;
}

Item::Item(int id, std::string name, unsigned int amount)
{
	this->id = id;
	this->name = name;
	this->amount = amount;
}