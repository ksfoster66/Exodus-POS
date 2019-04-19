#ifndef SALES_HPP
#define SALES_HPP

#include "item.hpp"
#include "inventory.hpp"
#include "order_manager.hpp"
#include "cust_manager.hpp"
#include "employee.hpp"
#include "order_generator.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Sales{
	Inventory* inv;
	OrderManager* orderMgr;
	CustManager* custMgr;
	EmpManager* empMgr;
	
	OrderGenerator* orderGen;
	
	Customer* cust;
	Employee* emp;
	
	bool isCustSet;
	bool isEmpSet;
	
	std::vector<int> ids;
	std::vector<int> quantities;
	std::vector<double> prices;
	std::vector<double> item_total_prices;
	
	std::vector<Item*> ref;
	
	double subtotal;
	double taxes;
	double total;
	double amount_owed;
	double change;
	
	double tax_rate;
	
	enum SaleType{ TAKE_WITH, DELIVERY, PICK_UP};
	SaleType sale_type;
	
	bool finalised;
	
public:
	//Constructor
	Sales(Inventory* i, OrderManager* m, CustManager* c, EmpManager* e, OrderGenerator* o, double localTaxRate=.07);
	
	//getters and setters
	std::vector<int> getItemIDs();
	std::vector<int> getQuantities();
	std::vector<double> getPrices();
	
	double getTotal();
	double getSubtotal();
	double getTaxes();
		
	Employee* getSalesman();
	Customer* getCustomer();
	
	std::string getSaleType();
	void setSaleType(int i);
	void setSaleType(std::string s);
	
	//Clear
	void reset();
	
	//Item entry and modification
	void enterItem(int i, int quant = 1, double p = -1.00);
	void enterItem(std::string m, int quant = 1, double p = -1.00);
	void enterItem(UPC u, int quant = 1, double p = -1.00);
	void changeQuantity(int line, int quantity);
	void removeItem(int line);
	void changePrice(int line, double price);
	
	void calcLinePrice(int line);
	void calcTotal();
	
	//Payment methods
	double payWithCash(double amount);
	double payWithCheck(double amount);
	double payWithDebit(double amount);
	double payWithCredit(double amount);
	
	//Order generation
	bool isCust();
	void custLookUp(int id);
	void empLookUp(int id);
	
	void createOrder();
	
	//Output and display
	void display();
	
};

#endif
