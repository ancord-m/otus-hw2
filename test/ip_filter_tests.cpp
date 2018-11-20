#define BOOST_TEST_MODULE DataInput

#include <boost/test/unit_test.hpp>
#include "parser.h"
#include "sorter.h"
#include <iostream>

class IpPoolGenerator 
{
	auto generateIP(int b1, int b2, int b3, int b4) -> IpAddress<unsigned int> *
	{
		IpAddress<unsigned int> result;

		result.push_back(std::to_string(b1));
		result.push_back(std::to_string(b2));
		result.push_back(std::to_string(b3));
		result.push_back(std::to_string(b4));
		
		return result;
	}

public:
	IpAddressPool<unsigned int> ip_pool;

	void generateIP_And_PutIntoPool(int b1, int b2, int b3, int b4)
	{
		ip_pool.push_back(generateIP(b1, b2, b3, b4));		
	}
};

BOOST_AUTO_TEST_SUITE(DataInput)

BOOST_AUTO_TEST_CASE(GotEmptyString_NothingFound)
{
	auto line = "";
	Parser parser;
	auto actual = parser.captureTextBeforeFirstTab(line);
	BOOST_CHECK_EQUAL(line, actual);
}

BOOST_AUTO_TEST_CASE(GotTabSeparatedString_CapturedAllBeforeFirstTab)
{
	auto line = "127.0.0.1\t567\t10\n";
	Parser parser;
	BOOST_CHECK_EQUAL(
		"127.0.0.1",
		parser.captureTextBeforeFirstTab(line)
	);
}

BOOST_AUTO_TEST_SUITE_END()