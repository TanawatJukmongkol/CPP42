#include "../include/C.hpp"
#include <iostream>

C::C()
{
	std::cout << "C created" << std::endl;
}

C::~C()
{
	std::cout << "C destroyed" << std::endl;
}

C::C(C const &copy)
{
	*this = copy;
}

C	&C::operator=(C const &assignment)
{
	(void)assignment;
	return *this;
}
