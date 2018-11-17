#ifndef FILTER_H_
#define FILTER_H_

#include "aliases.h"

class Filter 
{
	const DoubleVector<std::string> *original_pool;
	DoubleVector<std::string> *filtered_pool;

	static std::string first_ip_part;
	static std::string second_ip_part;
	static std::string any_part;
	
	static bool starting_with_one_element(Vector<std::string> ip);
	static bool starting_with_two_element(Vector<std::string> ip);
	static bool containing_one_element(Vector<std::string> ip);
	
	void prepareFilteredPool(void);

public:
	Filter(const DoubleVector<std::string> *op, DoubleVector<std::string> *fp) 
		: original_pool(op), filtered_pool(fp) {};
	~Filter() = default;

	void leaveIPs_AsIs(void);
	void leaveIPs_startingWith(unsigned int);
	void leaveIPs_startingWith(unsigned int, unsigned int);
	void leaveIPs_containing(unsigned int);
};

#endif