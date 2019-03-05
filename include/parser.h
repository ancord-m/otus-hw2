#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <vector>
#include "aliases.h"

class Parser 
{
	enum Delimiters
	{
		DOT = '.',
		TAB = '\t'
	};

	IpAddressPool<IpAddressType> ip_pool;

public:
		Parser();
	   ~Parser() = default;
	   
		std::string captureTextBeforeFirstTab(std::string);
		void splitIpAddressIntoPartsAndSave(std::string line);		
		IpAddressPool<IpAddressType>& get_ip_pool(void);
};

#endif