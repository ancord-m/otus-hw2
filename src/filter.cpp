#include <iostream>
#include <algorithm>

#include "filter.h"


void Filter::set_ip_pool_to_be_filtered(const IpAddressPool<unsigned int> *ip_pool)
{
	original_pool = ip_pool;
}


void Filter::show_ips_as_is(void)
{
	for(auto ip : *original_pool)
	{
		Printer::print_ip(&ip);
	}
}

