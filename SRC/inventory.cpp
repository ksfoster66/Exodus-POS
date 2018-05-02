
#include "item.hpp"
#include "inventory.hpp"

#include <iostream>
	
	/*
	std::map<int, item> inv;//Main map. Key:ItemID. Value:Item
	std::unordered_map<std::string, int> UPC_listing;//Maps the items UPC to the item.
	std::unordered_map<std::string, int> model_listing;//Maps the model number to the item
	
	//current info
	int num_items;//Number of different items in inventory
	int total_count;//Current count of number of individuals items in inventory
	double total_value;//Current value of of individual items in inventory
	
	int num_of_sales_YTD;// Year to date number of sales
	double value_of_sales_YTD;//Year to date value of sales in dollars
	int num_of_sales_MTD;
	double value_of_sales_MTD;
	int num_of_sales_WTD;
	double value_of_sales_WTD;
	int num_of_sales;//The daily number of sales
	double value_of_sales;//The daily value of sales;
	
	//Past info. Lists the most recent sales info for the periods. When the periods update this information is written into a log file for manual searching
	int num_of_sales_AT;
	double value_of_sales_AT;
	int num_of_sales_LM;
	double value_of_sales_LM;
	int num_of_sales_LW;
	double value_of_sales_LW;
	*/
	
	//Inventory::Inventory(){}; //Already defined
	
	//Methods
	//Modifiers
	
	//void inv_maintenance();
	//To be run at the end of business, updates all records
	
	void Inventory::updateSales(int n, double a, double v){//N = number sold, a = actual value of sold items, v - value items were sold at
		total_count -= n;
		total_value -= a;
		
		num_of_sales += n;
		value_of_sales += v;
		
		num_of_sales_WTD += n;
		value_of_sales_WTD += v;
		
		num_of_sales_MTD += n;
		value_of_sales_MTD += v;
		
		num_of_sales_YTD += n;
		value_of_sales_YTD += v;
		
	}
	
	bool Inventory::addItem(Item *i)//Adds an item to inventory
	{//Items default to a stock amount of zero and prices of 10000 until set
		int id = i->getID();
		UPC upc = i->getUPC();
		std::string m = i->getModelNumber();
		
		if ( contains(id) || contains(upc) || contains(m)){
			std::cout << "Error: Item already exists" << std::endl;
			return false;
		}
		
		inv[id] = i;
		UPC_listing[upc.getUPC()] = id;
		model_listing[m] = id;
		
		num_items++;
		
		if (i->getTotalCount() != 0){
			this->total_count += i->getTotalCount();
			this->total_value += (i->getMSRP()*i->getTotalCount());
		}
		
		std::cout << "item successfully added" << std::endl;
		return true;
		
	}
	
	void Inventory::removeItem(int ID)//Removes an item from inventory.
	{//If item still has on hand count items will be billed out as expense. Expense tracking to be added when reports are added 
		Item *i = inv[ID];
		if (i->getTotalCount() != 0){
			this->total_count -= i->getTotalCount();
			this->total_value -= (i->getMSRP()*i->getTotalCount());
		}
		
		UPC_listing.erase(i->getUPC());//gets the string from the UPC object
		model_listing.erase(i->getModelNumber());
		inv.erase(ID);
	}
	void Inventory::addToCount(int itemID, int quantity){
	//Add to the available count of an item //Add error handling
		inv[itemID]->add(quantity);	
	}
	
	void Inventory::subtractFromCount(int itemID, int quantity){
	//Subtract from the available count of an item
		inv[itemID]->subtract(quantity);
	}
	
	void Inventory::sold(std::vector<int> itemIDs, std::vector<int> quantities, std::vector<double> sale_price){
	//Adjusts counts after a sale. If it is a delayed order counts are adjusted in due file accordingly
		int num_sold = 0;
		double value_sold = 0, value_of_sale = 0;
		for (int i = 0; i < itemIDs.size(); i++){
			inv[itemIDs[i]]->sold(quantities[i]);
			num_sold += quantities[i];
			value_sold -= inv[itemIDs[i]]->getMSRP()*quantities[i];
			value_of_sale -= sale_price[i]*quantities[i];
			
		}
		
		updateSales(num_sold, value_sold, value_of_sale);
	}
	
	void Inventory::soldDelayed(std::vector<int> itemIDs, std::vector<int> quantities, std::vector<double> sale_price){
	//Adjusts counts after a sale. If it is a delayed order counts are adjusted in due file accordingly
		int num_sold = 0;
		double value_sold = 0, value_of_sale = 0;
		for (int i = 0; i < itemIDs.size(); i++){
			inv[itemIDs[i]]->soldPending(quantities[i]);
			num_sold += quantities[i];
			value_sold -= inv[itemIDs[i]]->getMSRP()*quantities[i];
			value_of_sale -= sale_price[i]*quantities[i];
			
		}
		
		updateSales(num_sold, value_sold, value_of_sale);
	}
	
	void Inventory::returned(std::vector<int> itemIDs, std::vector<int> quantities, std::vector<double> sale_price){
	//If items are returned they'll be added into the inventory
		int num_return = 0;
		double returned_value = 0, value_of_sale;
		
		for (int i = 0; i < itemIDs.size(); i++){
			inv[itemIDs[i]]->returned(quantities[i]);
			num_return += quantities[i];
			returned_value -= inv[itemIDs[i]]->getMSRP()*quantities[i];
			value_of_sale -= sale_price[i]*quantities[i];
			
		}
		updateSales(-(num_return), -(returned_value), -(value_of_sale));
	}
	
	void Inventory::delay_fulfill(std::vector<int> itemIDs, std::vector<int> quantities){
	//When a delayed order is fulfilled they shall be removed from the due file counting
		for (int i = 0; i < itemIDs.size(); i++){
			inv[itemIDs[i]]->soldPendingDelivered(quantities[i]);
			
		}
	}
	
	void Inventory::damage_out(int ID, int quantity){
	//Marks the item and amounts as damaged
		
		inv[ID]->damageOut(quantity);
			
	}
	
	void Inventory::damage_out(std::vector<int> itemIDs, std::vector<int> quantities){
	//Marks the item and amounts as damaged
		for (int i = 0; i < itemIDs.size(); i++){
			inv[itemIDs[i]]->damageOut(quantities[i]);
			
		}
	}
	
	void Inventory::remove_damaged(int ID, int quantity){
	//Removes the desired item and quantities from damaged
		
		inv[ID]->removeFromDamaged(quantity);
		
	}
	
	void Inventory::remove_damaged(std::vector<int> itemIDs, std::vector<int> quantities){
	//Removes the desired item and quantities from damaged
		for (int i = 0; i < itemIDs.size(); i++){
			inv[itemIDs[i]]->removeFromDamaged(quantities[i]);
			
		}
	}
	
	//void Inventory::create_order(std::vector<int> itemIDs, std::vector<int> quantities)
	//Creates an inventory order
	
	bool Inventory::contains(int n)//Checks if a certain item exists in the system. If the item isn't an UPC code is treated as a item ID
	{
		
		if (inv.find(n) == inv.end()) return false;
		return true;
	}
	
	bool Inventory::contains(std::string m)//Checks if a certain item is in the system based on the model number
	{
		if (model_listing.find(m) == model_listing.end()) return false;
		return true;
	}
	
	bool Inventory::contains(UPC u)//Checks if a certain item is in the system based on the model number
	{
		if (UPC_listing.find(u.getUPC()) == UPC_listing.end()) return false;
		return true;
	}
	
	//getters and setters
	Item* Inventory::getItem(int n)//Returns item based on either the item number or the UPC code
	{
		
		std::map<int, Item*>::iterator it = inv.find(n);
			
		if (it != inv.end()) return inv[n];
		Item *blank;
		return blank;
	}
	
	Item* Inventory::getItem(std::string m)//Returns the item based on model number
	{
		std::unordered_map<std::string, int>::iterator it = model_listing.find(m);
			
		if (it != model_listing.end()){
			int id = model_listing[m];
			return inv[id];
		}
		Item *blank;
		return blank;
		
	}
	
	Item* Inventory::getItem(UPC u)//Returns the item based on model number
	{
		std::unordered_map<std::string, int>::iterator it = UPC_listing.find(u.getUPC());
			
		if (it != model_listing.end()){
			int id = UPC_listing[u.getUPC()];
			return inv[id];
		}
		Item *blank;
		return blank;
		
	}
	
	
	int Inventory::get_num_items()//Number of different items in inventory
	{
		return num_items;
	}
	
	int Inventory::get_total_count()//Current count of number of individuals items in inventory
	{
		return total_count;
	}
	
	double Inventory::get_total_value()//Current value of of individual items in inventory
	{
		return total_value;
	}
	
	int Inventory::get_num_of_sales_YTD()// Year to date number of sales
	{
		return num_of_sales_YTD;
	}
	
	double Inventory::get_value_of_sales_YTD()//Year to date value of sales in dollars
	{
		return value_of_sales_YTD;
	}
	
	int Inventory::get_num_of_sales_MTD()//Month to date number of sales
	{
		return num_of_sales_MTD;
	}
	
	double Inventory::get_value_of_sales_MTD()//Month to date value of sales
	{
	return value_of_sales_MTD;
	}
	
	int Inventory::get_num_of_sales_WTD()//Week to date number of sales
	{
		return num_of_sales_WTD;
	}
	
	double Inventory::get_value_of_sales_WTD()//Week to date value of sales
	{
		return value_of_sales_WTD;
	}
	
	int Inventory::get_num_of_sales()//The daily number of sales
	{
		return num_of_sales;
	}
	
	double Inventory::get_value_of_sales()//The daily value of sales;
	{
		return value_of_sales;
	}
	
	
	int Inventory::get_num_of_sales_AT()//All time
	{
		return num_of_sales_AT;
	}
	
	double Inventory::get_value_of_sales_AT()
	{
		return value_of_sales_AT;
	}
	
	int Inventory::get_num_of_sales_LM()//Last month
	{
		return num_of_sales_LM;
	}
	
	double Inventory::get_value_of_sales_LM()
	{
		return value_of_sales_LM;
	}
	
	int Inventory::get_num_of_sales_LW()//Last week
	{
		return num_of_sales_LW;
	}
	
	double Inventory::get_value_of_sales_LW()
	{
		return value_of_sales_LW;
	}
	
