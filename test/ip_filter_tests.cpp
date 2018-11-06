#define BOOST_TEST_MODULE DataInput

#include <boost/test/unit_test.hpp>
#include "parser.h"
#include "sorter.h"
#include <iostream>


class IpPoolGenerator 
{
	auto generateIP(int b1, int b2, int b3, int b4) -> Vector<std::string>
	{
		Vector<std::string> result;

		result.push_back(std::to_string(b1));
		result.push_back(std::to_string(b2));
		result.push_back(std::to_string(b3));
		result.push_back(std::to_string(b4));
		
		return result;
	}

public:
	DoubleVector<std::string> ip_pool;

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

BOOST_AUTO_TEST_CASE(IpCaptured_Splitted_And_Saved)
{
	auto line = "127.0.0.1\t567\t10\n";
	Parser parser;

	auto s = parser.captureTextBeforeFirstTab(line);
	parser.splitIpAddressIntoPartsAndSave(s);

	BOOST_CHECK(false == parser.getIpPool().empty());

	BOOST_CHECK_EQUAL("127", parser.getIpPool().at(0)[0]);
	BOOST_CHECK_EQUAL(  "0", parser.getIpPool().at(0)[1]);
	BOOST_CHECK_EQUAL(  "0", parser.getIpPool().at(0)[2]);
	BOOST_CHECK_EQUAL(  "1", parser.getIpPool().at(0)[3]);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SorterFunctions)

BOOST_AUTO_TEST_CASE(IPs_WithNonZeroFirstByte_SortedReversly)
{
	int b1     = 10;
	int b1_Max = 11;

	Vector<std::string> v;

	IpPoolGenerator ipg;
	ipg.generateIP_And_PutIntoPool(b1,     0,0,0);
	ipg.generateIP_And_PutIntoPool(b1 + 1, 0,0,0);

	Sorter::sortInversely(&ipg.ip_pool);

	int i = b1_Max - 1;
	for(auto v : ipg.ip_pool)
	{
		BOOST_CHECK_EQUAL(std::to_string(i), v.at(0));
	}


}

BOOST_AUTO_TEST_SUITE_END()