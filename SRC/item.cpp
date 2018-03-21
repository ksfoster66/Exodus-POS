#include "item.hpp"

	/*Fields
	std::string name;
	std::string description;
	std::string type;
	std::string department;
	std::string model_number;
	
	std::string stock;
	std::string supplier;
	
	double current_price;
	double MSRP;
	double cost;
	
	int item_id;
	int upc;
	
	int total_count;
	int available;
	int damaged;
	int total_sold;
	int sold_pending;
	int ordered;
	*/
	
	//Constructor
	item::item(int itemID, int UPC_code, std::string model){
		//Passed arguments
		item_id = itemID;
		upc = UPC_code;
		model_number = model;
		//Defaults
		total_count = 0;
		available = 0;
		damaged = 0;
		total_sold = 0;
		sold_pending = 0;
		ordered = 0;
		
		stock = a;
		cost = 1000;
		MSRP = 1000;
		current_price = 1000;
	}
	
	item::item(int itemID, int UPC_code, std::string model, std::string name, std::string description, std::string type, std::string supplier, std::string stock_code, double current_price, double MSRP, double cost){
		item_id = itemID;
		upc = UPC_code;
		model_number = model;
		
		this->name = name;
		this->description = description;
		this->type = type;
		this->supplier = supplier;
		this->current_price = current_price;
		this->MSRP = MSRP;
		this->cost = cost;
		
		//stock = stock_code;
		
		if(stock_code.compare("available") == 0) stock = a;
		else if(stock_code.compare("clearance") == 0) stock = c;
		else if(stock_code.compare("discontinued") == 0) stock = d;
		else if(stock_code.compare("special") == 0) stock = s;
		else if(stock_code.compare("recall") == 0) stock = r;
		else stock = a;
		
		
		//Defaults
		total_count = 0;
		available = 0;
		damaged = 0;
		total_sold = 0;
		sold_pending = 0;
		ordered = 0;
				
	}
	
	//Modifiers
	std::string item::getName(){
		return name;
	}
	
	void item::updateName(std::string t){
		name = t;
	}
	
	std::string item::getDescription(){
		return description;
	}
	
	void item::updateDescription(std::string t){
		description = t;
	}
	
	std::string item::getType(){
		return type;
	}
	
	void item::changeType(std::string t){
		type = t;
	}
	
	std::string item::getDepartment(){
		return department;
	}
	
	void item::setDepartment(std::string t){
		department = t;
	}
	
	std::string item::getModelNumber(){
		return model_number;
	}
	
	void item::updateModelNumber(std::string t){
		model_number = t;
	}
	
	std::string item::getStock(){
		
		if( stock == a) return "available";
		else if (stock == c) return "clearance";
		else if (stock == d) return "discontinued";
		else if (stock == s) return "special";
		else if (stock == r) return "recall";
		return "error";
	}
	
	void item::changeStockStatus(std::string t){
		if(t.compare("available") == 0) stock = a;
		else if(t.compare("clearance") == 0) stock = c;
		else if(t.compare("discontinued") == 0) stock = d;
		else if(t.compare("special") == 0) stock = s;
		else if(t.compare("recall") == 0) stock = r;
	}
	
	std::string item::getSupplier(){
		return supplier;
	}
	
	void item::changeSupplier(std::string t){
		supplier = t;
	}
	
	double item::getPrice(){
		return current_price;
	}
	
	void item::setPrice(double n){
		current_price = n;
	}
	
	double item::getMSRP(){
		return MSRP;
	}
	
	void item::setMSRP(double n){
		MSRP = n;
	}
	
	double item::getCost(){
		return cost;
	}
	
	void item::setCost(double n){
		cost = n;
	}
	
	int item::getID(){
		return item_id;
	}
	
	int item::getUPC(){
		return upc;
	}
	
	int item::getTotalCount(){
		return total_count;
	}
	
	int item::getAvailableCount(){
		if (available < 0) return 0;
		return available;
	}
	
	int item::getDamagedCount(){
		return damaged;
	}
	
	int item::getSold(){
		return total_sold;
	}
	
	int item::getDue(){
		return sold_pending;
	}
	
	int item::getOrdered(){
		return ordered;
	}
	
	//special inventory modifier methods
	void item::add(int n){
		total_count += n;
		available += n;
	}
	
	void item::subtract (int n){
		total_count -= n;
		available -= n;
	}
	
	void item::inc(){
		total_count++;
		available++;
	}
	
	void item::dec(){
		total_count--;
		available--;
	}
	
	item item::operator++(){
		total_count++;
		available++;
	}
	
	item item::operator++(int){
		total_count++;
		available++;
	}
	
	item item::operator--(){
		total_count--;
		available--;
	}
	
	item item::operator--(int){
		total_count--;
		available--;
	}
	
	item item::operator+=(int n){
		total_count+=n;
		available+=n;
	}
	
	item item::operator -=(int n){
		total_count-=n;
		available-=n;
	}
	
	void item::sold(int n){
		total_count -= n;
		available -= n;
		total_sold += n;
	}
	
	void item::soldPending(int n){
		available -= n;
		sold_pending+= n;
		total_sold += n;
	}
	
	void item::soldPendingDelivered(int n){
		sold_pending -= n;
		total_count -= n;
	}
	
	void item::damageOut (int n){
		available -= n;
		damaged += n;
	}
	
	void item::soldDamaged (int n){
		total_count -= n;
		damaged -= n;
		total_sold += n;
	}
	
		
