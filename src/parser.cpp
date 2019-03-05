#include "parser.h"

static const int EXPECTED_IP_QUANTITY = 1000;

Parser::Parser()
{
	ip_pool.reserve(EXPECTED_IP_QUANTITY);
}

std::string Parser::captureTextBeforeFirstTab(std::string rawLine)
{
	std::string::size_type start = 0;
    std::string::size_type stop = rawLine.find_first_of(TAB);

    return rawLine.substr(start, stop - start);
}


void Parser::splitIpAddressIntoPartsAndSave(std::string ip)
{
	IpAddress<IpAddressType> splitedIp;

	std::string::size_type start = 0;
    std::string::size_type stop = ip.find_first_of(DOT);
    while(stop != std::string::npos)
    {
        splitedIp.push_back(atoi(ip.substr(start, stop - start).c_str()));
        start = stop + 1;
        stop = ip.find_first_of(DOT, start);
    }

    splitedIp.push_back(atoi(ip.substr(start).c_str()));

    ip_pool.push_back(splitedIp);
}

IpAddressPool<IpAddressType>& Parser::get_ip_pool(void)
{
	return ip_pool;
}