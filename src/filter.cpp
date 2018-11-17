#include <iostream>
#include "filter.h"
#include <algorithm>

void Filter::leaveIPs_AsIs(void)
{
	filtered_pool->resize(original_pool->size());
	std::copy(original_pool->begin(), original_pool->end(), filtered_pool->begin());
}

void Filter::leaveIPs_startingWith(unsigned int first_ip_part)
{
	auto ip_part = std::to_string(first_ip_part);


 
/*	for(auto ip : *ip_pool) {
		if(ip.end() != std::find(ip.begin(), ip.end(), ip_part))
			;
	}	*/
}

void Filter::leaveIPs_startingWith(unsigned int first_ip_part, unsigned int second_ip_part)
{

}

void Filter::leaveIPs_containing(unsigned int ip_part)
{

}