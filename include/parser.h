#include <string>
#include <vector>
#include <iostream>

class Parser {
	std::vector<std::string> ip_pool;

	public:
		//Parser() { std::cout << "ctor" << std::endl; }
		//~Parser() { std::cout << "dtor" << std::endl; }
		bool find_ip_adress(std::string line);
		std::vector<std::string> get_ip_list(void);
		std::string extractAndSaveTextBeforeFirstTab(std::string line);
};