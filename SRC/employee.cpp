#include "employee.hpp"

	/*
	std::string first_name, last_name;
	int emp_ID;
	std::string phone_number
	
	std::vector<int> order_numbers;
	*/
	
	int Employee::used_id = 0;
	
	Employee::Employee(std::string fname, std::string lname){
		emp_ID = getNewID();
		
		first_name = fname;
		last_name = lname;
	}
	
	std::string Employee::getName(){
		return first_name + " " + last_name;
	}
	
	std::string Employee::getFirstName(){
		return first_name;
	}
	
	std::string Employee::getLastName(){
		return last_name;
	}
	
	int Employee::getID(){
		return emp_ID;
	}
	
	std::string Employee::getPhoneNumber(){
		return phone_number;
	}
	
	void Employee::setPhoneNumber(std::string n){
		phone_number = n;
	}
	
	int Employee::getNewID(){
		used_id++;
		return used_id;
	}
	
	void Employee::addOrder(int id){
		order_numbers.push_back(id);
	}
	
	void Employee::removeOrder(int id){
		for (int i = 0; i< order_numbers.size(); i++){
			if (order_numbers[i] == id){
				order_numbers.erase(order_numbers.begin() + i);
				break;
			}
		}
	}
	
	std::vector<int> Employee::getOrders(){
		return order_numbers;
	}
