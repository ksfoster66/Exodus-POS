#include "order.hpp"

	/*
	int order_number;
	//Date ordered;
	//Date due;
	//Date arriving;
	
	Customer *customer;//THe customer that purchased the order
	Employee *employee;//The employee that sold the order
	
	vector<int> itemIDs;
	vector<int> quantities;
	vector<double> price_sold;
	 */
	 
	//ID generating code;
	int Order::used_id = 0;
	int Order::getNewID(){
		used_id++;
		return used_id;
	}
	
	Order::Order(Customer* c, Employee* e, vector<int> items, vector<int> quant, vector<double> prices){
		order_number = getNewID();
		
		customer = c;
		employee = e;
		
		itemIDs = items;
		quantities = quant;
		price_sold = prices;
	}
	
	int Order::getOrderNumber(){
		return order_number;
	}
	
	//Date Order::getDateOrdered();
	//Date Order::getDateDue();
	//void Order::setDateDue(Date d);
	//Date Order::getDateArriving();
	//void Order::setDateArriving(Date d);
	
	Customer* Order::getCustomer(){
		return customer;
	}
	
	Employee* Order::getEmployee(){
		return employee;
	}
	
	vector<int> Order::getItemsDue(){
		return itemIDs;
	}
	vector<int> Order::getQuantitiesDue(){
		return quantities;
	}
	vector<double> Order::getPriceSold(){
		return price_sold;
	}
	
	void Order::itemsPickedUp(vector<int> q){
		for (int i = 0; i < q.size(); i++){
			quantities[i] -= q[i];
		}
		for (int i = 0; i < quantities.size(); i++){
			if (quantities[i] == 0){
				itemIDs.erase[i];
				quantities[i];
				price_sold[i];
				continue;
			}
		}
	}
	
	void Order::refundOrder(vector<int> q){
		for (int i = 0; i < q.size(); i++){
			quantities[i] -= q[i];
		}
		for (int i = 0; i < quantities.size(); i++){
			if (quantities[i] == 0){
				itemIDs.erase[i];
				quantities[i];
				price_sold[i];
				continue;
			}
		}
	}
