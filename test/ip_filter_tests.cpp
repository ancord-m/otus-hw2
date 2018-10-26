#define BOOST_TEST_MODULE Parser

#include <boost/test/unit_test.hpp>

#include "parser.h"

BOOST_AUTO_TEST_SUITE(Parser)

BOOST_AUTO_TEST_CASE(GotEmptyString_NothingFound)
{
	Parser ip_parser;
	ip_parser.find_ip_adress(line);

	BOOST_CHECK(false == ip_parser.get_ip_list().empty());
}

BOOST_AUTO_TEST_SUITE_END()
