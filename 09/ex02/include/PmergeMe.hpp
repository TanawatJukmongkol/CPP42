#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <climits>
#include <cstdlib>
#include <cstddef>
#include <iterator>
#include <iostream>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &assignment);

	// private:
	// 	size_t	_comps;
	// 	size_t	_swaps;
};

template <typename T>
void	fill_char_array_to_int_stl(T &stl, char **arr, size_t len)
{
	for (size_t i = 1; i < len + 1; ++i)
	{
		long numbr = std::strtol(arr[i], NULL, 10);
		if (numbr > INT_MAX || numbr < INT_MIN)
			return ; // Error sth...
		stl.push_back(numbr);
	}
}

template <typename T>
void	print_int_stl(T &stl)
{
	for (typename T::iterator i = stl.begin(); i != stl.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
}

template <typename T>
// Much like binary search, it searches the STL container within the search tree.
// Halfing the search space each iteration.
size_t	binary_insert(T &stl, int val)
{
	typename T::iterator	min = stl.begin();
	typename T::iterator	max = stl.end();
	typename T::iterator	mid;
	size_t					size = stl.size();
	size_t					compares = 0;

	while (size > 0)
	{
		size /= 2;
		mid = min;
		std::advance(mid, size);
		compares++;
		if (val >= *mid)
		{
			min = mid;
			std::advance(min, 1);
		}
		else
			max = mid;
	}
	stl.insert(max, val);
	return compares;
}

#endif
