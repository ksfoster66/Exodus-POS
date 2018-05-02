#include "cli.hpp"
#include "inventory.hpp"
#include "cust_manager.hpp"
#include "emp_manager.hpp"
#include "order_manager.hpp"
#include "order_generator.hpp"
#include "sales.hpp"
#include "test_case.hpp"


int main(){
	Inventory inv;
	Inventory* i = &inv;
	
	CustManager custMgr;
	CustManager* cm = &custMgr;
	
	EmpManager empMgr;
	EmpManager* em = &empMgr;
	
	OrderManager orderMgr(i);
	OrderManager* om = &orderMgr;
	
	OrderGenerator orderGen(om, i);
	OrderGenerator* og = &orderGen;
	
	Sales sales(i, om, cm, em, og);
	Sales* s = &sales;
	
	TestCase tc(i, cm, em, om, og, s);
	tc.run();
	
	CLI cli(i, cm, em, om, og, s);
	
	cli.run();
}

