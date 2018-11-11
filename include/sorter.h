#include "aliases.h"

class Sorter 
{
	static auto is_a_goes_before_b(Vector<std::string> a, Vector<std::string> b) -> bool;
public:
	static void sortInversely(DoubleVector<std::string> *);
};