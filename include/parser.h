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
		auto captureTextBeforeFirstTab(std::string) -> std::string;
		void splitIpAddressIntoPartsAndSave(std::string line);		
		auto getIpPool(void) -> IpAddressPool<unsigned int> *;
};

#endif