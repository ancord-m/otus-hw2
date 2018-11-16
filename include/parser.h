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

	DoubleVector<std::string> ip_pool;

	public:
		Parser();
		auto captureTextBeforeFirstTab(std::string) -> std::string;
		void splitIpAddressIntoPartsAndSave(std::string line);		
		auto getIpPool(void) -> DoubleVector<std::string>;
};

#endif