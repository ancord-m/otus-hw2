#include "sorter.h"
#include <iostream>
#include <algorithm>

void Sorter::sortInversely_AllIPs(void)
{	
	ip_pool_copy = parser->getIpPool();
	std::sort(ip_pool_copy.begin(), ip_pool_copy.end(), is_a_goes_before_b);
}

void Sorter::sortInversely_IPs_startingWith(unsigned int)
{

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
	return &ip_pool_copy;
}

auto Sorter::is_a_goes_before_b_one_leading_sub_ip(Vector<std::string> a, Vector<std::string> b) -> bool
{
	bool a_goes_before_b = false;
	
	unsigned int subA, subB;
	//for(int i = a.size() - 1; i >= 0; i--) {
	for(int i = 0; i < a.size(); ++i) {
//		std::cout << a[i] << " " << b[i] << std::endl;
		subA = stoul(a[i], nullptr, 10);
		subB = stoul(b[i], nullptr, 10);
	  
	  	if(subA == subB) continue;

	  	if(subA > subB)  {
			a_goes_before_b = true;
			break;
		} else {
			a_goes_before_b = false;
			break;
		}
	}

	return a_goes_before_b;
}