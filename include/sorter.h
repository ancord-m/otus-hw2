#include "aliases.h"

class Sorter 
{

	static auto is_a_goes_before_b(Vector<std::string> a, Vector<std::string> b) -> bool;
	static auto is_a_goes_before_b_one_leading_sub_ip(Vector<std::string> a, Vector<std::string> b) -> bool;
	
public:
	static unsigned int first_leading_ip_part;
	static void sortInversely(DoubleVector<std::string> *);
	static void sortInversely_FirstGoIPsStartingWith(DoubleVector<std::string> *, unsigned int);
};