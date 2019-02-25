#ifndef FILTER_H_
#define FILTER_H_

#include <iostream>
#include <algorithm>

#include "aliases.h"
#include "printer.h"

class Filter 
{
	const int MAX_PARTS_QNT = 4;
	const IpAddressPool<unsigned int> *original_pool;
	std::vector<unsigned int> ip_parts;

public:
	Filter() = default;
   ~Filter() = default;

    //почему сигнатуру не получается оставить в заголовочном файле, 
    //а реализацию переместить в cpp? ошибка линковки!!!
	template<typename T>
	void show_ips_starting_with(T ip_part)
	{
		bool all_ip_parts_found;

		ip_parts.push_back(ip_part);
		
		for(auto ip : *original_pool)
		{
			all_ip_parts_found = true;

			for(auto i = 0; i < ip_parts.size() && i < MAX_PARTS_QNT; ++i)
			{
				if(ip_parts.at(i) != ip.at(i))
				{
					all_ip_parts_found = false;
					break;
				}
			}

			if(all_ip_parts_found)
			{
				Printer::print_ip(&ip);
			}
					
		}

		ip_parts.clear();
	}

	template<typename T, typename... Args>
	void show_ips_starting_with(T ip_part, Args... args)
	{
		ip_parts.push_back(ip_part);
		show_ips_starting_with(args...);
	}

	template<typename T>
	void show_ips_containing(T ip_part)
	{
		for(auto ip : *original_pool)
		{
			if(std::find(ip.begin(), ip.end(), ip_part) != ip.end())
			{		
				Printer::print_ip(&ip);
			}
		}	
	}

    void set_ip_pool_to_be_filtered(const IpAddressPool<unsigned int> *ip_pool);
	void show_ips_as_is(void);
};

#endif