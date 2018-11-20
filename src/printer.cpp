#include "printer.h"
#include <iostream>

void Printer::printContentsOfIpPool(const IpAddressPool<unsigned int> *ip_pool) 
{
	for(auto pool_itr = ip_pool->cbegin(); pool_itr != ip_pool->cend(); ++pool_itr) {
		for(auto ip_part_itr = pool_itr->cbegin(); ip_part_itr != pool_itr->cend(); ++ip_part_itr) {
			if(ip_part_itr != pool_itr->cbegin()) std::cout << '.'; 
			std::cout << *ip_part_itr;
		}
		std::cout << std::endl;
	}
}