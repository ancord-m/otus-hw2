#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool ipComparator(std::vector<std::string> a, std::vector<std::string> b)
{
	bool a_goes_before_b = false;	
	
	//for(int i = a.size() - 1; i >= 0; i--) {
	for(int i = 0; i < a.size(); ++i) {
		std::cout << a[i] << " " << b[i] << std::endl;
	  if(stoul(a[i], nullptr, 10) < stoul(b[i], nullptr, 10))  {
	//	if(a[i] > b[i]) {
		  a_goes_before_b = true;
		  break;
		}/* else {
			a_goes_before_b = false;
		}*/
	}
	
	return a_goes_before_b;
}
 
int main()
{   
	std::vector<std::string> temp;
	
	/*std::vector<std::vector<int> > pool = 
				{
						{ 222, 173, 235 },
						{ 222, 130, 177 },
						{ 222, 82, 198 },
						{ 1, 70, 44 },
						{ 99, 100, 168 },
						{ 100, 2, 234 }
				};*/
	std::vector<std::vector<std::string> > pool = 
			{
					{ "85", "254", "10", "197" },	
					{ "23", "240", "215", "189" },
					{ "1",  "29", "168", "152" },
					{ "185", "69", "186", "168" },
					{ "110", "152", "103", "161" },
					{ "68", "45", "152", "82" },
					{ "185", "182", "81", "131" },
					{ "114", "221", "179", "117" },
					{ "185", "89", "100", "249" },
					{ "46", "70", "113", "73" },
					{ "185", "68", "0", "38" }
			};

	
	for(auto i: pool) {
		std::cout << std::endl;		
		for(auto j: i) {
			if(j != i[0] ) std::cout << ".";
			std::cout << j;
		}
	}
	
	
	std::cout << "\n\nAfter sort " << std::endl;
	
	std::sort(pool.begin(), pool.end(), ipComparator);

	for(auto i: pool) {
		std::cout << std::endl;
		for(auto j: i) {
			if(j != i[0]) std::cout << ".";
			std::cout << j;
		}
	}
	
    return 0;
}
