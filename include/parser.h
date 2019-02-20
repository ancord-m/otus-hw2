#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <vector>
#include "aliases.h"

class Parser {

	enum Delimiters
	{
		DOT = '.',
		TAB = '\t'
	};

	IpAddressPool<unsigned int> ip_pool;

	public:
		Parser();
	   ~Parser() = default;
	   
		auto captureTextBeforeFirstTab(std::string) -> std::string;
		void splitIpAddressIntoPartsAndSave(std::string line);		
		auto get_raw_ip_pool(void) -> const IpAddressPool<unsigned int> *;
};

#endif