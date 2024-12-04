#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <climits>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe();

		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &assignment);

		template <typename T>
		void	sort(T &stack);

		size_t	getComps();
		size_t	getSwaps();
		size_t	getInserts();
		float	getTimeMs();

	protected:
		template <typename T>
		PmergeMe &mergeInsert(T &stack);
	
	private:
		size_t	__comps;
		size_t	__swaps;
		size_t	__inserts;
		float	__timediff;
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
void	print_int_stl(T &stl, size_t max_arg)
{
	for (typename T::iterator i = stl.begin(); i != stl.end(); ++i)
	{
		if (!max_arg--)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

// Splits big stack into 2 smaller stack, with the stack_in
// having the size of floor(N / 2) as described on the algorithm.
template <typename T>
void	stack_split(T &stack_in, T &stack_out)
{
	// dont split stack if pairless.
	if (stack_in.size() < 2)
		return ;
	size_t	half = stack_in.size() / 2;
	while (stack_in.size() > half)
	{
		stack_out.push_back(*stack_in.begin());
		stack_in.pop_front();
	}
}

// Swaps the pairs in-place the max value to the first stack.
// returns the No. of swaps. 0 if no swaping needed.
template <typename T>
size_t	stack_swap_max(T &stack1, T &stack2)
{
	typename T::iterator	s1begin = stack1.begin();
	typename T::iterator	s2begin = stack2.begin();
	typename T::iterator	s1end = stack1.end();
	int						tmp;
	size_t					swaps = 0;

	while (s1begin != s1end)
	{
		if (*s2begin > *s1begin)
		{
			// Swap pair
			tmp = *s1begin;
			*s1begin = *s2begin;
			*s2begin = tmp;
			swaps++;
		}
		s1begin++;
		s2begin++;
	}
	return swaps;
}

// Much like binary search, it searches the STL container within the search tree.
// Halfing the search space each iteration.
// returns No. of compares.
template <typename T>
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

template <typename T>
void	PmergeMe::sort(T &stack)
{
	__comps = 0;
	__swaps = 0;

	size_t	n1, n2;

	struct timespec res;
	clock_gettime(CLOCK_REALTIME,&res);
	n1 = res.tv_nsec;

	mergeInsert(stack);

	clock_gettime(CLOCK_REALTIME,&res);
	n2 = res.tv_nsec;

	__timediff = (n2 - n1) / 1000.f;
}

template <typename T>
PmergeMe	&PmergeMe::mergeInsert(T &stack)
{
	T		stack2;
	size_t	swaps;

	if (stack.size() < 2)
		return *this;

	::stack_split(stack, stack2);

	swaps = stack_swap_max(stack, stack2);
	__swaps = swaps;
	PmergeMe sorted = mergeInsert(stack);

	__swaps = 0;
	__inserts = 0;
	__comps += sorted.getComps();
	__swaps += sorted.getSwaps() + swaps;

	while (stack2.size())
	{
		__comps = ::binary_insert(stack, *stack2.begin());
		__inserts++;
		stack2.pop_front();
	}
	return *this;
}

#endif
