
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &scname): ClapTrap(scname)
{
	std::cout << "FragTrap "
			  << scname
			  << " has been called!" << std::endl;
	init(100, 100, 30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap has skibidi bob dead dead!" << std::endl;
}

