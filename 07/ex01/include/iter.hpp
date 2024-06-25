#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename T>

void iter (T* array, std::size_t length, void fn(T))
{
	for (size_t i = 0; i < length; i++)
		fn(array[i]);
}

#endif
