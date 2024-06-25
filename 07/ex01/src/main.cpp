#include "../include/iter.hpp"
#include <cstddef>
#include <iostream>

template<typename T>
void	functional_programming_go_brrrr(T something)
{
	std::cout << ": " << something << std::endl;
}

int main ()
{
	size_t		numbers_idk[3] = {4, 2, 0};
	std::string	strings_idk[5] = {"I", "<", "3", "4", "2"};

	::iter(numbers_idk, 3, functional_programming_go_brrrr);
	::iter(strings_idk, 5, functional_programming_go_brrrr);
	return 0;
}
