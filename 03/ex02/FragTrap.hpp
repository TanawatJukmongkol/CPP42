
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(const std::string &scname);
		~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys();
};

#endif