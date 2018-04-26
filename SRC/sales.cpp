#include "sales.hpp"

	/*
	Inventory* inv;
	OrderManager* orderMgr;
	CustManager* custMgr;
	
	Customer* cust;
	Employee* emp;
	
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
	Sales::Sales(Inventory* i, OrderManager* m, CustManager* c, Employee* e, double localTaxRate){
		inv = i;
		orderMgr = m;
		custMgr = c;
		emp = e;
		
		sale_type = 0;
		
		taxRate = localTaxRate;
		
		finalised = false;
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
			case 0: return "Take with"
				break;
			case 1: return "Pick up"
				break;
			case 2: "Delivery"
				break;
		}
	}
	void Sales::setSaleType(int i){
		if (finalised){return;}
		
		if (i < 3 || i > -1) sale_type = i;
		else sale_type = 0;
	}
	void Sales::setSaleType(std::string s){
		if (finalised){return;}
		
		if(s == "TW"){
			sale_type = 0;
		}else if(s == "PU"){
			sale_type = 1;
		}else if(s == "DL"){
			sale_type = 2;
		}else{
			sale_type = 0;
		}
	}
	
	//Clear
	void Sales::reset(){
		sale_type = 0;
		
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
	
	void Sales::enterItem(string m, int quant, double p){
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
		
		quantities[line] += quant;
		
		calcLinePrice(line);
		calcTotal();
		
	}
	void Sales::removeItem(int line){
		if (finalised){return;}
		
		ids.erase(ids.begin() + line);
		quantities.erase(quantities.begin() + line);
		prices.erase(prices.begin() + line);
		item_total_prices.erase(item_total_prices.begin() + line);
		ref.erase(ref.begin() + line);		
				
		calcTotal();
	}
	void Sales::changePrice(int line, double price){
		if (finalised){return;}
		
		prices[line] += price;
		calcLinePrice(line);
		calcTotal();
	}
	
	void Sales::calcLinePrice(int line){
		item_total_price[line] = price[line] * quantities[line];
	}
	
	void Sales::calcTotal(){
		subtotal = 0;
		for (int i = 0; i < item_total_price.size(); i++){
			subtotal += item_total_price[i];
		}
		taxes = subtotal * tax_rate;
		total = subtotal + taxes;
	}
	
	//Payment methods
	double Sales::payWithCash(double amount){
		finalised = true;
		
		total -= amount;
		return total;
	}
	double Sales::payWithCheck(double amount){
		finalised = true;
		
		//check processing mechanism
		
		total -= amount;
		return total;
	}
	double Sales::payWithDebit(double amount){
		finalised = true;
		
		//debit card handling mechanism
		
		total -= amount;
		return total;
	}
	double Sales::payWithCredit(double amount){
		finalised = true;
		
		//credit handling mechanism abstraction blah blah blah
		
		total -= amount;
		return total;
	}
	
	//Order generation
	
	void Sales::custLookUp(int id){
		cust = custMgr.getCustomer(id);
	}
	
	//TBI once the Order Generator is implemented
	
	//input and display
	void Sales::run();
	void Sales::display();
