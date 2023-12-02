
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(const std::string &scname);
		~ScavTrap();
		void guardGate();
};

