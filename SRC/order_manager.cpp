#include "order_manager.hpp"

	//map<int, Order*> orders;
	//int number_active;
	
	
	//OrderManager(){ number_active = 0;}
	
	Order* getOrder(int order_number){
		return orders[order_number];
	}
	vector<Order*> getOrders(Customer *c);
	vector<Order*> getOrders(Item *i);//Uses the item
	vector<Order*> getOrders(int i);//Uses the item number
	
	void refundOrder(int order_number);
	void refundOrder(int order_number, vector<int> q);
	void fulfillOrder(int order_number);
	void fulfillOrder(int order_number, vector<int> q);
