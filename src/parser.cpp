#include "parser.h"

static const int EXPECTED_IP_QUANTITY = 1000;

Parser::Parser()
{
	ip_pool.reserve(EXPECTED_IP_QUANTITY);
}

auto Parser::captureTextBeforeFirstTab(std::string rawLine) -> std::string
{
	std::string::size_type start = 0;
    std::string::size_type stop = rawLine.find_first_of(TAB);

    return rawLine.substr(start, stop - start);
}


void Parser::splitIpAddressIntoPartsAndSave(std::string ip)
{
	Vector<std::string> splitedIp;

	std::string::size_type start = 0;
    std::string::size_type stop = ip.find_first_of(DOT);
    while(stop != std::string::npos)
    {
        splitedIp.push_back(ip.substr(start, stop - start));
        start = stop + 1;
        stop = ip.find_first_of(DOT, start);
    }

    splitedIp.push_back(ip.substr(start));

    ip_pool.push_back(splitedIp);
}

auto Parser::getIpPool(void) -> DoubleVector<std::string> *
{
	return &ip_pool;
}