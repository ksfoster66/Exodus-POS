#include "employee.hpp"

	/*
	std::string first_name, last_name;
	int emp_ID;
	int phone_number
	*/
	
	int Employee::used_id = 0;
	
	Employee::Employee(int ID, std::string fname, std::string lname){
		emp_ID = ID;
		
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
	
	int Employee::getPhoneNumber(){
		return phone_number;
	}
	
	void Employee::setPhoneNumber(int n){
		phone_number = n;
	}
	
	int Employee::getNewID(){
		used_id++;
		return used_id;
	}
