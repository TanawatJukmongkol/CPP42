
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(const std::string& name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void init(unsigned int hp, unsigned int energy, unsigned int atk_dmg);

	private:
		std::string name;
		unsigned int hp;
		unsigned int energy;
		unsigned int atk_dmg;
};



