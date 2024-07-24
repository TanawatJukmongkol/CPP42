
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &scname): ClapTrap(scname, 100, 50, 20)
{
	std::cout << "ScavTrap has been summoned!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap fell out of the world!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
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
	std::cout << "ScavTrap "
			  << name
			  << " slapped "
			  << target
			  << " with "
			  << atk_dmg
			  << " Newtons of force! ("
			  << energy
			  << "pt energy left)"<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Gate keeping community activated. *lazer eyes*" << std::endl;
}
