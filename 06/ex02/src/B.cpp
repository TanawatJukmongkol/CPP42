#include "../include/B.hpp"
#include <iostream>

B::B()
{
	std::cout << "B created" << std::endl;
}

B::~B()
{
	std::cout << "B destroyed" << std::endl;
}

B::B(B const &copy)
{
	*this = copy;
}

B	&B::operator=(B const &assignment)
{
	(void)assignment;
	return *this;
}
