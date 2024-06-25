#include "../include/PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe created" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destroyed" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &assignment)
{
	(void)assignment;
	return *this;
}
