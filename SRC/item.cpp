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
	UPC* upc;
	
	int total_count;
	int available;
	int damaged;
	int total_sold;
	int sold_pending;
	int ordered;
	*/
	int Item::used_id = 0;
	
	//Constructor
	Item::Item(UPC* UPC_code, std::string model): upc(UPC_code){
		//Passed arguments
		item_id = getNewID();
		//upc(UPC_code);
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
	
	Item::Item(UPC* UPC_code, std::string model, std::string name, std::string description, std::string type, std::string supplier, std::string stock_code, double current_price, double MSRP, double cost) : upc(UPC_code){
		item_id = getNewID();
		//upc(UPC_code);
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
	std::string Item::getName(){
		return name;
	}
	
	void Item::updateName(std::string t){
		name = t;
	}
	
	std::string Item::getDescription(){
		return description;
	}
	
	void Item::updateDescription(std::string t){
		description = t;
	}
	
	std::string Item::getType(){
		return type;
	}
	
	void Item::changeType(std::string t){
		type = t;
	}
	
	std::string Item::getDepartment(){
		return department;
	}
	
	void Item::setDepartment(std::string t){
		department = t;
	}
	
	std::string Item::getModelNumber(){
		return model_number;
	}
	
	void Item::updateModelNumber(std::string t){
		model_number = t;
	}
	
	std::string Item::getStock(){
		
		if( stock == a) return "available";
		else if (stock == c) return "clearance";
		else if (stock == d) return "discontinued";
		else if (stock == s) return "special";
		else if (stock == r) return "recall";
		return "error";
	}
	
	void Item::changeStockStatus(std::string t){
		if(t.compare("available") == 0) stock = a;
		else if(t.compare("clearance") == 0) stock = c;
		else if(t.compare("discontinued") == 0) stock = d;
		else if(t.compare("special") == 0) stock = s;
		else if(t.compare("recall") == 0) stock = r;
	}
	
	std::string Item::getSupplier(){
		return supplier;
	}
	
	void Item::changeSupplier(std::string t){
		supplier = t;
	}
	
	double Item::getPrice(){
		if (current_price != 0) return current_price;
		else return MSRP;
	}
	
	void Item::setPrice(double n){
		current_price = n;
	}
	
	double Item::getMSRP(){
		return MSRP;
	}
	
	void Item::setMSRP(double n){
		MSRP = n;
	}
	
	double Item::getCost(){
		return cost;
	}
	
	void Item::setCost(double n){
		cost = n;
	}
	
	int Item::getID(){
		return item_id;
	}
	
	std::string Item::getUPC(){
		return upc->getUPC();
	}
	
	int Item::getTotalCount(){
		return total_count;
	}
	
	int Item::getAvailableCount(){
		if (available < 0) return 0;
		return available;
	}
	
	int Item::getDamagedCount(){
		return damaged;
	}
	
	int Item::getSold(){
		return total_sold;
	}
	
	int Item::getDue(){
		return sold_pending;
	}
	
	int Item::getOrdered(){
		return ordered;
	}
	
	//special inventory modifier methods
	void Item::add(int n){
		total_count += n;
		available += n;
	}
	
	void Item::subtract (int n){
		total_count -= n;
		available -= n;
	}
	
	void Item::inc(){
		total_count++;
		available++;
	}
	
	void Item::dec(){
		total_count--;
		available--;
	}
	
	Item Item::operator++(){
		total_count++;
		available++;
	}
	
	Item Item::operator++(int){
		total_count++;
		available++;
	}
	
	Item Item::operator--(){
		total_count--;
		available--;
	}
	
	Item Item::operator--(int){
		total_count--;
		available--;
	}
	
	Item Item::operator+=(int n){
		total_count+=n;
		available+=n;
	}
	
	Item Item::operator -=(int n){
		total_count-=n;
		available-=n;
	}
	
	void Item::sold(int n){
		total_count -= n;
		available -= n;
		total_sold += n;
	}
	
	void Item::soldPending(int n){
		available -= n;
		sold_pending+= n;
		total_sold += n;
	}
	
	void Item::soldPendingDelivered(int n){
		sold_pending -= n;
		total_count -= n;
	}
	
	void Item::returned(int n){
		total_count+= n;
		available += n;
		total_sold -= n;
	}
	
	void Item::damageOut (int n){
		available -= n;
		damaged += n;
	}
	
	void Item::removeFromDamaged (int n){
		available += n;
		damaged -= n;
	}
	
	void Item::soldDamaged (int n){
		total_count -= n;
		damaged -= n;
		total_sold += n;
	}
	
	int Item::getNewID(){
		used_id++;
		return used_id;
	}
	
		
