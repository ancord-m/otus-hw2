#ifndef FILTER_H_
#define FILTER_H_

#include <iostream>
#include <algorithm>

#include "aliases.h"
#include "printer.h"

class Filter 
{
	const IpAddressPool<IpAddressType> *original_pool;
	IpAddress<IpAddressType> looked_for_ip_parts;

public:
	Filter() = default;
   ~Filter() = default;

    //почему сигнатуру не получается оставить в заголовочном файле, 
    //а реализацию переместить в cpp? ошибка линковки!!!
	template<typename T>
	void show_ips_starting_with(T ip_part)
	{
		looked_for_ip_parts.push_back(ip_part);
		
		for(auto ip : *original_pool)
		{
			if(std::equal(looked_for_ip_parts.begin(), looked_for_ip_parts.end(), ip.begin()))
			{
				Printer::print_ip(ip);
			}					
		}

		looked_for_ip_parts.clear();
	}

	template<typename T, typename... Args>
	void show_ips_starting_with(T ip_part, Args... args)
	{
		looked_for_ip_parts.push_back(ip_part);
		show_ips_starting_with(args...);
	}

	template<typename T>
	void show_ips_containing(T ip_part)
	{
		for(auto ip : *original_pool)
		{
			if(std::any_of(ip.begin(), ip.end(), [&](IpAddressType ipp) { return ipp == ip_part; } ))
			{		
				Printer::print_ip(ip);
			}
		}	
	}

    void set_ip_pool_to_be_filtered(IpAddressPool<IpAddressType> &ip_pool);
	void show_ips_as_is(void);
};

#endif