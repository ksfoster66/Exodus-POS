//Represents an individual item in the inventory

#ifndef item_hpp
#define item_hpp

#include "upc.hpp"
#include <string>

class Item{
private:
	//fields
	std::string name;
	std::string description;
	std::string type;//Type of item. Wood, toilet, microwave, etc
	std::string department;//Department of the store item belongs to
	std::string model_number;//Manufacturer specified model number.
	
	enum stock_type {a, c, d, s, r};//a = Available, c = clearance, d = discontinued, s = special order, r = recall
	stock_type stock;
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
	
public:
	//methods
	//ID generator
	static int used_id;
	
	int getNewID();
	//Consructors
	
	Item(UPC* UPC_code, std::string model);
	
	Item(UPC* UPC_code, std::string model, std::string name, std::string description, std::string type, std::string supplier, std::string stock_code, double current_price, double MSRP, double cost);
	
	~Item();
	
	//Getters and setters
	std::string getName();
	
	void updateName(std::string t);
	
	std::string getDescription();
	
	void updateDescription(std::string t);
	
	std::string getType();
	
	void changeType(std::string t);
	
	std::string getDepartment();
	
	void setDepartment(std::string t);
	
	std::string getModelNumber();
	
	void updateModelNumber(std::string t);
	
	std::string getStock();
	
	void changeStockStatus(std::string t);
	
	std::string getSupplier();
	
	void changeSupplier(std::string t);
	
	double getPrice();
	
	void setPrice(double n);
	
	double getMSRP();
	
	void setMSRP(double n);
	
	double getCost();
	
	void setCost(double n);
	
	int getID();
	
	std::string getUPC();
	
	int getTotalCount();
	
	int getAvailableCount();
	
	int getDamagedCount();
	
	int getSold();
	
	int getDue();
	
	int getOrdered();
	
	//special inventory modifier methods
	void add(int n);
	
	void subtract (int n);
	
	void inc();
	
	void dec();
	
	void operator++();
	
	void operator++(int);
	
	void operator--();
	
	void operator--(int);
	
	void operator+=(int n);
	
	void operator -=(int n);
	
	void sold(int n=1);
	
	void soldPending(int n=1);
	
	void soldPendingDelivered(int n = 1);
	
	void returned(int n = 1);
	
	void damageOut (int n =1);
	
	void removeFromDamaged (int n = 1);
	
	void soldDamaged (int n =1);
};

#endif
