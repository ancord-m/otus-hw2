#include "sorter.h"
#include <iostream>
#include <algorithm>

void Sorter::sortInversely(DoubleVector<std::string> *ip_pool)
{
	std::sort(ip_pool->begin(), ip_pool->end(), is_a_goes_before_b);
}

auto Sorter::is_a_goes_before_b(Vector<std::string> a, Vector<std::string> b) -> bool
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