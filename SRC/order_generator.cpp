#include "order_generator.hpp"

	void OrderGenerator::createOrder(std::vector<int> ids, std::vector<int> quantities, std::vector<double> prices, customer* c, employee* e){
		std::vector<int> specialID;
		std::vector<int> stockID;
		
		std::vector<int> specialQuant;
		std::vector<int> stockQuant;
		
		std::vector<double> specialPrice;
		std::vector<double> stockPrice;
		
		Item* i;
		
		for (int i = 0; i < ids.size(); i++){
			i = inv->getItem(ids[i])
			if(i->getStock() == "special"){
				specialID.push_back(ids[i]);
				specialQuant.push_back(quantities[i]);
				specialPrice.push_back(prices[i]);
			}
			else{
				stockID.push_back(ids[i]);
				stockQuant.push_back(quantities[i]);
				stockPrice.push_back(prices[i]);
			}
			
		}
		
		if(!specialID.empty()){
			Order o(c,e,specialID,specialQuant,specialPrice);
			OrdMgr.addOrder(*o);
		}
		if(!stockID.empty()){
			Order o(c,e,stockID,stockQuant,stockPrice);
			OrdMgr.addOrder(*o);
		}
		//inventory order here
	}
