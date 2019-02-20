#include "sorter.h"
#include <iostream>
#include <algorithm>

void Sorter::sort_inversely_ip_pool(const IpAddressPool<unsigned int> *original_pool)
{	
	sorted_pool.resize(original_pool->size());
	std::copy(original_pool->begin(), original_pool->end(), sorted_pool.begin());
	std::sort(sorted_pool.begin(), sorted_pool.end());
	std::reverse(sorted_pool.begin(), sorted_pool.end());
}

auto Sorter::get_inversley_sorted_ip_pool(void) -> const IpAddressPool<unsigned int> *
{
	return &sorted_pool;
}