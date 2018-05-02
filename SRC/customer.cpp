#include "customer.hpp"
	
	/*
	std::string first_name, last_name;
	std::string phone_number;
	std::string address;
	std::string email;
	
	int cust_ID;
	
	std::vector<int> order_numbers;
	
	*/
	
	int Customer::used_id = 0;
	
	Customer::Customer(std::string fname, std::string lname, std::string number){
		first_name = fname;
		last_name = lname;
		phone_number = number;
		cust_ID = getNewID();
	}
	
	//Customer::~Customer(){} //Already implemented for now
	
	//getters and setters
	
	std::string Customer::getFirstName(){
		return first_name;
	}
	
	std::string Customer::getLastName(){
		return last_name;
	}
	
	std::string Customer::getName(){
		return first_name + " " + last_name;
	}
	
	int Customer::getID(){
		return cust_ID;
	}
	
	std::string Customer::getPhoneNumber(){
		return phone_number;
	}
	
	void Customer::setPhoneNumber(std::string num){
		phone_number = num;
	}
	
	std::string Customer::getAddress(){
		return address;
	}
	
	void Customer::setAddress(std::string address){
		this->address = address;
	}
	
	std::string Customer::getEmail(){
		return email;
	}
	
	void Customer::setEmail(std::string email){
		this->email = email;
	}
	
	int Customer::getNewID(){
		used_id++;
		return used_id;
	}
	
	void Customer::addOrder(int id){
		order_numbers.push_back(id);
	}
	
	void Customer::removeOrder(int id){
		for (int i = 0; i< order_numbers.size(); i++){
			if (order_numbers[i] == id){
				order_numbers.erase(order_numbers.begin() + i);
				break;
			}
		}
	}
	
	std::vector<int> Customer::getOrders(){
		return order_numbers;
	}
	
	
