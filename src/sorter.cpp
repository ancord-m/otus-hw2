#include "sorter.h"
#include <iostream>
#include <algorithm>

void Sorter::makeIpPoolCopy(void)
{
//	ip_pool_copy = parser->getIpPool();
}

void Sorter::sortInverslely(void)
{
	std::sort(filtered_pool.begin(), filtered_pool.end(), is_a_goes_before_b);
	
}

void Sorter::sortInversely_AllIPs(void)
{	
	filter.leaveIPs_AsIs();
	sortInverslely();
}

void Sorter::sortInversely_IPs_startingWith(unsigned int leading_ip_part)
{
	filter.leaveIPs_startingWith(leading_ip_part);
	sortInverslely();	
}

void Sorter::sortInversely_IPs_startingWith(unsigned int first_ip_part, unsigned int second_ip_part)
{
	filter.leaveIPs_startingWith(first_ip_part, second_ip_part);
	sortInverslely();	
}

void Sorter::sortInversely_IPs_containing(unsigned int ip_part)
{
	filter.leaveIPs_containing(ip_part);
	sortInverslely();
}

auto Sorter::is_a_goes_before_b(Vector<std::string> a, Vector<std::string> b) -> bool
{
	bool a_goes_before_b = false;	
	unsigned int ip_part_form_a, ip_part_form_b;

	for(int i = 0; i < a.size(); ++i) {
		ip_part_form_a = stoul(a[i], nullptr, 10);
		ip_part_form_b = stoul(b[i], nullptr, 10);
	  
	  	if(ip_part_form_a == ip_part_form_b) continue;

	  	if(ip_part_form_a > ip_part_form_b)  {
			a_goes_before_b = true;
			break;
		} else {
			a_goes_before_b = false;
			break;
		}
	}

	return a_goes_before_b;
}


auto Sorter::getSortedIpPool(void) -> DoubleVector<std::string> *
{
	return &filtered_pool;
}