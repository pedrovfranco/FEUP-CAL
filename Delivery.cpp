#include "Delivery.h"

Delivery::Delivery(Supermarket * origin,Data data ){
  this->origin = origin;
  this->data = data;
}

void Delivery:: addOrder(Client * c, Item * it){
	for(int i = 0; i < orders.size(); i++){
		if(orders.at(i)->getId() == c->getId())
		orders.at(i)->addItem(it);
    return;
	}
  orders.push_back(c);
}



void Delivery:: addOrder(Client * c, vector<Item *> its){
  bool b = false;
	for(int i = 0; i < orders.size(); i++){
		if(orders.at(i)->getId() == c->getId()){
      for(const auto item : its){
        orders.at(i)->addItem(item); b = true;
      }  }
	}
  if(!b){orders.push_back(c);}
}

Client * Delivery::orderExists(int id){
  for(const auto& c : orders){
    if(c->getId() == id) return c;
  }

  return NULL;
}
