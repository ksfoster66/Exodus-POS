#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee{
	//fields
	std::string first_name, last_name;
	int emp_ID;
	int phone_number;
	
	
	
public:
	//methods
	//constructors and destructors
	
	Employee(int ID, std::string fname, std::string lname);
	
	~Employee(){};
	//Getters and setters
	std::string getName();
	
	std::string getFirstName();
	
	std::string getLastName();
	
	int getID();
	
	int getPhoneNumber();
	
	void setPhoneNumber(int n);
	
	//Info for getting ID number;
	static int used_id;
	int getNewID();
	
	//modifiers
};

#endif
