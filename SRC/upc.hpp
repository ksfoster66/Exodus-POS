#ifndef UPC_HPP
#define UPC_HPP

#include <string>


class UPC{
	std::string code;
	
public:
	UPC(std::string upc){
		code = upc;
	}

	std::string getUPC();
	
	friend std::ostream& operator<<(std::ostream &strm, const UPC &u);
};

#endif
