#include "cli.hpp"
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

	/*
	Inventory* inv;
	CustManager* custMgr;
	EmpManager* empMgr;
	OrderManager* orderMgr;
	OrderGenerator* orderGen;
	Sales* sales;
	*/

void PressAKeyToContinue()
  {
  	int c;
  	printf( "\nPress a key to continue..." );
 	while ((c = getchar()) != '\n' && c != EOF) {
    
	}
  }

void CLI::run(){
	bool run = true;
	
	std::cout << "Welcome to Exodus!" << std::endl;
	
	while(run){
		
		std::cout << "\nMenu options:" << std::endl;
		std::cout << "1: Sales Entry" << std::endl;
		std::cout << "2: Order Management" << std::endl;
		std::cout << "3: Inventory Management" << std::endl;
		std::cout << "4: Customer Management" << std::endl;
		std::cout << "5: Employee Management" << std::endl;
		std::cout << "6: Reports" << std::endl;
		std::cout << "0: Exit" << std::endl;
		
		int in = -1;
		
		std::cin >> in;
		std::cout << std::endl;
		
		switch (in){
			default: std::cout << "Invalid entry" << std::endl;  
					break;
			case 0: run = false;
					break;
			case 1: SalesEntry();
					break;
			case 2: OrderManagement();
					break;
			case 3: InventoryManagement();
					break;
			case 4: CustomerManagement();
					break;
			case 5: EmployeeManagement();
					break;
			case 6: Reports();
					break;			
		}
		std::cout << std::endl;
		
	}
	std::cout << "Exodus shutting down" << std::endl;
}



void CLI::SalesEntry(){
	std::cout << "Sales Entry System." << std::endl;
	bool run = true;
	while (run){
		std::cout << "New sale entry.\nPlease enter your sales ID: ";
		int empID;
		std::cin >> empID;
		std::cin.ignore();
		if (!empMgr->contains(empID)){
			std::cout << "Invalid ID entered" << std::endl;
			continue;
		}
		sales->empLookUp(empID);
		
		std::cout << "Is this sale (1)take with, (2) pick up, or (3) delivery?\n: "; 
		int ch;
		std::cin >> ch;
		std::cin.ignore();
		switch(ch){
			default:
			case 1: sales->setSaleType("TW");
					break;
			case 2: sales->setSaleType("PU");
					break;
			case 3: sales->setSaleType("DL");
					break;
		}
		
		bool srun = true;
		while (srun){
			sales->display();			
			std::cout << "Select an option: \n(1) Enter item\t(2) Change Quantity\t(3) Change price\t(4) Remove Item" <<
			"(5) Look up Customer (6) Check out (0) Cancel Sale\n: ";
			std::cin >> ch;
			std::cin.ignore();
			switch(ch){
				default: break;
				case 0: srun = false;
						run = false;
						break;
				case 1: enterItem();
						break;
				case 2: changeQuantity();
						break;
				case 3: changePrice();
						break;
				case 4: removeSaleItem();
						break;
				case 5: lookUpCustomer();
						break;
				case 6: checkout();
						break;
			}
			
		}
	}
	std::cout << "Returning to main menu" << std::endl;
}

void CLI::enterItem(){
	
	std::cout << "Enter the item number, or 0 to cancel: ";
	int id;
	std::cin >> id;
	std::cin.ignore();
	if (id == 0){
		return;
	}
	int quant;
	std::cout << "Enter the quantity" << std::endl;
	std::cin >> quant;
	std::cin.ignore();
	
	sales->enterItem(id, quant);

}
void CLI::changeQuantity(){
	
	int line;
	std::cout << "Line: "<<std::endl;
	std::cin >> line;
	std::cin.ignore();
	
	int quant;
	std::cout << "Quantity: ";
	std::cin >>quant;
	std::cin.ignore();
	
	sales->changeQuantity(line, quant);
	
}
void CLI::changePrice(){
	
	int line;
	std::cout << "Line: "<<std::endl;
	std::cin >> line;
	std::cin.ignore();
	
	double price;
	std::cout << "Price: ";
	std::cin >>price;
	std::cin.ignore();
	
	sales->changePrice(line, price);
}
void CLI::removeSaleItem(){
	
	int line;
	std::cout << "Line: "<<std::endl;
	std::cin >> line;
	std::cin.ignore();
	
	sales->removeItem(line);
}
void CLI::lookUpCustomer(){
	bool run = true;
	while (run){
		int id;
		std::cout << "Please enter the customer number you are searching: ";
		std::cin >> id;
		std::cin.ignore();
		if(!custMgr->contains(id)) {
			std::cout << "Customer does not exist" << std::endl;
			continue;
		}
		sales->custLookUp(id);
		run = false;
	}
}
void CLI::checkout(){
	bool run = true;
	while (run) {
		if (!sales->isCust()){
			std::cout << "Please set a customer first" << std::endl;
			break;
		}
		
		std::cout << "Total due: " << sales->getTotal();
		
		int ch;
		double val;
		
		std::cout << "Please choose a payment option: " << std::endl;
		std::cout << "(1) Cash\t{2} Check\t(3) Debit\t(4) Credit" << std::endl;
		std::cin >> ch;
		std::cin.ignore();
		
		std::cout << "Please enter the amount to pay: " << std::endl;
		std::cin >> val;
		std::cin.ignore();
		
		if(ch == 1){sales->payWithCash(val);}
		else if(ch == 2){sales->payWithCheck(val);}
		else if(ch == 3){sales->payWithDebit(val);}
		else if(ch == 4){sales->payWithCredit(val);}
		
		if(sales->getTotal() <= 0){
			sales->reset();
			run = false;
		}
	}
}




void CLI::OrderManagement(){
	std::cout << "Order Management System." << std::endl;
	bool run = true;
	while (run){
		std::cout << "\nOrder menu options:" << std::endl;
		std::cout << "(1) Find orders" << std::endl;
		std::cout << "(2) Fullfill order" << std::endl;
		std::cout << "(3) Refund Order" << std::endl;
		std::cout << "(0) Exit menu" << std::endl;
		int in;
		std::cin >> in;
		std::cin.ignore();
		
		switch(in){
			default: std::cout << "Invalid entry\n" << std::endl;
					break;
			case 0:	run = false;
					break;
			case 1: orderLookUp();
					break;
			case 2: fulfillOrder();
					break;
			case 3: refundOrder();
					break;
	}
	std::cout << "Returning to main menu" << std::endl;
	}
}

	void CLI::orderLookUp(){
		bool run = true;
		while (run){
			std::cout << "Please enter your serch method:" << std::endl;
			std::cout << "(1) Order number\t(2) Customer\t(3) Employee\t(4) Item number\t(0) Exit" << std::endl;
			int ch;
			std::cin >> ch;
			std::cin.ignore();
			
			if(ch == 0){
				break;
			}
			else if(ch == 1){
				int id;
				std::cout << "Please enter the order number: ";
				std::cin>>id;
				std::cin.ignore();
				if (!orderMgr->contains(id)) {
					std::cout << "Order number was not found" << std::endl;
					continue;
				}
				
				Order* o = orderMgr->getOrder(id);
				std::cout << "Order number: " << id << std::endl;
				std::cout << "Customer: " << o->getCustomer()->getName() << std::endl;
				std::cout << "Employee: " << o->getEmployee()->getName() << std::endl;
				std::vector<int> ids = o->getItemsDue();
				std::vector<int> quant = o->getQuantitiesDue();
				std::vector<double> prices = o->getPriceSold();
				std::cout << "Item #\t\tQuantity\t\tPrice" << std::endl;
				for (int i = 0; i < ids.size(); i++){
					std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] << std::endl;
				}
				PressAKeyToContinue();
			}
			else if(ch == 2){
				int id;
				std::cout << "Please enter the customer number: ";
				std::cin>>id;
				std::cin.ignore();
				
				if(!custMgr->contains(id)) {
					std::cout << "Customer does not exist" << std::endl;
					continue;
				}
				Customer* c = custMgr->getCustomer(id);
				std::vector<Order*> os = orderMgr->getOrders(c);
				
				bool selector = true;
				while (selector){//Loops to preserve list for selecting orders to view
				
					std::cout << "\tOrder Number:" << std::endl;
					for(int i = 0; i < os.size(); i++){
						std::cout << i + 1 << ":\t" <<os[i]->getOrderNumber() << std::endl;
					}
					
					std::cout << "\nTo view an order enter the listing number, or enter 0 to exit\n:";
					std::cin >> ch;
					std::cin.ignore();
					
					if (ch == 0){
						break;
					}
					else if (ch < 0 || ch > os.size() ){
						std::cout << "Invalid choice" << std::endl;
						continue; 
					}
					else{
						Order* o = os[ch];
						std::cout << "Order number: " << o->getOrderNumber() << std::endl;
						std::cout << "Customer: " << o->getCustomer()->getName() << std::endl;
						std::cout << "Employee: " << o->getEmployee()->getName() << std::endl;
						std::vector<int> ids = o->getItemsDue();
						std::vector<int> quant = o->getQuantitiesDue();
						std::vector<double> prices = o->getPriceSold();
						std::cout << "Item #\t\tQuantity\t\tPrice" << std::endl;
						for (int i = 0; i < ids.size(); i++){
							std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] << std::endl;
						}
						PressAKeyToContinue();
					}
				}
			}
			else if(ch == 3){
			int id;
				std::cout << "Please enter the employee number: ";
				std::cin>>id;
				std::cin.ignore();
				
				if(!empMgr->contains(id)) {
					std::cout << "Employee does not exist" << std::endl;
					continue;
				}
				Employee* e = empMgr->getEmployee(id);
				std::vector<Order*> os = orderMgr->getOrders(e);
				
				bool selector = true;
				while (selector){//Loops to preserve list for selecting orders to view
				
					std::cout << "\tOrder Number:" << std::endl;
					for(int i = 0; i < os.size(); i++){
						std::cout << i + 1 << ":\t" <<os[i]->getOrderNumber() << std::endl;
					}
					
					std::cout << "\nTo view an order enter the listing number, or enter 0 to exit\n:";
					std::cin >> ch;
					std::cin.ignore();
					
					if (ch == 0){
						break;
					}
					else if (ch < 0 || ch > os.size() ){
						std::cout << "Invalid choice" << std::endl;
						continue; 
					}
					else{
						Order* o = os[ch];
						std::cout << "Order number: " << o->getOrderNumber() << std::endl;
						std::cout << "Customer: " << o->getCustomer()->getName() << std::endl;
						std::cout << "Employee: " << o->getEmployee()->getName() << std::endl;
						std::vector<int> ids = o->getItemsDue();
						std::vector<int> quant = o->getQuantitiesDue();
						std::vector<double> prices = o->getPriceSold();
						std::cout << "Item #\t\tQuantity\t\tPrice" << std::endl;
						for (int i = 0; i < ids.size(); i++){
							std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] << std::endl;
						}
						PressAKeyToContinue();
					}
				}
			}
			else if(ch == 4){
				int id;
				std::cout << "Please enter the item number: ";
				std::cin>>id;
				std::cin.ignore();
				
				if(!inv->contains(id)) {
					std::cout << "Item does not exist" << std::endl;
					continue;
				}
				std::vector<Order*> os = orderMgr->getOrders(id);
				
				bool selector = true;
				while (selector){//Loops to preserve list for selecting orders to view
				
					std::cout << "\tOrder Number:" << std::endl;
					for(int i = 0; i < os.size(); i++){
						std::cout << i + 1 << ":\t" <<os[i]->getOrderNumber() << std::endl;
					}
					
					std::cout << "\nTo view an order enter the listing number, or enter 0 to exit\n:";
					std::cin >> ch;
					std::cin.ignore();
					
					if (ch == 0){
						break;
					}
					else if (ch < 0 || ch > os.size() ){
						std::cout << "Invalid choice" << std::endl;
						continue; 
					}
					else{
						Order* o = os[ch];
						std::cout << "Order number: " << o->getOrderNumber() << std::endl;
						std::cout << "Customer: " << o->getCustomer()->getName() << std::endl;
						std::cout << "Employee: " << o->getEmployee()->getName() << std::endl;
						std::vector<int> ids = o->getItemsDue();
						std::vector<int> quant = o->getQuantitiesDue();
						std::vector<double> prices = o->getPriceSold();
						std::cout << "Item #\t\tQuantity\t\tPrice" << std::endl;
						for (int i = 0; i < ids.size(); i++){
							std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] << std::endl;
						}
						PressAKeyToContinue();
					}
				}
			}
			else{
				std::cout << "Invalid choice" << std::endl;
				continue;
			}
		}
	}
	
	void CLI::fulfillOrder(){
		bool run = true;
		while (run){
			std::cout << "Please enter the order number, or 0 to exit" << std::endl;
			int id;
			std::cin >> id;
			std::cin.ignore();
			if(id == 0) {
				run = false;
				break;
			}
			if (!orderMgr->contains(id)) {
				std::cout << "Order number was not found" << std::endl;
				continue;
			}
			Order* o = orderMgr->getOrder(id);
			std::vector<int> ids = o->getItemsDue();
			std::vector<int> quant = o->getQuantitiesDue();
			std::vector<double> prices = o->getPriceSold();
			std::vector<int> list;
			
			std::cout << "Item #\t\tQuantity\t\tPrice" << std::endl;
			int val;
			for (int i = 0; i < ids.size(); i++){
				std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] << std::endl;
			}
			
			std::cout << "Fullfill entire order? (y/n)\n: ";
			std::string in;
			std::cin >> in;
			std::cin.ignore();
			
			if(in == "y"){
				orderMgr->fulfillOrder(id);
			}
			
			else{
				std::cout << "Item #\t\tQuantity\t\tPrice\t\tFulfilled" << std::endl;
				int val;
				for (int i = 0; i < ids.size(); i++){
					std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] <<  "\t\t: " << std::endl;
					std::cin >> val;
					std::cin.ignore();
					list.push_back(val);
				}
				
				orderMgr->fulfillOrder(id, list);
			}
			
		}
	}
	
	void CLI::refundOrder(){
		bool run = true;
		while (run){
			std::cout << "Please enter the order number, or 0 to exit" << std::endl;
			int id;
			std::cin >> id;
			std::cin.ignore();
			if(id == 0) {
				run = false;
				break;
			}
			if (!orderMgr->contains(id)) {
				std::cout << "Order number was not found" << std::endl;
				continue;
			}
			Order* o = orderMgr->getOrder(id);
			std::vector<int> ids = o->getItemsDue();
			std::vector<int> quant = o->getQuantitiesDue();
			std::vector<double> prices = o->getPriceSold();
			std::vector<int> list;
			
			std::cout << "Item #\t\tQuantity\t\tPrice" << std::endl;
			int val;
			for (int i = 0; i < ids.size(); i++){
				std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] << std::endl;
			}
			
			std::cout << "Refund entire order? (y/n)\n: ";
			std::string in;
			std::cin >> in;
			std::cin.ignore();
			
			if(in == "y"){
				orderMgr->refundOrder(id);
			}
			
			else{
				std::cout << "Item #\t\tQuantity\t\tPrice\t\tRefundedd" << std::endl;
				int val;
				for (int i = 0; i < ids.size(); i++){
					std::cout << ids[i] << "\t\t" << quant[i] << "\t\t" << prices[i] <<  "\t\t: " << std::endl;
					std::cin >> val;
					std::cin.ignore();
					list.push_back(val);
				}
				
				orderMgr->refundOrder(id, list);
			}
			
		}
	}



void CLI::InventoryManagement(){
	std::cout << "Inventory Management System." << std::endl;
	bool run = true;
	while (run){
		std::cout << "\nInventory menu options:" << std::endl;
		std::cout << "1: Item look up" << std::endl;
		std::cout << "2: Item modification" << std::endl;
		std::cout << "3: Item Addition" << std::endl;
		std::cout << "4: Item Removal" << std::endl;
		std::cout << "5: Item ordering" << std::endl;
		std::cout << "0: Return to main menu" << std::endl;
		int in;
		std::cin >> in;
		std::cin.ignore();
		
		switch(in){
			default: std::cout << "Invalid entry\n" << std::endl;
					break;
			case 0:	run = false;
					break;
			case 1: itemLookUp();
					break;
			case 2: itemMod();
					break;
			case 3: addItem();
					break;
			case 4: removeItem();
					break;
			case 5: itemOrder();
					break;
		}
	}
	std::cout << "Returning to main menu" << std::endl;
}

//MORE INVENTORY METHODS
	void CLI::itemLookUp(){
		bool run = true;
		while (run){
			std::cout << "\nEnter an item number or UPC to look up or enter 0 to exit: ";
			int in;
			std::cin >> in;
			if (in == 0) break;
			Item* it;
			if(inv->contains(in)){
				it = inv->getItem(in);
				
				std::cout << "Item number: " << it->getID() << std::endl;
				std::cout << "Item UPC: " << it->getUPC() << std::endl;
				std::cout << "Item Model number: " << it->getModelNumber() << std::endl;
				std::cout << "Item name: " << it->getName() << std::endl;
				std::cout << "Item description: " << it->getDescription() << std::endl;
				std::cout << "Item type: " << it->getType() << std::endl;
				std::cout << "Department: " << it->getDepartment() << std::endl;
				std::cout << "Item stock code: " << it->getStock() << std::endl;
				
				std::cout << "Counts\nTotal: " << it->getTotalCount() << std::endl;
				std::cout << "Available: " << it->getAvailableCount() << std::endl;
				std::cout << "Due: " << it->getDue() << std::endl;
				std::cout << "Damaged: " << it->getDamagedCount() << std::endl;
				std::cout << "Ordered: " << it->getOrdered() << std::endl;
				std::cout << "Sold: " << it->getSold() << std::endl;
				
			}
			else{
				std::cout << "Item not found." << std::endl;
				continue;
			}
		}
	
	}
	
	void CLI::itemMod(){
		bool run = true;
		while (run){
			std::cout << "Enter the item number you would like to edit: ";
			std::string in;
			int id;
			std::cin >> id;
			std::cin.ignore();
			if (!inv->contains(id)) {
				std::cout << "Invalid ID number" << std::endl;
				continue;
			}
			std::cout << "What would you like to edit?" << std::endl;
			std::cout << "(1) Adjust counts\n(2) Adjust prices\n(3) Alter item info\n(0) Exit" << std::endl;
			std::cin >> in;
			std::cin.ignore();
			if(in == "0"){ break;}
			else if(in == "1"){
				std::cout << "Please enter the change you'd like to make in the following format:";
				std::cout << "add x | remove x | dam (+-)x\n: ";
				std::cin >> in;
				std::cin.ignore();
				std::string s [3];
				int count = 0;
				for (int i = 0; i < in.length(); i++){
					if (count == 0 && in[i] != ' '){
						s[0].push_back(in[i]);
					}
					else if(count == 0 && in[i] == ' ') count++;
					else if(count == 1){
						if (in[i] == '+' || in[i] == '-') {
							s[1].push_back(in[i]);
							count++;
						}
						else{
							s[1].push_back('+');
							count++;
						}
					}
					else if(count == 2){
						s[2].push_back(in[i]);
					}
				}
				int val = std::stoi(s[2]);
				if (s[0] == "add"){
					inv->addToCount(id, val);
				}
				else if (s[0] == "remove"){
					inv->subtractFromCount(id, val);
				}
				else if (s[0] == "dam"){
					if(s[1] == "+"){
						inv->damage_out(id, val);
					}
					else if (s[1] == "-"){
						inv->remove_damaged(id, val);
					}
				}
				else{
					std::cout << "Invalid command entered" << std::endl;
				} 
			}
			else if(in == "2"){
				std::cout << "Please enter the price you would like to change: ";
				std::cout << "(1) MSRP\t(2)Cost\t(3)Sale price\t(0)Cancel\n";
				std::cin >> in;
				std::cin.ignore();
				
				if(in == "0"){continue;}
				else if(in == "1"){
					std::cout << "The current MSRP is $" << inv->getItem(id)->getMSRP() << std::endl;
					double val;
					std::cout << "Please enter the new MSRP: ";
					std::cin >> val;
					std::cin.ignore();
					inv->getItem(id)->setMSRP(val);
				}
				else if(in == "2"){
					std::cout << "The current cost is $" << inv->getItem(id)->getCost() << std::endl;
					double val;
					std::cout << "Please enter the new cost: ";
					std::cin >> val;
					std::cin.ignore();
					inv->getItem(id)->setCost(val);
				}
				else if(in == "3"){
					std::cout << "The current price is $" << inv->getItem(id)->getPrice() << std::endl;
					double val;
					std::cout << "Please enter the new price(set to 0 for MSRP): ";
					std::cin >> val;
					std::cin.ignore();
					inv->getItem(id)->setPrice(val);
				}
				else{
					std::cout << "Invalid command entered" << std::endl;
				}
			}
			else if(in == "3"){
				std::cout << "Please enter the information you would like to change: ";
				std::cout << "(1) Name\t(2)Description\t(3)Type\t(4)Department\t(5) Change Supplier\t(6) Change stock code\t(0)Cancel\n";
				std::cin >> in;
				std::cin.ignore();
				
				if(in == "0"){continue;}
				else if(in == "1"){
					std::cout << "The current name is: " << inv->getItem(id)->getName() << std::endl;
					std::cout << "Please enter the new name: ";
					std::cin >> in;
					std::cin.ignore();
					inv->getItem(id)->updateName(in);
				}
				else if(in == "2"){
					std::cout << "The current decription is: \n" << inv->getItem(id)->getDescription() << std::endl;
					std::cout << "Please enter the new description: ";
					std::cin >> in;
					std::cin.ignore();
					inv->getItem(id)->updateDescription(in);
				}
				else if(in == "3"){
					std::cout << "The current type is: " << inv->getItem(id)->getType() << std::endl;
					std::cout << "Please enter the new type: ";
					std::cin >> in;
					std::cin.ignore();
					inv->getItem(id)->changeType(in);
				}
				else if(in == "4"){
					std::cout << "The current department is: " << inv->getItem(id)->getDepartment() << std::endl;
					std::cout << "Please enter the new department: ";
					std::cin >> in;
					std::cin.ignore();
					inv->getItem(id)->setDepartment(in);
				}
				else if(in == "5"){
					std::cout << "The current supplier is: " << inv->getItem(id)->getSupplier() << std::endl;
					std::cout << "Please enter the new supplier: ";
					std::cin >> in;
					std::cin.ignore();
					inv->getItem(id)->changeSupplier(in);
				}
				else if(in == "6"){
					std::cout << "The current stock code is: " << inv->getItem(id)->getType() << std::endl;
					std::cout << "Please select the new stock code:\n";
					std::cout << "a = Available, c = clearance, d = discontinued, s = special order, r = recall\n: ";
					std::cin >> in;
					std::cin.ignore();
					if(in == "a"){inv->getItem(id)->changeStockStatus("available");}
					else if(in == "c"){inv->getItem(id)->changeStockStatus("clearance");}
					else if(in == "d"){inv->getItem(id)->changeStockStatus("discontinued");}
					else if(in == "s"){inv->getItem(id)->changeStockStatus("special");}	
					else if(in == "r"){inv->getItem(id)->changeStockStatus("recall");}
					else {
						std::cout << "Invalid stock type" << std::endl;
						continue;
					}
				}
				else{
					std::cout << "Invalid command entered" << std::endl;
				}
			}
			else{
				std::cout << "Invalid entry" << std::endl;
				continue;
			}
		}
	}
	
	void CLI::addItem(){
		bool run = true;
		
		while (run){
			std::string model_num;
			
			std::string upc_code;
			
			std::string name;
			std::string description;
			std::string type;
			std::string supplier;
			std::string stock_code;
			int stock_type;
			
			double MSRP;
			double cost;
			double current_price;
			
			std::cout << "To enter an item into the system please provide the following information: " << std::endl;
			std::cout << "Enter the model number: ";
			std::cin >> model_num;
			std::cin.ignore();
			
			std::cout << "Enter the UPC: ";
			std::cin >> upc_code;
			UPC* upc= new UPC(upc_code);
			std::cin.ignore();
			
			std::cout << "Enter product name: ";
			std::cin >> name;
			std::cin.ignore();
			
			std::cout << "Enter product description: ";
			std::cin >> description;
			std::cin.ignore();
			
			std::cout << "Enter product type: ";
			std::cin >> type;
			std::cin.ignore();
			
			std::cout << "Enter product supplier: ";
			std::cin >> supplier;
			std::cin.ignore();
			
			std::cout << "Enter item's stock code: \n(1)Available\t(2)Special\n";
			std::cin >> stock_type;
			std::cin.ignore();
			if( stock_type == 1){
				stock_code = "available";
			}
			else{
				stock_code = "special";
			}
			
			std::cout << "Enter the product MSRP: ";
			std::cin >> MSRP;
			std::cin.ignore();
			
			std::cout << "Enter the product cost: ";
			std::cin >> cost;
			std::cin.ignore();
			
			std::cout << "Enter the product current price. Enter 0 for price equal to MSRP.\n";
			std::cin >> current_price;
			std::cin.ignore();
			
			Item* i = new Item(upc, model_num, name, description, type, supplier, stock_code, current_price, MSRP, cost);
			
			std::cout << "Item entered. Item number generated: " << i->getID() << std::endl; 
			
			inv->addItem(i);
			
			std::cout << "Enter another item? : ";
			std::string in;
			std::cin >> in;
			if (in == "n") run = false;
		}
	}
	
	void CLI::removeItem(){
		bool run = true;
		std::string in;
		while(run){
			int id;
			std::cout << "Please enter the item number to remove: ";
			std::cin >> id;
			std::cin.ignore();
			std::cout << "Are you sure you want to remove " << id << "? y/n\n";
			std::cin >> in;
			std::cin.ignore();
			if (in == "n") break;
			inv->removeItem(id);
			std::cout << "Remove more items? y/n\n";
			std::cin >> in;
			std::cin.ignore();
			if (in == "n") break;
		}
	}
	
	void CLI::itemOrder(){//TBI
		std::cout << "TO be Implemented" << std::endl;
	}
	
	
	

void CLI::CustomerManagement(){
	std::cout << "Customer Management System." << std::endl;
	bool run = true;
	while (run){
		std::cout << "Customer management menu.\n";
		std::cout << "(1) Customer look up" << std::endl;
		std::cout << "(2) Add customer" << std::endl;
		std::cout << "(3) Remove customer" << std::endl;
		std::cout << "(4) Edit customer info" << std::endl;
		std::cout << "(0) Exit menu" << std::endl;
		
		int in;
		std::cin >> in;
		std::cin.ignore();
		
		switch(in){
			default: std::cout << "Invalid entry" << std::endl;
					break;
			case 0: run = false;
					break;
			case 1: CustLookUp();
					break;
			case 2: AddCust();
					break;
			case 3: RemCust();
					break;
			case 4: EditCust();
					break;
		}
	}
	std::cout << "Returning to main menu" << std::endl;
}

	//Customer management methods
	void CLI::CustLookUp(){
		bool run = true;
			while (run){
			std::cout << "Please select a search method: ";
			std::cout << "(1) Last Name\t(2) Phone Number\t(3) Customer ID\t(0) Cancel\n: ";
			int ch;
			std::cin >> ch;
			std::cin.ignore();
			if( ch == 0){
				std::cout << "Invalid entry" << std::endl;
				break;
			}
			else if(ch == 1){
				std::string in;
				std::cout << "Please enter the name you are searching for: ";
				std::cin >> in;
				std::cin.ignore();
				std::vector<Customer*> results = custMgr->getCustomersByName(in);
				std::cout << "ID\t\tName\t\tPhone Number\tEmail Address" << std::endl;
				for (int i = 0; i < results.size(); i++){
					std::cout << results[i]->getID() << "\t\t" << results[i]->getName() << "\t";
					std::cout << results[i]->getPhoneNumber() << "\t" << results[i]->getEmail() << std::endl;
				}
			}
			else if(ch == 2){
				std::string in;
				std::cout << "Please enter the phone number you are searching: ";
				std::cin >> in;
				std::cin.ignore();
				std::vector<Customer*> results = custMgr->getCustomersByPhone(in);
				std::cout << "ID\t\tName\t\tPhone Number\tEmail Address" << std::endl;
				for (int i = 0; i < results.size(); i++){
					std::cout << results[i]->getID() << "\t\t" << results[i]->getName() << "\t";
					std::cout << results[i]->getPhoneNumber() << "\t" << results[i]->getEmail() << std::endl;
				}
			}
			else if(ch == 3){
				int id;
				std::cout << "Please enter the customer number you are searching: ";
				std::cin >> id;
				std::cin.ignore();
				Customer* c = custMgr->getCustomer(id);
				std::cout << "ID\t\tName\t\tPhone Number\tEmail Address" << std::endl;
				std::cout << c->getID() << "\t\t" << c->getName() << "\t";
				std::cout << c->getPhoneNumber() << "\t" << c->getEmail() << std::endl;
			}
			else{
				std::cout << "Invalid entry" << std::endl;
				continue;
			}
		}
	}
	
	void CLI::AddCust(){
		bool run = true;
		while (run){
			std::cout << "Please enter the following information to enter a new customer: ";
			std::string fname;
			std::string lname;
			std::string phone;
			std::string email;
			std::string address;
			
			std::cout << "Enter the customers first name: ";
			std::cin >> fname;
			std::cin.ignore();
			
			std::cout << "Enter the customers last name: ";
			std::cin >> lname;
			std::cin.ignore();
			
			std::cout << "Enter the customers phone number: ";
			std::cin >> phone;
			std::cin.ignore();
			
			Customer* c = new Customer(fname, lname, phone);
			
			std::string in;
			std::cout << "Is there an email to enter? (y/n): ";
			std::cin >> in;
			std::cin.ignore();
			if (in == "y"){
				std::cout << "Enter the customers email: ";
				std::cin >> email;
				std::cin.ignore();
				
				c->setEmail(email);
			}
			
			std::cout << "Is there an andress to enter? (y/n): ";
			std::cin >> in;
			std::cin.ignore();
			if (in == "y"){
				std::cout << "Enter the customers address: ";
				std::cin >> address;
				std::cin.ignore();
				
				c->setAddress(address);
			}
			
			std::cout << "The customer's ID is " << c->getID() << std::endl;
			
			custMgr->addCustomer(c);
			while(true){
				std::cout << "\nEnter another customer? (y/n): ";
				std::cin >> in;
				std::cin.ignore();
				if (in == "n"){
					run = false;
					break;
				}
				else if(in == "y"){
					break;
				}
				else{
					std::cout <<"Invalid entry" << std::endl;
				}
			}
		}
	}
	
	void CLI::RemCust(){
		bool run = true;
		while (run){
			std::cout << "Please enter the cusotmer number to remove: ";
			int id;
			std::cin >> id;
			std::cin.ignore();
			custMgr->removeCustomer(id);
		}
	}
	
	void CLI::EditCust(){
		bool run = true;
		while (run){
			std::cout << "Please enter the customer ID to edit: ";
			int id;
			std::cin >> id;
			std::cin.ignore();
			if(!custMgr->contains(id)) {
				std::cout << "Customer does not exist" << std::endl;
				continue;
			}
			
			Customer* c = custMgr->getCustomer(id);
			std::cout << "ID\t\tName\t\tPhone Number\tEmail Address\t\tAddress" << std::endl;
			std::cout << c->getID() << "\t\t" << c->getName() << "\t";
			std::cout << c->getPhoneNumber() << "\t" << c->getEmail() << "\t\t" << c->getAddress() << std::endl;
			
			std::cout << "What would you like to edit?" << std::endl;
			std::cout << "(1) Phone number\t(2) Email address\t(3) Address\t(0) Cancel\n: ";
			
			int ch;
			std::cin >> ch;
			std::cin.ignore();
			
			if (ch == 0){
				continue;
			}
			else if(ch == 1){
				std::cout << "Enter the new phone number: ";
				std::string in;
				std::cin >> in;
				std::cin.ignore();
				c->setPhoneNumber(in);
			}
			else if(ch == 2){
				std::cout << "Enter the new email address: ";
				std::string in;
				std::cin >> in;
				std::cin.ignore();
				c->setEmail(in);
			}
			else if(ch == 3){
				std::cout << "Enter the new address: ";
				std::string in;
				std::cin >> in;
				std::cin.ignore();
				c->setAddress(in);
			}
			else{
				std::cout << "Invalid choice" << std::endl;
				continue;
			}
		}
	}




void CLI::EmployeeManagement(){
	std::cout << "Employee Management System." << std::endl;
	bool run = true;
	while (run){
		std::cout << "Employee management menu.\n";
		std::cout << "(1) Employee look up" << std::endl;
		std::cout << "(2) Add employee" << std::endl;
		std::cout << "(3) Remove employee" << std::endl;
		std::cout << "(4) Edit employee info" << std::endl;
		std::cout << "(0) Exit menu" << std::endl;
		
		int in;
		std::cin >> in;
		std::cin.ignore();
		
		switch(in){
			default: std::cout << "Invalid entry" << std::endl;
					break;
			case 0: run = false;
					break;
			case 1: EmpLookUp();
					break;
			case 2: AddEmp();
					break;
			case 3: RemEmp();
					break;
			case 4: EditEmp();
					break;
		}
	}
	std::cout << "Returning to main menu" << std::endl;
}
	
	//Customer management methods
	void CLI::EmpLookUp(){
		bool run = true;
			while (run){
			std::cout << "Please select a search method: ";
			std::cout << "(1) Last Name\t(2) Employee ID\t(0) Cancel\n: ";
			int ch;
			std::cin >> ch;
			std::cin.ignore();
			if( ch == 0){
				std::cout << "Invalid entry" << std::endl;
				break;
			}
			else if(ch == 1){
				std::string in;
				std::cout << "Please enter the name you are searching for: ";
				std::cin >> in;
				std::cin.ignore();
				std::vector<Employee*> results = empMgr->getEmployees(in);
				std::cout << "ID\t\tName\t\tPhone Number" << std::endl;
				for (int i = 0; i < results.size(); i++){
					std::cout << results[i]->getID() << "\t\t" << results[i]->getName() << "\t";
					std::cout << results[i]->getPhoneNumber() << std::endl;
				}
			}
			else if(ch == 2){
				int id;
				std::cout << "Please enter the employee number you are searching: ";
				std::cin >> id;
				std::cin.ignore();
				Employee* e = empMgr->getEmployee(id);
				std::cout << "ID\t\tName\t\tPhone Number" << std::endl;
				std::cout << e->getID() << "\t\t" << e->getName() << "\t";
				std::cout << e->getPhoneNumber() << std::endl;
			}
			else{
				std::cout << "Invalid entry" << std::endl;
				continue;
			}
		}
	}
	
	void CLI::AddEmp(){
		bool run = true;
		while (run){
			std::cout << "Please enter the following information to enter a new employee: ";
			std::string fname;
			std::string lname;
			std::string phone;
			
			std::cout << "Enter the employeess first name: ";
			std::cin >> fname;
			std::cin.ignore();
			
			std::cout << "Enter the employees last name: ";
			std::cin >> lname;
			std::cin.ignore();
			
			Employee* e = new Employee(fname, lname);
			
			std::string in;
			std::cout << "Is there a phone number to enter? (y/n): ";
			std::cin >> in;
			std::cin.ignore();
			if (in == "y"){
				std::cout << "Enter the customers email: ";
				std::cin >> phone;
				std::cin.ignore();
				
				e->setPhoneNumber(phone);
			}
			
			
			std::cout << "The employee's ID is " << e->getID() << std::endl;
			
			empMgr->addEmployee(e);
			
			while(true){
				std::cout << "\tEnter another Employee? (y/n): ";
				std::cin >> in;
				std::cin.ignore();
				if (in == "n"){
					run = false;
					break;
				}
				else if(in == "y"){
					break;
				}
				else{
					std::cout <<"Invalid entry" << std::endl;
				}
			}
		}
	}
	
	void CLI::RemEmp(){
		bool run = true;
		while (run){
			std::cout << "Please enter the employee number to remove: ";
			int id;
			std::cin >> id;
			std::cin.ignore();
			empMgr->removeEmployee(id);
		}
	}
	
	void CLI::EditEmp(){
		bool run = true;
		while (run){
			std::cout << "Please enter the Employee ID to edit, or 0 to exit: ";
			int id;
			std::cin >> id;
			std::cin.ignore();
			
			if (id == 0) break;
			if (!empMgr->contains(id)){
				std::cout << "Could not find employee id " << id << std::endl;
				continue;
			}
			
			Employee* e = empMgr->getEmployee(id);
			std::cout << "ID\t\tName\t\tPhone Number" << std::endl;
			std::cout << e->getID() << "\t\t" << e->getName() << "\t";
			std::cout << e->getPhoneNumber() << std::endl;
			
			std::cout << "Enter the new phone number: ";
			std::string in;
			std::cin >> in;
			std::cin.ignore();
			e->setPhoneNumber(in); 
		}
	}

void CLI::Reports(){
	std::cout << "There is nothing here yet. Reports are not yet a thing." << std::endl;
}


