#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int find)
{
	if (container.size() == 0)
		throw std::runtime_error("Cannot find in an empty container.");
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
	{
		if (*i == find)
			return i;
	}
	throw std::runtime_error("Cannot find in container.");
}

#endif
