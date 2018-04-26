//Base class for ordering items.

#ifndef ORDER_HPP
#define ORDER_HPP

#include "item.hpp"
#include "inventory.hpp"
#include "employee.hpp"
#include "customer.hpp"
#include <vector>

class order{
	
	int order_number;
	//Date ordered;
	//Date due;
	//Date arriving;
	
	Customer *customer;//THe customer that purchased the order
	Employee *employee;//The employee that sold the order
	
	vector<int> itemIDs;
	vector<int> quantities;
	vector<double> price_sold;
	 
	//ID generating code;
	static int used_id;
	int getNewID();
	
public:
	Order(Customer* c, Employee* e, vector<int> items, vector<int> quant, vector<double> prices);
	
	int getOrderNumber();
	
	//Date getDateOrdered();
	//Date getDateDue();
	//void setDateDue(Date d);
	//Date getDateArriving();
	//void setDateArriving(Date d);
	
	Customer* getCustomer();
	Employee* getEmployee();
	
	vector<int> getItemsDue();
	vector<int> getQuantitiesDue();
	vector<double> getPriceSold();
	
	void itemsPickedUp(vector<int> q);
	
	void refundOrder(vector<int> q);
};

#endif
