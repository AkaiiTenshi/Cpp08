#include "easyfind.hpp"
#include <exception>
#include <vector>

int main()
{
	int tab[] = {312, 12, 61, 93, 2000};
	std::vector<int> vec(tab, tab + sizeof(tab) / sizeof(int));
	try {

		std::vector<int>::iterator it = easyfind(vec, 61);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
			
	return 0;
}
