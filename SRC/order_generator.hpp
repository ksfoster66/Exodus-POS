#ifndef ORDER_GENERATOR_HPP
#define ORDER_GENERATOR_HPP
//Gets passed sales info from the sales system and automatically creates the order as necessary, breaking up the sos items from the rest

#include "item.hpp"
#include "inventory.hpp"
#include "customer.hpp"
#include "employee.hpp"
#include "cust_manager.hpp"
#include "emp_manager.hpp"
#include "order.hpp"
#include "order_manager.hpp"
#include <vector>

class OrderGenerator{
	OrderManager* OrdMgr;
	Inventory* inv;
	
public:
	
	OrderGenerator(OrderManager* o, Inventory* i){
		OrdMgr = o;
		inv = i;
	}
	
	void createOrder(std::vector<int> ids, std::vector<int> quantities, std::vector<double> prices, Customer* c, Employee* e);
};

#endif
