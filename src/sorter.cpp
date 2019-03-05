#include <iostream>
#include <algorithm>
#include <functional>

#include "sorter.h"

void Sorter::sort_inversely_ip_pool(IpAddressPool<IpAddressType> &sorted_pool)
{	
	std::sort(sorted_pool.begin(), sorted_pool.end(), std::greater<IpAddress<IpAddressType>>());	
}