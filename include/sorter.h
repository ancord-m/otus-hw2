#ifndef SORTER_H_
#define SORTER_H_

#include "aliases.h"
#include "parser.h"
#include "filter.h"

class Sorter 
{
	IpAddressPool<unsigned int> sorted_pool;
	
public:
	Sorter() = default;
   ~Sorter() = default;

	void sort_inversely_ip_pool(const IpAddressPool<unsigned int> *original_pool);
	auto get_inversley_sorted_ip_pool(void) -> const IpAddressPool<unsigned int> *;
	
};

#endif