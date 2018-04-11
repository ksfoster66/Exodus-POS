//TODO add Inventory order support once supported
//Add threading support

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include "item.hpp"


class Inventory{
private:
	//Fields
	//Inventory maps
	std::map<int, Item*> inv;//Main map. Key:ItemID. Value:Item
	std::unordered_map<int, int> UPC_listing;//Maps the items UPC to the item.
	std::unordered_map<std::string, int> model_listing;//Maps the model number to the item
	
	//current info
	int num_items;//Number of different items in inventory
	int total_count;//Current count of number of individuals items in inventory
	double total_value;//Current value of of individual items in inventory
	
	int num_of_sales_YTD;// Year to date number of sales
	double value_of_sales_YTD;//Year to date value of sales in dollars
	int num_of_sales_MTD;//Month to date number of sales
	double value_of_sales_MTD;//Month to date value of sales
	int num_of_sales_WTD;//Week to date number of sales
	double value_of_sales_WTD;//Week to date value of sales
	int num_of_sales;//The daily number of sales
	double value_of_sales;//The daily value of sales;
	
	//Past info. Lists the most recent sales info for the periods. When the periods update this information is written into a log file for manual searching
	int num_of_sales_AT;//All time
	double value_of_sales_AT;
	int num_of_sales_LM;//Last month
	double value_of_sales_LM;
	int num_of_sales_LW;//Last week
	double value_of_sales_LW;
	
	
	
public:
	//Constructor
	Inventory(){};
	
	//Methods
	//Modifiers
	
	void inv_maintenance();
	//To be run at the end of business, updates all records
	
	void updateSales(int n, double a, double v);//N = number sold, a = actual value of sold items, v - value items were sold at
	
	bool addItem(Item *i);//Adds an item to inventory
	//Items default to a stock amount of zero and prices of 10000 until set
	
	void removeItem(int ID);//Removes an item from inventory.
	//If item still has on hand count items will be billed out as expense
	//Anywhere this method is called should check to be sure there are no orders for this item
	
	void addToCount(int itemID, int quantity);
	//Add to the available count of an item
	
	void subtractFromCount(int itemID, int quantity);
	//Subtract from the available count of an item
	
	void sold(std::vector<int> itemIDs, std::vector<int> quantities, std::vector<double> sale_price);
	//Adjusts counts after a sale.
	
	void soldDelayed(std::vector<int> itemIDs, std::vector<int> quantities, std::vector<double> sale_price);
	//Adjusts counts after a sale. Delayed order counts are adjusted in due file accordingly
	
	void returned(std::vector<int> itemIDs, std::vector<int> quantities, std::vector<double> sale_price);
	//If items are returned they'll be added into the inventory.
	
	void delay_fulfill(std::vector<int> itemIDs, std::vector<int> quantities);
	//When a delayed order is fulfilled they shall be removed from the due file counting
	
	void damage_out(std::vector<int> itemID, std::vector<int> quantity);
	//Marks the item and amounts as damaged
	
	void remove_damaged(std::vector<int> itemID, std::vector<int> quantity);
	//Removes the desired item and quantities from damaged
	
	void create_order(std::vector<int> itemIDs, std::vector<int> quantities);
	//Creates an inventory order
	
	bool contains(int n);//Checks if a certain item exists in the system. If the item isn't an UPC code is treated as a item ID
	
	bool contains(std::string m);//Checks if a certain item is in the system based on the model number
	
	
	//getters and setters
	Item* getItem(int n);
	//Returns item based on either the item number or the UPC code
	
	Item* getItem(std::string m);
	//Returns the item based on model number
	
	int get_num_items();//Number of different items in inventory	//IMPL
	int get_total_count();//Current count of number of individuals items in inventory	//IMPL
	double get_total_value();//Current value of of individual items in inventory	//IMPL
	int get_num_of_sales_YTD();// Year to date number of sales	//IMPL
	double get_value_of_sales_YTD();//Year to date value of sales in dollars	//IMPL
	int get_num_of_sales_MTD();//Month to date number of sales	//IMPL
	double get_value_of_sales_MTD();//Month to date value of sales	//IMPL
	int get_num_of_sales_WTD();//Week to date number of sales	//IMPL
	double get_value_of_sales_WTD();//Week to date value of sales	//IMPL
	int get_num_of_sales();//The daily number of sales	//IMPL
	double get_value_of_sales();//The daily value of sales	//IMPL
	
	
	int get_num_of_sales_AT();//All time 	//IMPL
	double get_value_of_sales_AT(); 	//IMPL
	int get_num_of_sales_LM();//Last month 	//IMPL
	double get_value_of_sales_LM();	//IMPL
	int get_num_of_sales_LW();//Last week 	//IMPL
	double get_value_of_sales_LW();	//IMPL
	
	
};

#endif
