#include "printer.h"
#include <iostream>

void Printer::printContentsOfIpPool(DoubleVector<std::string> *ip_pool) 
{
	for(auto ip : *ip_pool) {
		for(auto ip_part : ip) {
			if(ip_part != ip[0]) std::cout << '.'; //fixme!!!!
			std::cout << ip_part;
		}
		std::cout << std::endl;
	}
}