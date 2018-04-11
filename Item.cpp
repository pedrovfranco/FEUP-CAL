#include "Item.h"


Item::Item()
{}

Item::Item(int id,  int amount)
{
	this->id = id;
	this->amount = amount;
}


int Item::getId(){
	return id;
}
