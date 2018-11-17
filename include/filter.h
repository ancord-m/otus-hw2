#ifndef FILTER_H_
#define FILTER_H_

#include "aliases.h"

class Filter 
{
	const DoubleVector<std::string> *original_pool;
	DoubleVector<std::string> *filtered_pool;
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