#ifndef FILTER_H_
#define FILTER_H_

#include <iostream>
#include <algorithm>

#include "aliases.h"
#include "printer.h"



class Filter 
{
	const IpAddressPool<unsigned int> *original_pool;
	IpAddressPool<unsigned int> filtered_pool;

	static std::string first_ip_part;
	static std::string second_ip_part;
	static std::string any_part;
	
	static bool starting_with_one_element(IpAddress<unsigned int> ip);
	static bool starting_with_two_element(IpAddress<unsigned int> ip);
	static bool containing_one_element(IpAddress<unsigned int> ip);
	
	void prepareFilteredPool(void);

public:
	Filter() = default;
   ~Filter() = default;

    //почему сигнатуру не получается оставить в заголовочном файле, 
    //а реализацию переместить в cpp? ошибка линковки!!!
	template<typename T>
	void show_ips_starting_with(T ip_part)
	{
		
	}

	template<typename T, typename... Args>
	void show_ips_starting_with(T ip_part, Args... args)
	{
		
	}

	template<typename T>
	void show_ips_containing(T ip_part)
	{
		for(auto ip : *original_pool)
		{
			if(std::find(ip.begin(), ip.end(), ip_part) != ip.end())			
				Printer::print_ip(&ip);
		}	
	}
    void set_ip_pool_to_be_filtered(const IpAddressPool<unsigned int> *ip_pool);

	void leaveIPs_AsIs(void);
	void leaveIPs_startingWith(unsigned int);
	void leaveIPs_startingWith(unsigned int, unsigned int);
	void leaveIPs_containing(unsigned int);
};

#endif