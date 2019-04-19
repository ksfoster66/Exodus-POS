#ifndef TEST_CASE_HPP
#define TEST_CASE_HPP

#include "inventory.hpp"
#include "cust_manager.hpp"
#include "emp_manager.hpp"
#include "order_manager.hpp"
#include "order_generator.hpp"
#include "sales.hpp"

class TestCase{

	Inventory* inv;
	CustManager* custMgr;
	EmpManager* empMgr;
	OrderManager* orderMgr;
	OrderGenerator* orderGen;
	Sales* sales;

public:
	TestCase(Inventory* i, CustManager* cm, EmpManager* em, OrderManager* om, OrderGenerator* og, Sales* s){
		inv = i;
		custMgr = cm;
		empMgr = em;
		orderMgr = om;
		orderGen = og;
		sales = s;
	}
	
	void run();

};

#endif
