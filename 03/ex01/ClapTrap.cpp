/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanawat J. <66011255@kmitl.ac.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:21:02 by Tanawat J.        #+#    #+#             */
/*   Updated: 2023/11/28 15:02:38 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->hp = 10;
	this->energy = 10;
	this->atk_dmg = 0;
}

ClapTrap::ClapTrap(const std::string& trname)
{
	std::cout << "ClapTrap " << trname << " constructor called." << std::endl;
	this->name = trname;
	this->hp = 10;
	this->energy = 10;
	this->atk_dmg = 0;
};

ClapTrap::ClapTrap(const std::string& name, unsigned int hp, unsigned int energy, unsigned int atk_dmg)
{
	std::cout << "ClapTrap " << name << " constructor called." << std::endl;
	this->name = name;
	this->hp = hp;
	this->energy = energy;
	this->atk_dmg = atk_dmg;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called." << std::endl;
};

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap "
			  << name
			  << " clapped "
			  << target
			  << " with "
			  << atk_dmg
			  << " Newtons of force! ("
			  << energy
			  << "pt energy left)"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << name
				  << " iz ded. Okay?? Cannot beat a dead *ahem* ClapTrap." << std::endl;
		return ;
	}
	if (hp > amount)
		hp -= amount;
	else
		hp = 0;
	std::cout << name
			  << " got bonkaied with damage of "
			  << amount
			  << "! 痛い！("
			  << hp
			  << "HP left)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << name
				  << " iz ded. Okay?? Cannot be repaired!" << std::endl;
		return ;
	}
	if (energy == 0)
	{
		std::cout << name
				  << ": T^T. I'm out of energy. Cannot repair! ~Dori-me" << std::endl;
		return ;
	}
	hp += amount;
	energy--;
	std::cout << name
			  << " repaired thy owne health bi "
			  << amount
			  << " HP! ("
			  << hp
			  << " HP, "
			  << energy
			  << "pt energy left)" << std::endl;
}

