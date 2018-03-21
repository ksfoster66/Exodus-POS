//TODO add Inventory order support once supported

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <map>
#include <unordered_map>
#include "item.hpp"


class inventory{
private:
	//Fields
	//Inventory maps
	std::map<int, item> inv;//Main map. Key:ItemID. Value:Item
	std::unordered_map<int, int> UPC_listing;//Maps the items UPC to the item.
	std::unordered_map<std::string, int> model_listing;//Maps the model number to the item
	
	//current info
	int num_items;//Number of different items in inventory
	int total_count;//Current count of number of individuals items in inventory
	double total_value;//Current value of of individual items in inventory
	int num_of_sales_YTD;
	double value_of_sales_YTD;
	int num_of_sales_MTD;
	double value_of_sales_MTD;
	int num_of_sales_WTD;
	double value_of_sales_WTD;
	
	//Past info
	int num_of_sales_AT;
	double value_of_sales_AT;
	
	
	
public:
	//Constructor
	inventory(){};
	
	//Methods
	//Modifiers
	void addItem(item i);//Adds an item to inventory
	
	void removeItem(item i);//Removes an item from inventory.
	
	void addToCount(int itemID, int quantity);
	
	void subtractFromCount(int itemID, int quantity);
	
	void inv_maintenance();
	
	void sold(int[] itemIDs, int[] quantities, bool delayed_order);
	
	void returned(int itemIDs, int[] quantities);
	
	void delay_fulfill(int [] itemIDs, int[] quantities);
	
	void damage_out(int itemID, int quantity);
	
	void remove_damaged(int itemID, int quantity);
	
	void create_order(int[] itemIDs, int[] quantities);
	
	
	
	
	
	//getters and setters
	item getItem(int n);
	
	item getItem(std::string m);
};

#endif
