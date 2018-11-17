#ifndef SORTER_H_
#define SORTER_H_

#include "aliases.h"
#include "parser.h"
#include "filter.h"

class Sorter 
{
	Parser *parser;
	DoubleVector<std::string> filtered_pool;
	Filter filter{ parser->getIpPool(), &filtered_pool };
	static auto is_a_goes_before_b(Vector<std::string> a, Vector<std::string> b) -> bool;
	void makeIpPoolCopy(void);
	void sortInverslely(void);
	
public:
	Sorter(Parser *p) : parser(p) {};
	~Sorter() = default;

	unsigned int first_leading_ip_part;
	void sortInversely_AllIPs(void);
	void sortInversely_IPs_startingWith(unsigned int);
	void sortInversely_IPs_startingWith(unsigned int, unsigned int);
	void sortInversely_IPs_containing(unsigned int);
	auto getSortedIpPool(void) -> DoubleVector<std::string> *;
};

#endif