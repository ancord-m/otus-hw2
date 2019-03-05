#ifndef SORTER_H_
#define SORTER_H_

#include "aliases.h"
#include "parser.h"
#include "filter.h"

struct Sorter 
{
	Sorter() = default;
   ~Sorter() = default;
   
	void sort_inversely_ip_pool(IpAddressPool<IpAddressType> &original_pool);
};

#endif