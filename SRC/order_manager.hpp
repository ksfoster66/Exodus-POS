#ifndef ORDER_MANAGER_HPP
#define ORDER_MANAGER_HPP

#include "order.hpp"
#include "inventory.hpp"
#include <map>
#include <vector>
#include <string>

class OrderManager{
	map<int, Order*> orders;
	int number_active;
	Inventory* inv;
	
public:
	OrderManager(Inventory* i){ 
		number_active = 0;
		inv = i;
	}
	
	Order* getOrder(int order_number);
	vector<Order*> getOrders(Customer *c);
	vector<Order*> getOrders(Employee *e);
	vector<Order*> getOrders(int id);//Uses the item number
	
	void refundOrder(int order_number);
	void refundOrder(int order_number, vector<int> q);
	void fulfillOrder(int order_number);
	void fulfillOrder(int order_number, vector<int> q);
	
	void addOrder(Order* o);
	
	bool contains(int id);
};

#endif
