/*
Keeps a track of all customers.
Customers should be searchable by three methods, name(specifically last name), phone number, and customer ID number
*/
#ifndef CUST_MANAGER_HPP
#define CUST_MANAGER_HPP

#include "customer.hpp"
#include <map>
#include <vector>
#include <string>

class CustManager{
//attributes
	std::map<int, Customer*> customer_listing;//a listing of customers by customer number
	
	int num_customers;//Total number of customers in the system
	
	
public:
	//methods
	CustManager(){
		num_customers = 0;
	}
	
	Customer* getCustomer(int ID);//Gets customer using their customer ID.
	
	std::vector<Customer*> getCustomersByName(std::string name); //Gets a list of customers based on their name
	
	std::vector<Customer*> getCustomersByPhone(std::string phone_number); //Gets a list of customers based on the phone number entered
	
	int getNumCustomers();
	
	void addCustomer(Customer *c);
	
	void removeCustomer(int id);
	
	bool contains(int id);
	
};

#endif
