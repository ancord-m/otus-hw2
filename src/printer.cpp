#include "printer.h"
#include <iostream>

void Printer::print_ip(const IpAddress<IpAddressType> &ip) 
{
	for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
	{
		if(ip_part != ip.cbegin())
		{
			std::cout << '.';
		}

		std::cout << *ip_part;
	}
	
	std::cout << std::endl;
}