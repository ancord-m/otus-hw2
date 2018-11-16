#ifndef FILTER_H_
#define FILTER_H_

#include "aliases.h"

class Filter 
{
	DoubleVector<std::string> *ip_pool;
public:
	Filter(DoubleVector<std::string> *pool) : ip_pool(pool) {};
	~Filter() = default;

	void leaveIPs_startingWith(unsigned int);
	void leaveIPs_startingWith(unsigned int, unsigned int);
	void leaveIPs_containing(unsigned int);
};

#endif