#define BOOST_TEST_MODULE Parser

#include <boost/test/unit_test.hpp>

#include "parser.h"

BOOST_AUTO_TEST_SUITE(ip_parser)

BOOST_AUTO_TEST_CASE(GotEmptyString_NothingFound)
{
	Parser ip_parser;
	std::string line = "";
	ip_parser.find_ip_adress(line);

	BOOST_CHECK(true == ip_parser.get_ip_list().empty());
}

BOOST_AUTO_TEST_CASE(TabSeparatedStringAtInput_123string_extracted)
{
	Parser ip_parser;
	auto line = "123\t456\t789\n";
	auto expected = "123";

	auto actual = ip_parser.extractAndSaveTextBeforeFirstTab(line);

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(TabSeparatedStringWithRealIP_AtInput_extractedSavedAndReturned)
{
	Parser ip_parser;
	auto line = "185.89.100.249\t752\t39\n";
	auto expected = "185.89.100.249";

	auto actual = ip_parser.extractAndSaveTextBeforeFirstTab(line);

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE()

BOOST_AUTO_TEST_SUITE_END()
