#include "PmergeMe.hpp"
#include <list>
#include <deque>
#include <iostream>
#include <ostream>

// 3) std::list, std::queue

int main (int argc, char **argv)
{
	PmergeMe	merge_insert;
	std::list<int>	lst;
	std::deque<int>	que;

	if (argc < 2)
	{
		std::cerr << "Not enough argment." << std::endl;
		return 1;
	}

	for (size_t i = 1; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '\0')
		{
			std::cerr << "Invalid parameter." << std::endl;
			return 1;
		}
		for (size_t j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				continue ;
			std::cerr << "Invalid parameter." << std::endl;
			return 1;
		}
	}

	::fill_char_array_to_int_stl(lst, argv, argc - 1);
	::fill_char_array_to_int_stl(que, argv, argc - 1);

	std::cout << "Before:\t";
	::print_int_stl(lst, 10);

	merge_insert.sort(lst);

	std::cout << "After:\t";
	::print_int_stl(lst, 10);

	std::cout << "Time to process a range of \t" << argc - 1
			  << " elements with std::list  : " << merge_insert.getTimeMs()
			  << " us" << std::endl;

	merge_insert.sort(que);

	std::cout << "Time to process a range of \t" << argc - 1
			<< " elements with std::deque : " << merge_insert.getTimeMs()
			<< " us" << std::endl;

	return 0;
}
