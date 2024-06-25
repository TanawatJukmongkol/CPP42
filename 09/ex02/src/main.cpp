#include "../include/PmergeMe.hpp"
#include <list>
#include <deque>
#include <iostream>

// 3) std::list, std::queue

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Not enough argment." << std::endl;
		return 1;
	}
	std::list<int>	lst;
	std::deque<int>	que;
	PmergeMe		sort;

	::fill_char_array_to_int_stl(lst, argv, argc - 1);
	// ::fill_char_array_to_int_stl(que, argv, argc - 1);

	std::cout << "comps: " << ::binary_insert(lst, 5) << std::endl;
	// ::binary_insert(que, 5);

	::print_int_stl(lst);
	// ::print_int_stl(que);	
	return 0;
}
