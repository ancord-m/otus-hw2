#include <iostream>
#include "filter.h"
#include <algorithm>

std::string Filter::first_ip_part 	= "";
std::string Filter::second_ip_part 	= "";
std::string Filter::any_part		= "";

bool Filter::starting_with_one_element(Vector<std::string> ip)
{
	if(first_ip_part == ip.at(0))
		return true;

	return false;
}

bool Filter::starting_with_two_element(Vector<std::string> ip)
{
	if(first_ip_part == ip.at(0) && second_ip_part == ip.at(1))
		return true;

	return false;
}

bool Filter::containing_one_element(Vector<std::string> ip)
{
	for(auto ip_part : ip)
		if(any_part == ip_part) return true;

	return false;
}

void Filter::prepareFilteredPool(void)
{
	filtered_pool->clear();
	filtered_pool->resize(original_pool->size());
}

void Filter::leaveIPs_AsIs(void)
{
	prepareFilteredPool();
	std::copy(original_pool->begin(), original_pool->end(), filtered_pool->begin());
}

void Filter::leaveIPs_startingWith(unsigned int ip_part)
{
	first_ip_part = std::to_string(ip_part);

	prepareFilteredPool();
	auto end = std::copy_if(original_pool->begin(), original_pool->end(), filtered_pool->begin(), starting_with_one_element);
	filtered_pool->resize(std::distance(filtered_pool->begin(), end));
}

void Filter::leaveIPs_startingWith(unsigned int f_ip_part, unsigned int s_ip_part)
{
	first_ip_part  = std::to_string(f_ip_part);
	second_ip_part = std::to_string(s_ip_part);

	prepareFilteredPool();
	auto end = std::copy_if(original_pool->begin(), original_pool->end(), filtered_pool->begin(), starting_with_two_element);
	filtered_pool->resize(std::distance(filtered_pool->begin(), end));
}

void Filter::leaveIPs_containing(unsigned int ip_part)
{
	any_part = std::to_string(ip_part);

	prepareFilteredPool();
	auto end = std::copy_if(original_pool->begin(), original_pool->end(), filtered_pool->begin(), containing_one_element);
	filtered_pool->resize(std::distance(filtered_pool->begin(), end));
}