#include "sales.hpp"
#include <iostream>

	/*
	Inventory* inv;
	OrderManager* orderMgr;
	CustManager* custMgr;
	EmpManager* empMgr;
	
	OrderGenerator orderGen;
	
	Customer* cust;
	Employee* emp;
	
	bool isCustSet;
	bool isEmpSet;
	
	std::vector<int> ids;
	std::vector<int> quantities;
	std::vector<double> prices;
	std::vector<double> item_total_price;
	
	std::vector<Item*> ref;
	
	double subtotal;
	double taxes;
	double total;
	double amount_owed;
	double change;
	
	double tax_rate;
	
	enum SaleType{ TAKE_WITH, DELIVERY, PICK_UP};
	SaleType sale_type = 0;
	
	bool finalised;
	*/

	//Constructor
	Sales::Sales(Inventory* i, OrderManager* m, CustManager* c, EmpManager* e, OrderGenerator* o, double localTaxRate){
		inv = i;
		orderMgr = m;
		custMgr = c;
		empMgr = e;
		
		orderGen = o;
		
		isCustSet = false;
		isEmpSet = false;
		
		sale_type = TAKE_WITH;
		
		tax_rate = localTaxRate;
		
		finalised = false;
		subtotal = 0;
		taxes = 0;
		total = 0;
		amount_owed = 0;
	}
	
	//getters and setters
	std::vector<int> Sales::getItemIDs(){
		return ids;
	}
	std::vector<int> Sales::getQuantities(){
		return quantities;
	}
	std::vector<double> Sales::getPrices(){
		return prices;
	}
	
	double Sales::getTotal(){
		return total;
	}
	double Sales::getSubtotal(){
		return subtotal;
	}
	double Sales::getTaxes(){
		return taxes;
	}
	
	Employee* Sales::getSalesman(){
		return emp;
	}
	Customer* Sales::getCustomer(){
		return cust;
	}
	
	std::string Sales::getSaleType(){
		switch(sale_type){
			default:
			case 0: return "Take with";
				break;
			case 1: return "Pick up";
				break;
			case 2: "Delivery";
				break;
		}
	}
	void Sales::setSaleType(int i){
		if (finalised){return;}
		
		
		switch(i){
			default:
			case 0 : sale_type = TAKE_WITH;
					break;
			case 1 : sale_type = DELIVERY;
					break;
			case 2 : sale_type = PICK_UP;
					break;
		}
	}
	void Sales::setSaleType(std::string s){
		if (finalised){return;}
		
		if(s == "TW"){
			sale_type = TAKE_WITH;
		}else if(s == "PU"){
			sale_type = PICK_UP;
		}else if(s == "DL"){
			sale_type = DELIVERY;
		}else{
			sale_type = TAKE_WITH;
		}
	}
	
	//Clear
	void Sales::reset(){
		sale_type = TAKE_WITH;
		
		isCustSet = false;
		
		ids.clear();
		quantities.clear();
		prices.clear();
		
		subtotal = 0;
		taxes = 0;
		total = 0;
		
		finalised = false;
	}
	
	//Item entry and modification
	void Sales::enterItem(int i, int quant, double p){
		
		if (finalised){return;}
		
		int id;//Tthe item's id number
		Item* it;//A reference to the item in the inventory
		double price; 
		if( inv->contains(i) ){//Confirm the item is real and get some basic info regarding it
			it = inv->getItem(i);
			id = it->getID();
			if (p != -1.00){
				price = p;
			}
			else{
				price = it->getPrice(); 
			}
		}
		else{
			return;
		}
		
		int line= -1;
		if (ids.empty()){		}//If the checkout list is empty don't bother checking if the item is already in the list
		
		else{
			
			for (int i = 0; i < ids.size(); i++){//Checking if item is already in the list
				if (id == ids[i]){
					if (prices[i] == price)//If it is being sold for a different price don't add to it
					line = i;
					break;
				}
			}
		}
		
		if (line != -1){//If it is in the list and the same price
			quantities[line] += quant;
		}
		else{ //If it isn't in the list
			ids.push_back(id);
			quantities.push_back(quant);
			prices.push_back(price);
			ref.push_back(it);
			item_total_prices.push_back(0.0);
			line = ids.size() - 1;
			std::cout << "Test 8b: Item added" << std::endl;
		}
		
		calcLinePrice(line);
		calcTotal();
		
	}
	
	void Sales::enterItem(std::string m, int quant, double p){
		if (finalised){return;}
		
		int id;//Tthe item's id number
		Item* it;//A reference to the item in the inventory
		double price; 
		if( inv->contains(m) ){//Confirm the item is real and get some basic info regarding it
			it = inv->getItem(m);
			id = it->getID();
			if (p != -1.00){
				price = p;
			}
			else{
				price = it->getPrice(); 
			}
		}
		else{
			return;
		}
		
		int line= -1;
		if (ids.empty()){}//If the checkout list is empty don't bother checking if the item is already in the list
		else{
			for (int i = 0; i < ids.size(); i++){//Checking if item is already in the list
				if (id == ids[i]){
					if (prices[i] == price)//If it is being sold for a different price don't add to it
					line = i;
					break;
				}
			}
		}
		
		if (line != -1){//If it is in the list and the same price
			quantities[line] += quant;
		}
		else{ //If it isn't in the list
			ids.push_back(id);
			quantities.push_back(quant);
			prices.push_back(price);
			ref.push_back(it);
			line = ids.size() - 1;
		}
		calcLinePrice(line);
		calcTotal();
	}
	
	void Sales::changeQuantity(int line, int quantity){
		if (finalised){return;}
		int i = line -1;
		quantities[i] = quantity;
		
		calcLinePrice(i);
		calcTotal();
		
	}
	void Sales::removeItem(int line){
		if (finalised){return;}
		
		int i = line - 1;
		
		ids.erase(ids.begin() + i);
		quantities.erase(quantities.begin() + i);
		prices.erase(prices.begin() + i);
		item_total_prices.erase(item_total_prices.begin() + i);
		ref.erase(ref.begin() + i);		
				
		calcTotal();
	}
	void Sales::changePrice(int line, double price){
		if (finalised){return;}
		int i = line -1;
		prices[i] = price;
		calcLinePrice(i);
		calcTotal();
	}
	
	void Sales::calcLinePrice(int line){
		item_total_prices[line] = prices[line] * quantities[line];
	}
	
	void Sales::calcTotal(){
		subtotal = 0;
		for (int i = 0; i < item_total_prices.size(); i++){
			subtotal += item_total_prices[i];
		}
		taxes = subtotal * tax_rate;
		total = subtotal + taxes;
	}
	
	//Payment methods
	double Sales::payWithCash(double amount){
		if(!isCustSet) return -1.00;
		if(!isEmpSet) return -2.00;
		finalised = true;
		
		total -= amount;
		return total;
	}
	double Sales::payWithCheck(double amount){
		if(!isCustSet) return -1.00;
		if(!isEmpSet) return -2.00;
		finalised = true;
		
		//check processing mechanism
		
		total -= amount;
		return total;
	}
	double Sales::payWithDebit(double amount){
		if(!isCustSet) return -1.00;
		if(!isEmpSet) return -2.00;
		finalised = true;
		
		//debit card handling mechanism
		
		total -= amount;
		return total;
	}
	double Sales::payWithCredit(double amount){
		if(!isCustSet) return -1.00;
		if(!isEmpSet) return -2.00;
		finalised = true;
		
		//credit handling mechanism abstraction blah blah blah
		
		total -= amount;
		
		if( total <= 0){
			createOrder();
		}
		
		return total;
	}
	
	//Order generation
	bool Sales::isCust(){
		return isCustSet;
	}
	
	void Sales::custLookUp(int id){
		cust = custMgr->getCustomer(id);
		isCustSet = true;
	}
	
	void Sales::empLookUp(int id){
		emp = empMgr->getEmployee(id);
		isEmpSet = true;
	}
	
	void Sales::createOrder(){
		orderGen->createOrder(ids, quantities, prices, cust, emp);
	}
	
	//input and display
	void Sales::display(){
		std::cout << "Line\tItem ID\tQuantity\tPrice\tTotal" << std::endl;
		for (int i = 0; i < ids.size(); i++){
			std::cout << i + 1 << "\t" << ids[i] << "\t" << quantities[i] << "\t" << prices[i] << "\t" << item_total_prices[i]<< std::endl;
		}
		std::cout <<"\t\t\tSubtotal:\t" << subtotal <<"\n\t\t\tTaxes\t"<<taxes<<"\n\t\t\tTotal\t"<<total<<std::endl; 
	}
	
	
