#include <iostream>
#include <algorithm>

#include "filter.h"

std::string Filter::first_ip_part 	= "";
std::string Filter::second_ip_part 	= "";
std::string Filter::any_part		= "";

/*template <typename T>
auto Filter::leave_ips_starting_with(
		const IpAddressPool<unsigned int> *ip_pool,
		T ip_part
	) -> const IpAddressPool<unsigned int> *
{
	std::cout << ip_part << ' ';
}

template <typename T, typename... Args>
auto Filter::leave_ips_starting_with(
		const IpAddressPool<unsigned int> *ip_pool,
		T ip_part,
		Args... args
	) -> const IpAddressPool<unsigned int> *
{
	std::cout << ip_part << ' ';
	leave_ips_starting_with(ip_pool, args...);
}
*/

void Filter::set_ip_pool_to_be_filtered(const IpAddressPool<unsigned int> *ip_pool)
{
	original_pool = ip_pool;
}




bool Filter::starting_with_one_element(IpAddress<unsigned int> ip)
{
	/*if(first_ip_part == ip.at(0))
		return true;*/

	return false;
}

bool Filter::starting_with_two_element(IpAddress<unsigned int> ip)
{
	/*if(first_ip_part == ip.at(0) && second_ip_part == ip.at(1))
		return true;*/

	return false;
}

bool Filter::containing_one_element(IpAddress<unsigned int> ip)
{
	/*for(auto ip_part : ip)
		if(any_part == ip_part) return true;*/

	return false;
}

void Filter::prepareFilteredPool(void)
{
	filtered_pool.clear();
	filtered_pool.resize(original_pool->size());
}

void Filter::leaveIPs_AsIs(void)
{
	prepareFilteredPool();
	std::copy(original_pool->begin(), original_pool->end(), filtered_pool.begin());
}

void Filter::leaveIPs_startingWith(unsigned int ip_part)
{
	first_ip_part = std::to_string(ip_part);

	prepareFilteredPool();
	auto end = std::copy_if(original_pool->begin(), original_pool->end(), filtered_pool.begin(), starting_with_one_element);
	filtered_pool.resize(std::distance(filtered_pool.begin(), end));
}

void Filter::leaveIPs_startingWith(unsigned int f_ip_part, unsigned int s_ip_part)
{
	first_ip_part  = std::to_string(f_ip_part);
	second_ip_part = std::to_string(s_ip_part);

	prepareFilteredPool();
	auto end = std::copy_if(original_pool->begin(), original_pool->end(), filtered_pool.begin(), starting_with_two_element);
	filtered_pool.resize(std::distance(filtered_pool.begin(), end));
}

void Filter::leaveIPs_containing(unsigned int ip_part)
{
	any_part = std::to_string(ip_part);

	prepareFilteredPool();
	auto end = std::copy_if(original_pool->begin(), original_pool->end(), filtered_pool.begin(), containing_one_element);
	filtered_pool.resize(std::distance(filtered_pool.begin(), end));
}