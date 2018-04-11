#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>

class Customer{

	//Fields
	std::string first_name, last_name;
	int phone_number;
	std::string address;
	std::string email;
	
	int cust_ID;
	
public:
	//Methods
	//Constructor and destructor
	Customer(std::string fname, std::string lname, int number, int ID);
	
	~Customer(){}
	
	//getters and setters
	
	std::string getFirstName();
	
	std::string getLastName();
	
	std::string getName();
	
	int getID();
	
	int getPhoneNumber();
	
	void setPhoneNumber(int num);
	
	std::string getAddress();
	
	void setAddress(std::string address);
	
	std::string getEmail();
	
	void setEmail(std::string email);
	
	//ID number generating code
	static int used_id;
	int getNewID();
};

#endif
