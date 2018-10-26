#include <string>
#include <vector>

class Parser {
	std::vector<std::string> lines;

	public:
		auto find_ip_adress(auto line);
		auto get_ip_list(void);
};