#include "upc.hpp"

	//std::string code
	
	//UPC(std::string upc){
	//	code = upc;
	//}
	
	std::string UPC::getUPC(){
		return code;
	}
	
	std::ostream& operator<<(std::ostream &strm, const UPC &u){
		return strm << u.code;
	}
