//Base class for ordering items.

#ifndef ORDER_HPP
#define ORDER_HPP

#include "item.hpp"
#include "inventory.hpp"
#include "employee.hpp"
#include "customer.hpp"
#include <vector>

class Order{
	
	int order_number;
	//Date ordered;
	//Date due;
	//Date arriving;
	
	Customer *customer;//THe customer that purchased the order
	Employee *employee;//The employee that sold the order
	
	std::vector<int> itemIDs;
	std::vector<int> quantities;
	std::vector<double> price_sold;
	 
	//ID generating code;
	static int used_id;
	int getNewID();
	
	bool special;
	
public:
	Order(Customer* c, Employee* e, std::vector<int> items, std::vector<int> quant, std::vector<double> prices, bool s = false);
	
	int getOrderNumber();
	
	//Date getDateOrdered();
	//Date getDateDue();
	//void setDateDue(Date d);
	//Date getDateArriving();
	//void setDateArriving(Date d);
	
	Customer* getCustomer();
	Employee* getEmployee();
	
	std::vector<int> getItemsDue();
	std::vector<int> getQuantitiesDue();
	std::vector<double> getPriceSold();
	
	void itemsPickedUp(std::vector<int> q);
	
	void refundOrder(std::vector<int> q);
	
	
};

#endif
