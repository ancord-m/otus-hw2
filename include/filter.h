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

   template<typename T>
   auto leave_ips_starting_with(
   			const IpAddressPool<unsigned int> *ip_pool,
   			T ip_part
   		) -> const IpAddressPool<unsigned int> *
   {
   	
   }

   template<typename T, typename... Args>
   auto leave_ips_starting_with(
	   		const IpAddressPool<unsigned int> *ip_pool,
	   		T ip_part,
	   		Args... args
   		) -> const IpAddressPool<unsigned int> *
   {
		
   }

	void leaveIPs_AsIs(void);
	void leaveIPs_startingWith(unsigned int);
	void leaveIPs_startingWith(unsigned int, unsigned int);
	void leaveIPs_containing(unsigned int);
};

#endif