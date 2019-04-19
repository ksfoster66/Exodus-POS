#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>

class Customer{

	//Fields
	std::string first_name, last_name;
	std::string phone_number;
	std::string address;
	std::string email;
	
	int cust_ID;
	
	//Orders
	std::vector<int> order_numbers;
	
public:
	//Methods
	//Constructor and destructor
	Customer(std::string fname, std::string lname, std::string number);
	
	~Customer(){}
	
	//getters and setters
	
	std::string getFirstName();
	
	std::string getLastName();
	
	std::string getName();
	
	int getID();
	
	std::string getPhoneNumber();
	
	void setPhoneNumber(std::string num);
	
	std::string getAddress();
	
	void setAddress(std::string address);
	
	std::string getEmail();
	
	void setEmail(std::string email);
	
	//ID number generating code
	static int used_id;
	int getNewID();
	
	void addOrder(int id);
	
	void removeOrder(int id);
	
	std::vector<int> getOrders();
};

#endif
