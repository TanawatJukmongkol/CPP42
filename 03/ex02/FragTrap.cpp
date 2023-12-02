
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &scname): ClapTrap(scname, 100, 100, 30)
{
	std::cout << "FragTrap emerges!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " skibidi dead dead!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hp == 0)
	{
		std::cout << name
				  << " iz ded. Okay?? Cannot attack." << std::endl;
		return ;
	}
	if (energy == 0)
	{
		std::cout << name
				  << ": Beep boop. I'm out of energy." << std::endl;
		return ;
	}
	energy--;
	std::cout << "FragTrap "
			  << name
			  << " slapped "
			  << target
			  << " with "
			  << atk_dmg
			  << " Newtons of force! ("
			  << energy
			  << "pt energy left)"<< std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "High five!" << std::endl;
}
