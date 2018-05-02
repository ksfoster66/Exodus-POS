//THe command line interpreter to debug and test the POS system as it currently works. To be updated and used as the primary testbed for new features before creating/updating GUI features
#ifndef CLI_HPP
#define CLI_HPP

#include <iostream>
#include <fstream>

#include "inventory.hpp"
#include "cust_manager.hpp"
#include "emp_manager.hpp"
#include "order_manager.hpp"
#include "order_generator.hpp"
#include "sales.hpp"

class CLI{
	//Fields
	Inventory* inv;
	CustManager* custMgr;
	EmpManager* empMgr;
	OrderManager* orderMgr;
	OrderGenerator* orderGen;
	Sales* sales;

public:
	CLI(Inventory* i, CustManager* cm, EmpManager* em, OrderManager* om, OrderGenerator* og, Sales* s){
		inv = i;
		custMgr = cm;
		empMgr = em;
		orderMgr = om;
		orderGen = og;
		sales = s;
	}

	void run();
	
	void SalesEntry();
	//More sales methods
	void enterItem();
	void changeQuantity();
	void changePrice();
	void removeSaleItem();
	void lookUpCustomer();
	void checkout();
	
	void OrderManagement();
	//More Order methods
	void orderLookUp();
	void fulfillOrder();
	void refundOrder();
	
	void InventoryManagement();
	//MORE INVENTORY METHODS
	void itemLookUp();
	void itemMod();
	void addItem();
	void removeItem();
	void itemOrder();//TBI
	
	void CustomerManagement();
	//MORE CUSTOMER METHODS
	void CustLookUp();
	void AddCust();
	void RemCust();
	void EditCust();
	
	void EmployeeManagement();
	//MPRE EMPLOYEE METHODS
	void EmpLookUp();
	void AddEmp();
	void RemEmp();
	void EditEmp();
	
	void Reports();

};

#endif
