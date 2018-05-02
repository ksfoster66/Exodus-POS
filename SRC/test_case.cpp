#include "test_case.hpp"
#include <iostream>

/*
	Inventory* inv;
	CustManager* custMgr;
	EmpManager* empMgr;
	OrderManager* orderMgr;
	OrderGenerator* orderGen;
	Sales* sales;

*/

	void TestCase::run(){
		Employee* e = new Employee("Kevin", "Foster");
		empMgr->addEmployee(e);
		
		std::cout << "\nEmployee 1 added" << std::endl;
		std::cout << "Kevin Foster, ID: 1" << std::endl;
		
		e = new Employee("Luke", "Flake");
		empMgr->addEmployee(e);
		
		std::cout << "\nEmployee 2 added" << std::endl;
		std::cout << "Luke Flake, ID: 2" << std::endl;
		
		Customer* c = new Customer("Jeff", "Jeffers", "2295551234");
		custMgr->addCustomer(c);
		
		std::cout << "\nCustomer 1 added" << std::endl;
		std::cout << "Jeff Jeffers, 229-555-1234, ID: 1" << std::endl;
		
		c = new Customer("John", "Doe", "2295551235");
		custMgr->addCustomer(c);
		
		std::cout << "\nCustomer 2 added" << std::endl;
		std::cout << "John Doe, 229-555-1235, ID: 2" << std::endl;
		
		c = new Customer("Jane", "Doe", "2295551236");
		custMgr->addCustomer(c);
		
		std::cout << "\nCustomer 3 added" << std::endl;
		std::cout << "Jane Doe, 229-555-1236 ID: 3" << std::endl;
		
		Item* i = new Item(new UPC("1111"), "s1", "Stuff", "It's stuff", "Thing", "Stuff'r'Us", "available", 0.0, 20.00, 15.00);
		inv->addItem(i);
		
		std::cout << "\nItem 1 added" << std::endl;
		std::cout << "ID: 1, Stuff, MSRP: 20.00, Cost: 15.00" << std::endl;
		
		i = new Item(new UPC("2222"), "tv001", "TV", "A television for viewing things", "Television", "Televisos", "available", 80.00, 90.00, 50.00);
		inv->addItem(i);
		
		std::cout << "\nItem 2 added" << std::endl;
		std::cout << "ID: 2, TV, MSRP: 90.00, Cost: 50.00" << std::endl;
	}
