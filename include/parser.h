#include <string>
#include <vector>

template<typename T>
using DoubleVector = std::vector<std::vector<T> >;

template<typename T>
using Vector = std::vector<T>;

class Parser {

	enum Delimiters
	{
		DOT = '.',
		TAB = '\t'
	};

	DoubleVector<std::string> ip_pool;

	public:
		auto captureTextBeforeFirstTab(std::string) -> std::string;
		void splitIpAddressIntoPartsAndSave(std::string line);		
		auto getIpPool(void) -> DoubleVector<std::string>;
};