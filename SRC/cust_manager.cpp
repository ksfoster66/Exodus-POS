#include "cust_manager.hpp"
#include <iostream>

	//std::map<int, Customer*> customer_listing//a listing of customers by customer number
	
	//int num_customers = 0;//Total number of customers in the system
	
	Customer* CustManager::getCustomer(int ID){//Gets customer using their customer ID.
		return customer_listing[ID];
	}
	
	std::vector<Customer*> CustManager::getCustomersByName(std::string name){ //Gets a list of customers based on their name
		std::vector<Customer*> list;
		for(std::map<int, Customer*>::iterator it = customer_listing.begin(); it != customer_listing.end(); it++){
			if (name == it->second->getName()) list.push_back(it->second);
		}
		return list;
	}
	
	std::vector<Customer*> CustManager::getCustomersByPhone(std::string phone_number){ //Gets a list of customers based on the phone number entered
		std::vector<Customer*> list;
		for(std::map<int, Customer*>::iterator it = customer_listing.begin(); it != customer_listing.end(); it++){
			if (phone_number == it->second->getPhoneNumber()) list.push_back(it->second);
		}
		return list;
	}
	
	int CustManager::getNumCustomers(){
		return num_customers;
	}
	
	void CustManager::addCustomer(Customer *c){
		int id = c->getID();
		customer_listing.insert(std::pair<int, Customer*>(id, c));
		num_customers++;
	}
	
	void CustManager::removeCustomer(int id){
		std::cout << "Removal of customers is not currently enabled" << std::endl;
	}
	
	bool CustManager::contains(int id){
		
		if(customer_listing.find(id) == customer_listing.end()) return false;
		return true;
	}
