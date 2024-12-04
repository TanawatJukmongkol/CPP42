#include "../include/PmergeMe.hpp"
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

	std::cout << "Compares : " << merge_insert.getComps() << std::endl
			  << "Swaps    : " << merge_insert.getSwaps() << std::endl
			  << "Inserts  : " << merge_insert.getInserts() << std::endl;
	
	return 0;
}
