#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <vector>

class Employee{
	//fields
	std::string first_name, last_name;
	int emp_ID;
	std::string phone_number;
	
	std::vector<int> order_numbers;
	
public:
	//methods
	//constructors and destructors
	
	Employee(std::string fname, std::string lname);
	
	~Employee(){};
	//Getters and setters
	std::string getName();
	
	std::string getFirstName();
	
	std::string getLastName();
	
	int getID();
	
	std::string getPhoneNumber();
	
	void setPhoneNumber(std::string n);
	
	//Info for getting ID number;
	static int used_id;
	int getNewID();
	
	//modifiers
	
	void addOrder(int id);
	
	void removeOrder(int id);
	
	std::vector<int> getOrders();
};

#endif
