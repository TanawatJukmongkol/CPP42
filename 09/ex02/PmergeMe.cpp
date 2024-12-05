#include "PmergeMe.hpp"
#include <cstddef>

PmergeMe::PmergeMe():
	__comps(0),
	__swaps(0),
	__inserts(0),
	__timediff(0.0f)
{
	// std::cout << "PmergeMe created" << std::endl;
}

PmergeMe::~PmergeMe()
{
	// std::cout << "PmergeMe destroyed" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy):
	__comps(0),
	__swaps(0),
	__inserts(0),
	__timediff(0.0f)
{
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &assignment)
{
	(void)assignment;
	return *this;
}

size_t	PmergeMe::getComps()
{
	return __comps;
}

size_t	PmergeMe::getSwaps()
{
	return __swaps;
}

size_t	PmergeMe::getInserts()
{
	return __inserts;
}

float	PmergeMe::getTimeMs()
{
	return __timediff;
}
