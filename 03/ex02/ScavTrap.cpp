
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &scname): ClapTrap(scname)
{
	std::cout << "ScavTrap has been summoned!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap fell out of the world!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Gate keeping community activated. *lazer eyes*" << std::endl;
}

