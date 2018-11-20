#ifndef SORTER_H_
#define SORTER_H_

#include "aliases.h"
#include "parser.h"
#include "filter.h"

class Sorter 
{
	Parser *parser;
	IpAddressPool<unsigned int> filtered_pool;
	Filter filter{ parser->getIpPool(), &filtered_pool };

	static auto is_a_goes_before_b(IpAddress<unsigned int> a, IpAddress<unsigned int> b) -> bool;

	void sortInverslely(void);
	
public:
	Sorter(Parser *p) : parser(p) {};
	~Sorter() = default;

	void sortInversely_AllIPs(void);
	void sortInversely_IPs_startingWith(unsigned int);
	void sortInversely_IPs_startingWith(unsigned int, unsigned int);
	void sortInversely_IPs_containing(unsigned int);
	auto getSortedIpPool(void) -> IpAddressPool<unsigned int> **;
};

#endif