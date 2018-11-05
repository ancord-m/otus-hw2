#define BOOST_TEST_MODULE DataInput

#include <boost/test/unit_test.hpp>

#include "parser.h"

#include <iostream>

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
