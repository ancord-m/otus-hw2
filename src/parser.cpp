#include "parser.h"

bool Parser::find_ip_adress(std::string line)
{

}

std::vector<std::string> Parser::get_ip_list(void)
{
	std::vector<std::string> v;

	return v;
}

std::string Parser::extractAndSaveTextBeforeFirstTab(std::string line)
{
	std::string result;

	std::string::size_type start = 0;
	std::string::size_type end   = line.find_first_of('\t');
	result = line.substr(start, end);
	ip_pool.push_back(result);

	return result;
}