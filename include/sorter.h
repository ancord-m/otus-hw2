#ifndef SORTER_H_
#define SORTER_H_

#include "aliases.h"
#include "parser.h"

class Sorter 
{
	Parser *parser;
	DoubleVector<std::string> ip_pool_copy;
	static auto is_a_goes_before_b(Vector<std::string> a, Vector<std::string> b) -> bool;
	
public:
	Sorter(Parser *p) : parser(p) {};
	~Sorter() = default;

	unsigned int first_leading_ip_part;
	void sortInversely_AllIPs(void);
	void sortInversely_IPs_startingWith(unsigned int);
	auto getSortedIpPool(void) -> DoubleVector<std::string> *;
};

#endif