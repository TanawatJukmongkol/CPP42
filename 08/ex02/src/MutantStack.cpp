#include "../include/MutantStack.hpp"
#include <iostream>

MutantStack::MutantStack()
{
	std::cout << "MutantStack created" << std::endl;
}

MutantStack::~MutantStack()
{
	std::cout << "MutantStack destroyed" << std::endl;
}

MutantStack::MutantStack(MutantStack const &copy)
{
	*this = copy;
}

MutantStack	&MutantStack::operator=(MutantStack const &assignment)
{
	return *this;
}
