#ifndef ORDER_MANAGER_HPP
#define ORDER_MANAGER_HPP

#include "order.hpp"
#include <map>
#include <vector>
#include <string>

class OrderManager{
	map<int, Order*> orders;
	int number_active;
	
public:
	OrderManager(){ number_active = 0;}
	Order* getOrder(int order_number);
	vector<Order*> getOrders(Customer *c);
	vector<Order*> getOrders(Item *i);//Uses the item
	vector<Order*> getOrders(int i);//Uses the item number
	
	void refundOrder(int order_number);
	void refundOrder(int order_number, vector<int> q);
	void fulfillOrder(int order_number);
	void fulfillOrder(int order_number, vector<int> q);
};

#endif
