#include "../include/A.hpp"
#include <iostream>

A::A()
{
	std::cout << "A created" << std::endl;
}

A::~A()
{
	std::cout << "A destroyed" << std::endl;
}

A::A(A const &copy)
{
	*this = copy;
}

A	&A::operator=(A const &assignment)
{
	(void)assignment;
	return *this;
}
