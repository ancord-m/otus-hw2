#ifndef FILTER_H_
#define FILTER_H_

#include "aliases.h"
#include <iostream>


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

    //почему сигнатуру неполучается отсавить в заголовочном файле, 
    //а реализацию переместить в cpp? ошибка линковки!!!
	template<typename T>
	auto leave_ips_starting_with(T ip_part) -> const IpAddressPool<unsigned int> *
	{
		
	}

	template<typename T, typename... Args>
	auto leave_ips_starting_with(T ip_part, Args... args) -> const IpAddressPool<unsigned int> *
	{
		auto end = 
			std::copy_if(original_pool->begin(), original_pool->end(), filtered_pool.begin(), starting_with_one_element);
		filtered_pool.resize(std::distance(filtered_pool.begin(), end));
	}

	template<typename T>
	auto leave_ips_containing(T ip_part) -> const IpAddressPool<unsigned int> *
	{
		prepareFilteredPool();
	}


    void set_ip_pool_to_be_filtered(const IpAddressPool<unsigned int> *ip_pool);

	void leaveIPs_AsIs(void);
	void leaveIPs_startingWith(unsigned int);
	void leaveIPs_startingWith(unsigned int, unsigned int);
	void leaveIPs_containing(unsigned int);
};

#endif