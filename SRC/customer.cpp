#include "customer.hpp"
	
	/*
	std::string first_name, last_name;
	int phone_number;
	std::string address;
	std::string email;
	
	int cust_ID;
	
	
	*/
	
	int Customer::used_id = 0;
	
	Customer::Customer(std::string fname, std::string lname, int number, int ID){
		first_name = fname;
		last_name = lname;
		phone_number = number;
		cust_ID = ID;
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
	
	int Customer::getPhoneNumber(){
		return phone_number;
	}
	
	void Customer::setPhoneNumber(int num){
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
