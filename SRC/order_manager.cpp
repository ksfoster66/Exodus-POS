#include "order_manager.hpp"

	//map<int, Order*> orders;
	//int number_active;
	//Inventory* inv
	
	
	//OrderManager(Inventory* i){ 
	//	number_active = 0;
	//	inv = i;
	//}
	
	Order* OrderManager::getOrder(int order_number){
		return orders[order_number];
	}
	
	std::vector<Order*> OrderManager::getOrders(Customer *c){
		std::vector<Order*> output;
		for (std::map<Order*>::iterator it = orders.begin(); it != orders.end(); it++){
			if(orders[it]->getCutomer() == c) output.push_back(orders[it]);
		}
		
		return output;
	}
	
	std::vector<Order*> OrderManager::getOrders(Employee *e){
		std::vector<Order*> output;
		for (std::map<Order*>::iterator it = orders.begin(); it != orders.end(); it++){
			if(orders[it]->getEmployee() == e) output.push_back(orders[it]);
		}
		
		return output;
	}
	
	std::vector<Order*> OrderManager::getOrders(int id){}//Uses the item number
		std::vector<Order*> output;
		std::vector<int> ids;
		for (std::map<Order*>::iterator it = orders.begin(); it != orders.end(); it++){
			ids = orders[it]->getItemsDue();
			for(int i = 0; i < ids.size(); i++){
				if(ids[i] == id) output.push_back(orders[it]);
				break;
			}
		}
		
		return output;
	}
	
	void OrderManager::refundOrder(int order_number){
		Order* order = orders[order_number];
		std::vector<int> ids = order->getItemsDue();
		std::vector<int> quantities = order->getQuantitiesDue();
		std::vector<double> prices = order->getPriceSold();
		
		inv->returned(ids, quantities, prices);
		
	}
	void OrderManager::refundOrder(int order_number, vector<int> q){
		Order* order = orders[order_number];
		std::vector<int> ids = order->getItemsDue();
		std::vector<double> prices = order->getPriceSold();
		
		inv->returned(ids, q, prices);
	}
	
	void OrderManager::fulfillOrder(int order_number){
		Order* order = orders[order_number];
		std::vector<int> ids = order->getItemsDue();
		std::vector<int> quantities = order->getQuantitiesDue();
		
		inv->delay_fulfilled(ids, quantities);
	}
	void OrderManager::fulfillOrder(int order_number, vector<int> q){
		Order* order = orders[order_number];
		std::vector<int> ids = order->getItemsDue();
		
		inv->delay_fulfilled(ids, q);
	}
	
	void OrderManager::addOrder(Order* o){
		int id = o->getOrderNumber();
		number_active++;
		orders[id] = o;
	}
	
	bool OrderManager::contains(int id){
		bool result = true;
		try{
			orders.at(id);
		}catch(){
			result = false;
		}
		return result;
	}
